#include "../include/Huffman.h"

Huffman::Huffman() { this->_head = nullptr; }

void Huffman::populateTree(unsigned int *frequencyTable) {
    for (int i = 0; i < MAX_CHAR_VAL; i++) {
        if (frequencyTable[i] > 0) {
            this->queue.push(new HuffmanLeaf(frequencyTable[i], i));
        }
    }
    while (this->queue.size() > 1) {
        Node *nodeA = this->queue.top();
        this->queue.pop();
        Node *nodeB = this->queue.top();
        this->queue.pop();
        this->queue.push(new HuffmanNode(nodeA->frequency() + nodeB->frequency(), nodeA, nodeB));
    }
    this->_head = (HuffmanNode *)this->queue.top();
    this->queue.pop();
}

HuffmanNode *Huffman::head() { return this->_head; }