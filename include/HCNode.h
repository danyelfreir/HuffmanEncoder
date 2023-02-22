#pragma once

class HCNode {
public:
    int frequency;
    HCNode *left, *right;
    HCNode(int frequency);
    bool operator < (HCNode *that);
};