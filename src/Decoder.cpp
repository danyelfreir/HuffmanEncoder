#include "../include/Decoder.h"

Decoder::Decoder(std::string inputFile, std::string outputFile) {
    this->fin.open(inputFile, std::ios::binary);
    this->fout.open(outputFile, std::ios::binary);
    for (int i = 0; i < MAX_CHAR_VAL; i++) {
        this->frequencyTable[i] = 0;
    }
}

void Decoder::readHeader() {
    char character = 0;
    char tmp = 0;
    unsigned int frequency = 0;
    for (int i = 0; i < MAX_CHAR_VAL; i++) {
        fin.read(&character, 1);
        for (int j = 3; j >= 0; j--) {
            fin.read(&tmp, 1);
            unsigned int tmp2 = (unsigned int)tmp;
            tmp2 = tmp2 & 0xFF;
            frequency |= (tmp2 << 8 * j);
        }
        unsigned char unsignedCharacter = (unsigned char)character;
        this->frequencyTable[unsignedCharacter] = frequency;
        frequency = 0;
    }
}

void Decoder::readBody() {
    char byteIn;
    Node *currentNode = this->huffman.head();
    while (this->fin.read(&byteIn, 1)) {
        for (int i = 7; i >= 0; i--) {
            if (((byteIn >> i) & 1) == 0) {
                currentNode = currentNode->left;
            } else if (((byteIn >> i) & 1) == 1) {
                currentNode = currentNode->right;
            }
            if (currentNode->isLeafNode()) {
                HuffmanLeaf *tmp = (HuffmanLeaf *)currentNode;
                char val = tmp->value();
                this->fout.write(&val, 1);
                currentNode = this->huffman.head();
            }
        }
    }
}

void Decoder::decode() {
    this->readHeader();
    this->huffman.populateTree(this->frequencyTable);
    this->readBody();
    this->fin.close();
    this->fout.close();
}

void Decoder::print() {
    HuffmanNode *root = this->huffman.head();
    this->print(root);
}

void Decoder::print(Node *root) {
    if (root->left) this->print(root->left);
    if (root->right) this->print(root->right);
    HuffmanLeaf *tmp;
    if (root->isLeafNode()) {
        tmp = (HuffmanLeaf *)root;
        std::cout << tmp->value() << " -> " << tmp->frequency() << std::endl;
    }
}