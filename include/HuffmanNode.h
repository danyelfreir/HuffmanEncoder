#pragma once
#include "Node.h"

class HuffmanNode : public Node {
   public:
    HuffmanNode(int frequency, Node *left, Node *right);
};