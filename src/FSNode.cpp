#include "../include/FSNode.h"

FSNode::FSNode(char value) : Node(value, 1) {
    this->left = nullptr;
    this->right = nullptr;
}

void FSNode::incrementFreq() { this->_frequency++; }
