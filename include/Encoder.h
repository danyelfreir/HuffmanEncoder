#pragma once

#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "Huffman.h"
#include "Node.h"

class Encoder {
   private:
    static int const MAX_CHAR_VAL = 255;
    std::ifstream fin;
    std::ofstream fout;
    unsigned int frequencyTable[MAX_CHAR_VAL];
    unsigned char numOfSymbols;
    Huffman huffman;
    void readFile();
    void writeHeader();
    void print(Node *root);

   public:
    Encoder(std::string inputFile, std::string outputFile);
    void encode();
    void print();
};