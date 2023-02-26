#pragma once
#include <fstream>
#include <iostream>
#include <queue>
#include <string>

#include "HDNode.h"

class HuffmanDecoding {
   private:
    std::ifstream fin;
    std::ofstream fout;
    HDNode *queueHead;
    int _size;
    std::priority_queue<HDNode *, std::vector<HDNode *>, std::greater<HDNode *>> queue;
    void generateHuffmanTree();
    HDNode *insert(HDNode *root, HDNode *value, int level);
    void print(HDNode *root);

   public:
    HuffmanDecoding(std::string inputFile, std::string outputFile);
    void readHeaders();
    void decode();
    void print();
};