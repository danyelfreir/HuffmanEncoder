#include "../include/PQNode.h"

PQNode::PQNode(char value, int frequency) {
    this->value = value;
    this->frequency = frequency;
    this->next = nullptr;
}