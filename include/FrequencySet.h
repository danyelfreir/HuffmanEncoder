#pragma once
#include <iostream>
#include "../include/FSNode.h"
#include "../include/PriorityQueue.h"

class FrequencySet {
private:
    FSNode *head;
    int size;
    FSNode *add(FSNode *root, char value);
    void convertToQueue(FSNode *root, PriorityQueue *queue);
    void print(FSNode *root);
public:
    FrequencySet();
    ~FrequencySet();
    void add(char value);
    void convertToQueue(PriorityQueue *queue);
    void print();
};