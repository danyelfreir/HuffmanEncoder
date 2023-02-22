#pragma once

class FSNode {
public:
    char value;
    int frequency;
    FSNode *left;
    FSNode *right;
    FSNode(char value);
};