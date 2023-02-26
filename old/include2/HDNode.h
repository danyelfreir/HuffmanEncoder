#pragma once
#include <string.h>

class HDNode {
public:
    HDNode(char value, int bitStringLen, int bitString);
    char value;
    int bitStringLen;
    int bitString;
    HDNode *left, *right;
    bool operator<(HDNode *that);
    bool operator>(HDNode *that);
};