#include <iostream>
#include <fstream>
#include <ostream>
#include <climits>
#include <tuple>
#include "Huffman.h"
#include "HuffmanException.h"
#include "Tree.h"

namespace my_Huffman {

    Huffman::Huffman(const char *in_file, const char *out_file) : input_file{in_file, std::ifstream::binary},
                                                                  output_file{out_file, std::ostream::binary} {
        if (!input_file.is_open()) {
            throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::FOPIN);
        }
        if (!output_file.is_open()) {
            throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::FOPOUT);
        }
    }

    void Huffman::CountFreq() {
        unsigned char symbol;
        input_file.read((char *) &symbol, sizeof(char));
        if ((input_file.fail() || input_file.bad()) && !input_file.eof()) {
            throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::READ);
        }
        while (!input_file.eof()) {
            frequency[(int) symbol]++;
            input_file.read((char *) &symbol, sizeof(char));

            if ((input_file.fail() || input_file.bad()) && !input_file.eof()) {
                throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::READ);
            }
        }}

    void Huffman::WriteTable() {
        output_file.write(reinterpret_cast<char *>(&(frequency[0])), sizeof(std::size_t) * my_Tree::ELEMENTS);
        if (output_file.fail() || output_file.bad()) {
            throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::WRITE);
        }
    }

    void Huffman::WriteToFile(my_Tree::HuffmanTree &Tree) {
        input_file.clear();
        input_file.seekg(0);
        WriteTable();
        int count = 0;
        unsigned char buffer = 0;
        while (!input_file.eof()) {
            char c = input_file.get();
            if ((input_file.fail() || input_file.bad()) && !input_file.eof()) {
                throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::READ);
            }
            std::vector<bool> x = Tree.table[c];
            for (std::size_t i = 0; i < x.size(); i++) {
                buffer = buffer | x[i] << ((CHAR_BIT - 1) - count);
                count++;
                if (count == CHAR_BIT) {
                    count = 0;
                    output_file << buffer;
                    if (output_file.fail() || output_file.bad()) {
                        throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::WRITE);
                    }
                    buffer = 0;
                }
            }
        }
        if (buffer != 0) {
            output_file << buffer;
            if (output_file.fail() || output_file.bad()) {
                throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::WRITE);
            }
        }
    }

    void Huffman::CleanFiles() {
        input_file.clear();
        input_file.seekg(0, std::ifstream::end);
        output_file.clear();
        output_file.seekp(0, std::iostream::end);
    }

    std::tuple<size_t, size_t, size_t> Huffman::Statistics() {
        return std::make_tuple(input_file.tellg(), output_file.tellp(), my_Tree::ELEMENTS * sizeof(std::size_t));
    }

    void Huffman::Compress() {
        CountFreq();
        my_Tree::HuffmanTree Tree(frequency);
        Tree.BuildNewCodes(Tree.get_root());
        WriteToFile(Tree);
        CleanFiles();
    }

    void Huffman::ReadFreq() {
        input_file.read(reinterpret_cast<char *>(&(frequency[0])), sizeof(std::size_t) * my_Tree::ELEMENTS);
        if (input_file.fail() || input_file.bad()) {
            throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::READ);
        }
    }

    void Huffman::ReadBits(my_Tree::HuffmanTree &Tree) {
        my_Tree::HuffmanTree::Node *p = Tree.get_root();
        for (int i = 0; i < my_Tree::ELEMENTS; i++) {
            quant += frequency[i];
        }
        int count = 0;
        char byte;
        byte = input_file.get();
        if ((input_file.fail() || input_file.bad()) && !input_file.eof()) {
            throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::READ);
        }
        while (!input_file.eof() && quant != 0) {
            bool b = byte & (1 << ((CHAR_BIT - 1) - count));
            if (b) p = p->right;
            else p = p->left;
            if (p->left == nullptr && p->right == nullptr) {
                output_file << p->symbol;
                if (output_file.fail() || output_file.bad()) {
                    throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::WRITE);
                }
                quant--;
                p = Tree.get_root();
            }
            count++;
            if (count == CHAR_BIT) {
                count = 0;
                byte = input_file.get();
                if ((input_file.fail() || input_file.bad()) && !input_file.eof()) {
                    throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::READ);
                }
            }
        }
    }

    void Huffman::Decompress() {
        ReadFreq();
        my_Tree::HuffmanTree Tree(frequency);
        Tree.BuildNewCodes(Tree.get_root());
        ReadBits(Tree);
        CleanFiles();
    }

}