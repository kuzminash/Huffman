#include <iostream>
#include <string>
#include <memory>
#include "Huffman.h"
#include "HuffmanException.h"

using namespace std;

int main(int argc, char **argv) {
    try {

        const char *input_file = nullptr;
        const char *output_file = nullptr;

        if (string(argv[1]) == "-c") {
            if ((string(argv[2]) == "-f" || string(argv[2]) == "--file") &&
                (string(argv[4]) == "-o" || string(argv[4]) == "--output")) {
                input_file = argv[3];
                output_file = argv[5];
                my_Huffman::Huffman h(input_file, output_file);
                h.Compress();
            }
        } else if (string(argv[1]) == "-u") {
            if ((string(argv[2]) == "-f" || string(argv[2]) == "--file") &&
                (string(argv[4]) == "-o" || string(argv[4]) == "--output")) {
                input_file = argv[3];
                output_file = argv[5];
                my_Huffman::Huffman h(input_file, output_file);
                h.Decompress();
            }
        } else {
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
    /*
    ofstream file;
    file.open("l.txt");
    for(int i = 0; i < 5000000; i++) {
        file << 'a';
    }
    file.close();
    */
}