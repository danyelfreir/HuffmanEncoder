#pragma once
#include "Node.h"

class PQNode : public Node {
   public:
    PQNode(char value, int frequency);
    PQNode *next;
};