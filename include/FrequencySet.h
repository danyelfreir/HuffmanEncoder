#pragma once
#include <iostream>

#include "FSNode.h"
#include "PriorityQueue.h"

class FrequencySet {
   private:
    FSNode *head;
    int size;
    void deleteNodes(FSNode *root);
    FSNode *add(FSNode *root, char value);
    void addToQueue(FSNode *root, PriorityQueue *queue);
    void print(FSNode *root);

   public:
    FrequencySet();
    ~FrequencySet();
    void add(char value);
    void addToQueue(PriorityQueue *queue);
    void print();
};