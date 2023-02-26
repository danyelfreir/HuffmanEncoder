#pragma once
#include <iostream>

class Node {
public:
    int frequency;
    char value;
    Node *next, *left, *right;
    Node(int frequency);
    bool operator < (Node *that);
};