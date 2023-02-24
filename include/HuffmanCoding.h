#pragma once
#include <iostream>

#include "HCNode.h"
#include "PriorityQueue.h"

class HuffmanCoding {
   private:
    HCNode *queueHead;
    int _size;
    void push(char value, int frequency);
    void push(HCNode *newNode);
    HCNode *pop();
    void print(HCNode *root, char *string, int level);

    public:
    HuffmanCoding();
    HCNode *getHead();
    void populate(PriorityQueue *queue);
    void encode();
    void decode();
    void print();
};
