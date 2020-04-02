#ifndef HW_03_HUFFMAN_TEST_H
#define HW_03_HUFFMAN_TEST_H

#include "autotest.h"
#include "Tree.h"
#include <fstream>

namespace my_huffman {

    class HuffmanTest final : public my_base_autotest_class::AutoTest {
    public:
        HuffmanTest();

        void RunAllTests() override;

    private:
        static void CreateCompressFile(const char *first, const char *second);

        static void CreateDecompressFile(const char *first, const char *second);

        bool FirstFile();

        bool SecondFile();

        bool ThirdFile();

        bool CountFreq();

        bool CheckTree();

        bool DFS(my_huffman::HuffmanTree::Node *node);

        bool Statistics();

        bool CheckCodes();

        bool pass;
    };

}

#endif //HW_03_HUFFMAN_TEST_H
