#ifndef HW_03_HUFFMAN_TEST_H
#define HW_03_HUFFMAN_TEST_H

#include "autotest.h"
#include <fstream>

namespace my_huffman_tests {
    enum {
        PASSED,
        FAILED
    };

    class HuffmanTest final : public my_base_autotest_class::AutoTest {
    public:
        HuffmanTest();

        void RunAllTests() override;

    protected:
        void CreateFile(const char* first, const char* second, const char* third);

        bool FirstFile();

        bool SecondFile();

        bool ThirdFile();

        bool FourthFile();
    };

}

#endif //HW_03_HUFFMAN_TEST_H
