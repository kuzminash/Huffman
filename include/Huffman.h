#ifndef HUFFMAN_NEW_HUFFMAN_H
#define HUFFMAN_NEW_HUFFMAN_H

#include <iostream>
#include <vector>
#include <fstream>
#include "Tree.h"

namespace my_Huffman {
    class Huffman {
    public:
        Huffman(const char *input_file, const char *output_file);

        void Compress();

        void Decompress();

        void Statistics();

    private:
        void CountFreq();

        void WriteTable();

        void WriteToFile(my_Tree::HuffmanTree &Tree);

        void ReadFreq();

        void ReadBits(my_Tree::HuffmanTree &Tree);

        void CleanFiles();

        std::size_t quant = 0;
        std::size_t frequency[my_Tree::ELEMENTS] = {0};
        std::ifstream input_file;
        std::ofstream output_file;
    };

}

#endif //HUFFMAN_NEW_HUFFMAN_H