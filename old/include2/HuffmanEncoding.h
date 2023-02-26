#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../include/FSNode.h"
#include "FrequencySet.h"
#include "HCNode.h"

const int MAX_CHAR_VAL = 256;

class HuffmanEncoding {
   private:
    HCNode *queueHead;
    std::ifstream fin;
    std::ofstream fout;
    std::map<char, std::string> huffmanCodes;
    int frequencyTable[MAX_CHAR_VAL];
    int _size;
    void push(HCNode *newNode);
    HCNode *pop();
    void writeHeaders();
    void createHuffmanString(HCNode *root, char *bitString, int level);
    short createHuffmanCodeFromString(char value, std::string &bitString);

   public:
    short codeStringToShort(std::string bitString);
    HuffmanEncoding(std::string inputFile, std::string outputFile);
    void compress(FrequencySet &fSet);
    HCNode *getHead();
    void push(char value, int frequency);
    void generateHuffmanTree();
    void encode();
    void print();
};
