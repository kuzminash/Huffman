#include <iostream>
#include "Huffman_test.h"
#include "Huffman.h"

namespace my_huffman_tests {
    HuffmanTest::HuffmanTest() : AutoTest() {
    }

    void HuffmanTest::RunAllTests() {
        if (!FirstFile()) {
            std::cout << "Failed on empty file\n";
        } else Passed++;
        if (!SecondFile()) {
            std::cout << "Failed on one symbol file\n";
        } else Passed++;
        if (!ThirdFile()) {
            std::cout << "Failed om War and Peace\n";
        } else Passed++;
        if (!FourthFile()) {
            std::cout << "Failed on 5000000 same symbols file\n";
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
        CreateFile("../test_files/war_and_peace.txt", "../test_files/war_and_peace.bin",
                   "../test_files/war_and_peace_test.txt");
        return CheckIfSimilar("../test_files/war_and_peace.txt", "../test_files/war_and_peace_test.txt");
    }

    bool HuffmanTest::FourthFile() {
        CreateFile("../test_files/5000000_same_symbols.txt", "../test_files/5000000_same_symbols.bin",
                   "../test_files/5000000_same_symbols_test.txt");
        return CheckIfSimilar("../test_files/5000000_same_symbols.txt", "../test_files/5000000_same_symbols_test.txt");
    }

}