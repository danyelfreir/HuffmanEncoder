#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

#include "HCNode.h"
#include "PriorityQueue.h"

class HuffmanEncoding {
   private:
    HCNode *queueHead;
    std::map<char, std::string> huffmanCodes;
    int _size;
    void push(char value, int frequency);
    void push(HCNode *newNode);
    HCNode *pop();
    // void createHuffmanString(HCNode *root, char *bitString, int level);
    void createHuffmanString(HCNode *root, char *bitString, int level);
    short createHuffmanCodeFromString(char value, std::string &bitString);

    public:
    HuffmanEncoding();
    HCNode *getHead();
    void populate(PriorityQueue *queue);
    void generateHuffmanTree();
    void encode(std::ofstream &fout, std::ifstream &fin);
    void print();
};
