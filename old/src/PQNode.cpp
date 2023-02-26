#include "../include/PQNode.h"

PQNode::PQNode(char value, int frequency) : Node(frequency) {
    this->value = value;
}