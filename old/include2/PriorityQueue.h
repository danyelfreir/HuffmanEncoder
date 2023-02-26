#pragma once
#include <iostream>

#include "PQNode.h"

class PriorityQueue {
   private:
    int _length;

   public:
    PQNode *head;
    PriorityQueue();
    ~PriorityQueue();
    void push(char value, int frequency);
    PQNode *pop();
    int length();
    void print();
};