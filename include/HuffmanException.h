#ifndef HUFFMAN_HUFFMANEXCEPTION_H
#define HUFFMAN_HUFFMANEXCEPTION_H

#include <iostream>

namespace my_huffman {

    class HuffmanException final : public std::exception {
    public:
        enum Exception_type {
            ARG,
            FOPIN,
            FOPOUT,
            WRITE,
            READ,
        };

        explicit HuffmanException(Exception_type type) noexcept;

        const char *what() const noexcept override;

    private:

        Exception_type type;
    };

}

#endif //HUFFMAN_HUFFMANEXCEPTION_H
