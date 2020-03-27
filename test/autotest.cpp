#include <iostream>
#include <fstream>
#include <ostream>
#include "autotest.h"

namespace my_base_autotest_class {
    AutoTest::AutoTest() : Passed{0} {
    }

    void AutoTest::Result() {
        std::cout << "In total program passed " << Passed << " tests\n";
    }

    bool AutoTest::CheckIfSimilar(const char *first, const char *second) {
        std::ifstream file1, file2;
        file1.open(first), file2.open(second);
        while (!file1.eof()) {
            if (file1.get() != file2.get()) return false;
        }
        return file2.eof();
    }
}