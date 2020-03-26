cmake_minimum_required(VERSION 3.15)
project(hw_03)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(hw_03 src/main.cpp src/Tree.cpp src/Huffman.cpp src/HuffmanException.cpp
                            include/Huffman.h include/HuffmanException.h include/Tree.h)