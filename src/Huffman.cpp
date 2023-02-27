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

void Huffman::generateCodes(std::map<char, std::string> &huffmanCodes) {
    HuffmanNode *root = this->_head;
    char bitString[MAX_CHAR_VAL];
    this->generateCodes(root, bitString, 0, huffmanCodes);
}

void Huffman::generateCodes(Node *root, char *bitString, int level,
                            std::map<char, std::string> &huffmanCodes) {
    if (root->left) {
        bitString[level] = '0';
        this->generateCodes(root->left, bitString, level + 1, huffmanCodes);
    }
    if (root->right) {
        bitString[level] = '1';
        this->generateCodes(root->right, bitString, level + 1, huffmanCodes);
    }
    if (root->isLeafNode()) {
        bitString[level] = 0;
        HuffmanLeaf *tmp = (HuffmanLeaf *)root;
        huffmanCodes.insert({tmp->value(), std::string(bitString, level)});
    }
}
