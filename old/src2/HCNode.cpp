#include "../include/HCNode.h"

HCNode::HCNode(char value, int frequency, HCNode *left, HCNode *right) : Node(value, frequency) {
    this->next = nullptr;
    this->left = left;
    this->right = right;
}