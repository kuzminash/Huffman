cmake_minimum_required(VERSION 3.10)
project(hw_03)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

include_directories(test)

add_executable(hw_03 src/main.cpp src/Tree.cpp src/Huffman.cpp src/HuffmanException.cpp
        include/Huffman.h include/HuffmanException.h include/Tree.h)
add_executable(hw_03_test test/autotest.cpp test/autotest.h test/test.cpp test/Huffman_test.cpp
        test/Huffman_test.h src/Tree.cpp src/Huffman.cpp src/HuffmanException.cpp
        include/Huffman.h include/HuffmanException.h include/Tree.h)

