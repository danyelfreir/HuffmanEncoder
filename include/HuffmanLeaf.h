#pragma once
#include "Node.h"

class HuffmanLeaf : public Node {
   private:
    char _value;

   public:
    HuffmanLeaf(int frequency, char value);
    char value();
};