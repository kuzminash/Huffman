#include <iostream>
#include<tuple>
#include "Huffman_test.h"
#include "Tree.h"
#include "Huffman.h"

namespace my_huffman_tests {
    HuffmanTest::HuffmanTest() : AutoTest() {
    }

    void HuffmanTest::RunAllTests() {
        /*if (!FirstFile()) {
            std::cout << "Failed on empty file\n";
        } else Passed++;
        */if (!SecondFile()) {
            std::cout << "Failed on one symbol file\n";
        } else Passed++;
        if (!ThirdFile()) {
            std::cout << "Failed om random file\n";
        } else Passed++;
        if (!CountFreq()) {
            std::cout << "Program couldn't count symbols frequency properly\n";
        } else Passed++;
        /*if (!CheckTree()) {
            std::cout << "Program couldn't properly create tree\n";
        } else Passed++;
        */if(!Statistics()) {
            std::cout << "Statistics method doesn't count properly\n";
        } else Passed++;
    }

    void HuffmanTest::CreateFile(const char *first, const char *second, const char *third) {
        my_Huffman::Huffman h1(first, second);
        h1.Compress();
        my_Huffman::Huffman h2(second, third);
        h2.Decompress();
    }

    bool HuffmanTest::FirstFile() {
        CreateFile("../test_files/empty.txt", "../test_files/empty.bin", "../test_files/empty_test.txt");
        return CheckIfSimilar("../test_files/empty.txt", "../test_files/empty_test.txt");
    }

    bool HuffmanTest::SecondFile() {
        CreateFile("../test_files/one_symbol.txt", "../test_files/one_symbol.bin", "../test_files/one_symbol_test.txt");
        return CheckIfSimilar("../test_files/one_symbol.txt", "../test_files/one_symbol_test.txt");
    }

    bool HuffmanTest::ThirdFile() {
        CreateFile("../test_files/tests.txt", "../test_files/tests.bin",
                   "../test_files/tests_test.txt");
        return CheckIfSimilar("../test_files/tests.txt", "../test_files/tests_test.txt");
    }

    bool HuffmanTest::DFS(my_Tree::HuffmanTree::Node &node) {
        if (node.left != nullptr && node.right != nullptr) {
            if (node.freq == (node.left->freq + node.right->freq)) {
                passed = DFS(*node.left);
                passed = DFS(*node.right);
            } else return false;
        } else if (node.left != nullptr) {
            if (node.freq == node.left->freq) {
                passed = DFS(*node.left);
            } else return false;
        } else if (node.right != nullptr) {
            if (node.freq == node.right->freq) {
                passed = DFS(*node.right);
            } else return false;
        }
        return passed;
    }

    bool HuffmanTest::CheckTree() {
        my_Huffman::Huffman h3("../test_files/tests.txt", "../test_files/lala.bin");
        h3.CountFreq();
        my_Tree::HuffmanTree Tree(h3.frequency);
        passed = true;
        return DFS(*Tree.get_root());
    }


    bool HuffmanTest::CountFreq() {
        my_Huffman::Huffman h4("../test_files/one_symbol.txt", "../test_files/lala.bin");
        h4.CountFreq();
        return h4.frequency[97] == 1;
    }

    bool HuffmanTest::Statistics() {
        my_Huffman::Huffman h5("../test_files/one_symbol.txt", "../test_files/one_symbol.bin");
        h5.CleanFiles();
        auto statistics = h5.Statistics();
        std::cout << std::get<0>(statistics) << '\n'
                  << std::get<1>(statistics) << '\n'
                  << std::get<2>(statistics) << '\n';

        return std::get<0>(statistics) == 1 &&
               std::get<1>(statistics) == 2049 &&
               std::get<2>(statistics) == 2048;
    }

}