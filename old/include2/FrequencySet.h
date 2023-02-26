#pragma once
#include <iostream>

#include "FSNode.h"

class FrequencySet {
   private:
    FSNode *head;
    int size;
    void deleteNodes(FSNode *root);
    FSNode *add(FSNode *root, char value);
    FSNode *next(FSNode *root, std::pair<char, int> &nextPair);
    // void addToQueue(FSNode *root, HuffmanEncoding *queue);
    void print(FSNode *root);

   public:
    FrequencySet();
    ~FrequencySet();
    bool empty();
    void add(char value);
    void next(std::pair<char, int> &nextPair);
    void deleteNode(FSNode *node);
    // void addToQueue(HuffmanEncoding *queue);
    void print();
};