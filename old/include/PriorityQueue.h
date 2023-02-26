#pragma once
#include <iostream>
#include "PQNode.h"
#include "HCNode.h"

class PriorityQueue {
private:
    Node *head;
    int _length;
    void print(Node *root, char *string, int level);
public:
    PriorityQueue();
    void push(Node *newNode);
    int getHeadFreq();
    Node *pop();
    int length();
    void encode();
    void print();
};