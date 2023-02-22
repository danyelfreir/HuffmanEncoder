#include "../include/HCLeaf.h"

HCLeaf::HCLeaf(char value, int frequency) : HCNode(frequency) {
    this->value = value;
}