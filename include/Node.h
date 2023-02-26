#pragma once

class Node {
protected:
    int _frequency;
    bool _isLeafNode;

public:
    Node(int frequency, bool isLeafNode, Node *left, Node *right);
    Node *left, *right;
    int frequency();
    bool isLeafNode();
    bool operator<(Node *that);
};