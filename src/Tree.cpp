#include <iostream>
#include <vector>
#include <queue>
#include "Tree.h"

namespace my_huffman {

    void HuffmanTree::PlaceNode(std::size_t(&frequency)[ELEMENTS]) {
        for (int i = 0; i < ELEMENTS; i++) {
            if (frequency[i] > 0) {
                std::shared_ptr<Node> p(new Node((char) i, frequency[i], nullptr, nullptr));
                node_vector.push_back(p);
            }
        }
    }

    void HuffmanTree::CollapseTree() {
        std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, Node::Comparator> Q1;
        for (auto p:node_vector) {
            Q1.push(p);
        }
        while (Q1.size() < 2) {
            std::shared_ptr<Node> new_node(new Node(' ', INT32_MAX, nullptr, nullptr));
            Q1.push(new_node);
        }
        std::size_t tree_size = Q1.size();
        std::shared_ptr<Node> first = nullptr, second = nullptr;
        for (std::size_t i = tree_size; i < 2 * tree_size - 1; i++) {
            first = Q1.top(), Q1.pop();
            second = Q1.top(), Q1.pop();
            std::shared_ptr<Node> new_node(new Node(' ', first->freq + second->freq, second, first));
            Q1.push(new_node);
        }
        root = Q1.top(), Q1.pop();
    }

    void HuffmanTree::BuildNewCodes(std::shared_ptr<Node> root) {
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

    std::shared_ptr<HuffmanTree::Node> HuffmanTree::get_root() {
        return root;
    }

    bool HuffmanTree::Node::Comparator::operator()(std::shared_ptr<Node> first, std::shared_ptr<Node> second) {
        return first->freq > second->freq;
    }

    HuffmanTree::Node::Node(char symbol, std::size_t freq, std::shared_ptr<Node> left, std::shared_ptr<Node> right) :
                                                        symbol{symbol}, freq{freq}, left{left}, right{right} {

    }
}