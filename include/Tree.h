#ifndef HUFFMAN_NEW_TREE_H
#define HUFFMAN_NEW_TREE_H

#include <vector>
#include <unordered_map>

namespace my_Tree {

    enum {
        ELEMENTS = 256
    };

    class HuffmanTree {
    public:
        class Node {
        public:
            Node(char symbol, std::size_t freq, Node *left, Node *right);

            ~Node();

            class Comparator {
            public:
                bool operator()(const Node *first, const Node *second);
            };

            char symbol;
            std::size_t freq;
            Node *left, *right;
        };

        explicit HuffmanTree(std::size_t(&frequency)[ELEMENTS]);

        ~HuffmanTree();

        void PlaceNode(std::size_t(&frequency)[ELEMENTS]);

        void CollapseTree();

        void BuildNewCodes(Node *root);

        Node *get_root();

        std::unordered_map<char, std::vector<bool>> table;
        std::vector<Node *> node_vector;
    private:
        Node *root;
    };

}


#endif //HUFFMAN_NEW_TREE_H