#pragma once
#include "Node.h"

class PQNode : public Node {
public:
    char value;
    PQNode(char value, int frequency);
};