#include <iostream>
#include <string.h>
#include <string>
#include <memory>
#include "Huffman.h"
#include "HuffmanException.h"

using namespace std;

int main(int argc, char **argv) {
    try {

        const char *input_file = nullptr;
        const char *output_file = nullptr;

        if (argv[1][1] == 'c') {
            if (!strcmp(argv[2], "-f") || !strcmp(argv[2], "--file")) {
                input_file = argv[3];
            }
            else if (!strcmp(argv[4], "-f") || !strcmp(argv[4], "--file")) {
                input_file = argv[5];
            }
            if (!strcmp(argv[2], "-o") || !strcmp(argv[2], "--output")){
                output_file = argv[3];
            }
            else if (!strcmp(argv[4], "-o") || !strcmp(argv[4], "--output")) {
                output_file = argv[5];
            }
            my_Huffman::Huffman h(input_file, output_file);
            h.Compress();

        }
        else if (argv[1][1] == 'u') {
            if (!strcmp(argv[2], "-f") || !strcmp(argv[2], "--file")) {
                input_file = argv[3];
            }
            else if (!strcmp(argv[4], "-f") || !strcmp(argv[4], "--file")) {
                input_file = argv[5];
            }
            if (!strcmp(argv[2], "-o") || !strcmp(argv[2], "--output")){
                output_file = argv[3];
            }
            else if (!strcmp(argv[4], "-o") || !strcmp(argv[4], "--output")) {
                output_file = argv[5];
            }

            std::unique_ptr<my_Huffman::Huffman> h1(new my_Huffman::Huffman(input_file, output_file));
            my_Huffman::Huffman h(input_file, output_file);
            h.Decompress();
        }
        else {
            throw my_exception::HuffmanException(my_exception::HuffmanException::Exception_type::ARG);
        }
    }
    catch (const std::bad_alloc &excep) {
        std::cout << "Unable to allocate memory." << '\n';
    }
    catch (const std::exception &excep) {
        std::cout << excep.what() << '\n';
    }
    catch (...) {
        std::cout << "Unknown error" << '\n';
    }

}