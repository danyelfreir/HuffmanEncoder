#pragma once
#include "../include/HCNode.h"

class HCLeaf : public HCNode {
public:
    char value;
    HCLeaf(char value, int frequency);
};