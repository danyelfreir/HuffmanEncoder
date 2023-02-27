#pragma once

class Node {
   protected:
    unsigned int _frequency;
    bool _isLeafNode;

   public:
    Node(int frequency, bool isLeafNode, Node *left, Node *right);
    Node *left, *right;
    unsigned int frequency();
    bool isLeafNode();
    bool operator<(Node *that);
};