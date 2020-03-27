#ifndef HW_03_AUTOTEST_H
#define HW_03_AUTOTEST_H

#include <iostream>
#include <cstring>
#include <fstream>

namespace my_base_autotest_class {

    class AutoTest {
    public:
        AutoTest();

        virtual int RunTests() = 0;

        void Result();
    protected:
        bool CheckIfSimilar(const char *first, const char *second);

        int Passed;
    };

}

#endif //HW_03_AUTOTEST_H
