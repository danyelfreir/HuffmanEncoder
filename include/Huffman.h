#pragma once
#include <iostream>
#include <map>
#include <queue>
#include <string>

#include "HuffmanLeaf.h"
#include "HuffmanNode.h"

class Huffman {
   private:
    static int const MAX_CHAR_VAL = 255;
    HuffmanNode *_head;
    std::priority_queue<Node *, std::vector<Node *>, std::greater<Node *> > queue;
    void generateCodes(Node *root, char *bitString, int level,
                        std::map<char, std::string> &huffmanCodes);

   public:
    Huffman();
    void populateTree(unsigned int *frequencyTable);
    HuffmanNode *head();
    void generateCodes(std::map<char, std::string> &huffmanCodes);
    void print();
};