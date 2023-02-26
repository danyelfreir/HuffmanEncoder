#include "../include/Node.h"

Node::Node(int frequency) {
    this->frequency = frequency;
    this->value = 0;
    this->next = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

bool Node::operator < (Node *that) {
    return this->frequency < that->frequency;
}