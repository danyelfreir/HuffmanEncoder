#pragma once
#include "Node.h"

class FSNode : public Node {
   public:
    FSNode *left;
    FSNode *right;
    FSNode(char value);
    void incrementFreq();
};