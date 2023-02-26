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
    std::map<char, std::string> huffmanCodes;
    std::priority_queue<Node *, std::vector<Node *>, std::greater<Node *> > queue;

   public:
    Huffman();
    void populateTree(unsigned int *frequencyTable);
    HuffmanNode *head();
};