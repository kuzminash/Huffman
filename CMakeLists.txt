cmake_minimum_required(VERSION 3.15)
project(Huffman)

set(CMAKE_CXX_STANDARD 14)

add_executable(Huffman main.cpp Tree.cpp Huffman.cpp HuffmanException.cpp Huffman.h HuffmanException.h Tree.h)