#ifndef HUFFMAN_NEW_HUFFMAN_H
#define HUFFMAN_NEW_HUFFMAN_H

#include <iostream>
#include <vector>
#include <fstream>
#include <Huffman_test.h>
#include "Tree.h"

namespace my_huffman {
    class Huffman {
    public:
        Huffman(const char *input_file, const char *output_file);

        void Compress();

        void Decompress();

        std::tuple<size_t, size_t, size_t> Statistics();

        friend class my_huffman::HuffmanTest;
    private:
        void CountFreq();

        void WriteTable();

        void WriteToFile(my_huffman::HuffmanTree &Tree);

        void WriteBitsWork(unsigned char &buffer, int &count, std::vector<bool> &x);

        void WriteBits(my_huffman::HuffmanTree &Tree);

        void ReadFreq();

        void ReadBitsWork(my_huffman::HuffmanTree &Tree);

        void ReadBits(my_huffman::HuffmanTree &Tree);

        void CleanFiles();

        std::size_t quant = 0;
        std::size_t frequency[my_huffman::ELEMENTS] = {0};
        std::ifstream input_file;
        std::ofstream output_file;
    };

}

#endif //HUFFMAN_NEW_HUFFMAN_H