#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Huffman.h"
#include "Node.h"

class Decoder {
   private:
    static int const MAX_CHAR_VAL = 255;
    std::ifstream fin;
    std::ofstream fout;
    unsigned int frequencyTable[MAX_CHAR_VAL];
    Huffman huffman;
    void readHeader();
    void readBody();
    void print(Node *root);

   public:
    Decoder(std::string inputFile, std::string outputFile);
    void decode();
    void print();
};