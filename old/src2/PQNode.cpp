#include "../include/PQNode.h"

PQNode::PQNode(char value, int frequency) : Node(value, frequency) { this->next = nullptr; }
