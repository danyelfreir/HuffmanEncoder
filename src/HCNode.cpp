#include "../include/HCNode.h"

HCNode::HCNode(int frequency) {
    this->frequency = frequency;
    this->left = nullptr;
    this->right = nullptr;
}

bool HCNode::operator < (HCNode *that) {
    return this->frequency < that->frequency;
}