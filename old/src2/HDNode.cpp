#include "../include/HDNode.h"

HDNode::HDNode(char value, int bitStringLen, int bitString) {
    this->value = value;
    this->bitString = bitString;
    this->bitStringLen = bitStringLen;    
    this->left = nullptr;
    this->right = nullptr;
}

bool HDNode::operator<(HDNode *that) {
    return this->bitString < that->bitString;
}

bool HDNode::operator>(HDNode *that) {
    return this->bitString > that->bitString;
}