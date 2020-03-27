#include <iostream>
#include <vector>
#include <queue>
#include "Tree.h"

namespace my_Tree {

    void HuffmanTree::PlaceNode(std::size_t(&frequency)[ELEMENTS]) {
        for (int i = 0; i < ELEMENTS; i++) {
            if (frequency[i] > 0) {
                try {
                    Node *p = new Node((char) i, frequency[i], nullptr, nullptr);
                    node_vector.push_back(p);
                }
                catch (const std::bad_alloc &excep) {
                    for (auto i = node_vector.begin(); i != node_vector.end(); i++) {
                        auto help = i;
                        delete *help;
                        throw excep;
                    }
                }
            }
        }
    }

    HuffmanTree::Node::~Node() {
        delete left;
        delete right;
    }

    HuffmanTree::~HuffmanTree() {
        delete root;
    }

    void HuffmanTree::CollapseTree() {
        std::priority_queue<Node *, std::vector<Node *>, Node::Comparator> Q1;
        for (auto p:node_vector) {
            Q1.push(p);
        }
        while (Q1.size() < 2) {
            Node *new_node = new Node(' ', INT32_MAX, nullptr, nullptr);
            Q1.push(new_node);
        }
        std::size_t tree_size = Q1.size();
        Node *first = nullptr, *second = nullptr;
        for (std::size_t i = tree_size; i < 2 * tree_size - 1; i++) {
            first = Q1.top(), Q1.pop();
            second = Q1.top(), Q1.pop();
            Node *new_node = new Node(' ', first->freq + second->freq, second, first);
            Q1.push(new_node);
        }
        root = Q1.top(), Q1.pop();
    }

    void HuffmanTree::BuildNewCodes(Node *root) {
        if (!root) {
            return;
        }
        if (root->left) {
            code.push_back(0);
            BuildNewCodes(root->left);
        }
        if (root->right) {
            code.push_back(1);
            BuildNewCodes(root->right);
        }
        if (!root->left && !root->right) {
            table[root->symbol] = code;
        }
        code.pop_back();
    }

    HuffmanTree::HuffmanTree(std::size_t(&frequency)[ELEMENTS]) : root{nullptr} {
        PlaceNode(frequency);
        CollapseTree();
    }

    HuffmanTree::Node *HuffmanTree::get_root() {
        return root;
    }

    HuffmanTree::Node::Node(char symbol, std::size_t freq, HuffmanTree::Node *left, HuffmanTree::Node *right) :
                                                            symbol{symbol}, freq{freq}, left{left}, right{right} {
    }

    bool HuffmanTree::Node::Comparator::operator()(const HuffmanTree::Node *first, const HuffmanTree::Node *second) {
        return first->freq > second->freq;
    }

}