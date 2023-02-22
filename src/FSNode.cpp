#include "../include/FSNode.h"

FSNode::FSNode(char value) {
    this->value = value;
    this->frequency = 1;
    this->left = nullptr;
    this->right = nullptr;
}
