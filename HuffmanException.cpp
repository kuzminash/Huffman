#include <iostream>
#include "HuffmanException.h"

namespace my_exception {

    HuffmanException::HuffmanException(HuffmanException::Exception_type type) noexcept : type{type} {
    }

    const char *HuffmanException::what() const noexcept {
        switch (type) {
            case Exception_type::FOPIN:
                return "LOAD: unable to open input file.";
            case Exception_type::FOPOUT:
                return "LOAD: unable to open output file.";
            case Exception_type::READ:
                return "LOAD: invalid file format.";
            case Exception_type::WRITE:
                return "WRITE: unable to write data";
            case Exception_type::ARG:
                return "INVALID common-line arguments";
            default:
                return "Unknown error";
        }
    }

}