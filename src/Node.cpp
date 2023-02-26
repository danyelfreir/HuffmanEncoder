#include "../include/Node.h"

Node::Node(int frequency, bool isLeafNode, Node* left, Node *right) {
    this->_frequency = frequency;
    this->_isLeafNode = isLeafNode;
    this->left = left;
    this->right = right;
}

int Node::frequency() {
    return this->_frequency;
}

bool Node::isLeafNode() {
    return this->_isLeafNode;
}

bool Node::operator<(Node *that) {
    return this->_frequency < that->frequency();
}