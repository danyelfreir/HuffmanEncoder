#include "../include/Encoder.h"

Encoder::Encoder(std::string inputFile, std::string outputFile) {
    this->fin.open(inputFile, std::ios::binary);
    this->fout.open(outputFile, std::ios::binary);
    for (int i = 0; i < MAX_CHAR_VAL; i++) {
        this->frequencyTable[i] = 0;
    }
    this->numOfSymbols = 0;
}

void Encoder::readFile() {
    char character;
    while (this->fin.get(character)) {
        if (!this->frequencyTable[character]) this->numOfSymbols++;
        this->frequencyTable[character]++;
    }
    this->fin.seekg(0);
}

void Encoder::writeHeader() {
    unsigned char character;
    this->fout << this->numOfSymbols;
    for (unsigned char i = 0; i < MAX_CHAR_VAL; i++) {
        if (this->frequencyTable[i] > 0) {
            this->fout << i;
            for (int j = 3; j >= 0; j--) {
                character = (unsigned char)this->frequencyTable[i] >> (8 * j);
                this->fout << character;
            }
        }
    }
}

void Encoder::encode() {
    this->readFile();
    this->writeHeader();
    this->huffman.populateTree(this->frequencyTable);
}

void Encoder::print() {
    HuffmanNode *root = this->huffman.head();
    this->print(root);
}

void Encoder::print(Node *root) {
    if (root->left) this->print(root->left);
    if (root->right) this->print(root->right);
    HuffmanLeaf *tmp;
    if (root->isLeafNode()) {
        tmp = (HuffmanLeaf *)root;
        std::cout << tmp->value() << " -> " << tmp->frequency() << std::endl;
    }
}