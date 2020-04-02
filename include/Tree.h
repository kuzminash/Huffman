#ifndef HUFFMAN_NEW_TREE_H
#define HUFFMAN_NEW_TREE_H

#include <vector>
#include <unordered_map>
#include <climits>
#include <memory>

namespace my_huffman {

    enum {
        ELEMENTS = 1 << CHAR_BIT
    };

    class HuffmanTree {
    public:
        class Node {
        public:
            Node(char symbol, std::size_t freq, std::shared_ptr<Node> left, std::shared_ptr<Node> right);

            class Comparator {
            public:
                bool operator()(std::shared_ptr<Node> first, std::shared_ptr<Node> second);
            };

            char symbol;
            std::size_t freq;
            std::shared_ptr<Node> left;
            std::shared_ptr<Node> right;
        };

        explicit HuffmanTree(std::size_t(&frequency)[ELEMENTS]);

        void PlaceNode(std::size_t(&frequency)[ELEMENTS]);

        void CollapseTree();

        void BuildNewCodes(std::shared_ptr<Node> root);

        std::shared_ptr<Node> get_root();

        std::unordered_map<char, std::vector<bool>> table;
        std::vector<std::shared_ptr<Node>> node_vector;
    private:
        std::shared_ptr<Node> root;
        std::vector<bool> code;
    };

}


#endif //HUFFMAN_NEW_TREE_H