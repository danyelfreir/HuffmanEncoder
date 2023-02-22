#pragma once
#include <iostream>
#include "../include/PQNode.h"

class PriorityQueue {
private:
    PQNode *head;
    int _length;
public:
    PriorityQueue();
    void push(PQNode *newNode);
    int getHeadFreq();
    char pop();
    void print();
    int length();
};