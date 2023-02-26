#include "../include/HuffmanNode.h"

HuffmanNode::HuffmanNode(int frequency, Node *left, Node *right) : Node(frequency, false, left, right) {
    this->_frequency = frequency;
}
