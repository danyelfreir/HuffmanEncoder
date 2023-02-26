#include "../include/HuffmanLeaf.h"

HuffmanLeaf::HuffmanLeaf(int frequency, char value) : Node(frequency, true, nullptr, nullptr) {
    this->_value = value;
}

char HuffmanLeaf::value() { return this->_value; }