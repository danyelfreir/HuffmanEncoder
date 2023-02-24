#pragma once
#include "Node.h"

class HCNode : public Node {
   public:
    HCNode(char value, int frequency, HCNode *left, HCNode *right);
    HCNode *next, *left, *right;
};