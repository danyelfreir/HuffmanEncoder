#include "../include/HCNode.h"

HCNode::HCNode(Node* left, Node* right) : Node(left->frequency + right->frequency) {
    this->left = left;
    this->right = right;
}
