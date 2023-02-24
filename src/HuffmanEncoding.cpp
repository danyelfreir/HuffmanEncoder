#include "../include/HuffmanEncoding.h"
#include <algorithm>
#include <iterator>

HuffmanEncoding::HuffmanEncoding() {
    this->queueHead = nullptr;
    int _size = 0;
}

HCNode *HuffmanEncoding::getHead() { return this->queueHead; }

void HuffmanEncoding::push(char value, int frequency) {
    HCNode *newNode = new HCNode(value, frequency, nullptr, nullptr);
    if (!this->queueHead || newNode->frequency() < this->queueHead->frequency()) {
        newNode->next = this->queueHead;
        this->queueHead = newNode;
    } else {
        HCNode *current = this->queueHead;
        while (current->next && current->next->frequency() < newNode->frequency()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    this->_size++;
}

void HuffmanEncoding::push(HCNode *newNode) {
    if (!this->queueHead || newNode->frequency() < this->queueHead->frequency()) {
        newNode->next = this->queueHead;
        this->queueHead = newNode;
    } else {
        HCNode *current = this->queueHead;
        while (current->next && current->next->frequency() < newNode->frequency()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    this->_size++;
}

HCNode *HuffmanEncoding::pop() {
    HCNode *tmp = this->queueHead;
    this->queueHead = this->queueHead->next;
    this->_size--;
    return tmp;
}

void HuffmanEncoding::populate(PriorityQueue *queue) {
    while (queue->length() > 0) {
        PQNode *pqnode = queue->pop();
        this->push(pqnode->value(), pqnode->frequency());
        delete pqnode;
    }
}

void HuffmanEncoding::generateHuffmanTree() {
    while (this->_size > 1) {
        HCNode *nodeA = this->pop();
        HCNode *nodeB = this->pop();
        HCNode *newNode = new HCNode(0, nodeA->frequency() + nodeB->frequency(), nodeA, nodeB);
        this->push(newNode);
    }
    char bitString[64];
    // std::string bitString;
    this->createHuffmanString(this->queueHead, bitString, 0);
}

short HuffmanEncoding::createHuffmanCodeFromString(char value, std::string &bitString) {
    short huffmanCode = 0;
    for (int i = 0; i < bitString.size(); i++) {
        if (bitString[i] == '1') {
            huffmanCode |= 1 << i;
        }
    }
    return huffmanCode;
}

void HuffmanEncoding::encode(std::ofstream &fout, std::ifstream &fin) {
    std::vector<unsigned char> bytes;
    unsigned char byte = 0;
    int bitPos = 7;
    char cur;
    while (fin.get(cur)) {
        std::string curCompr = this->huffmanCodes[cur];
        for (char letter : curCompr) {
            if (bitPos < 0) {
                bytes.push_back(byte);
                byte = 0;
                bitPos = 7;
            }
            if (letter == '0') {
                bitPos--;
            } else if (letter == '1') {
                byte |= 1 << bitPos;
                bitPos--;
            }
        }
    }
    for (unsigned char b : bytes) {
        fout << b;
    }
}


void HuffmanEncoding::print() {
    for (auto &code : this->huffmanCodes) {
        std::cout << code.first
                  << " -> "
                  << code.second
                  << "\n";
    }
}

// void HuffmanEncoding::createHuffmanString(HCNode *root, char *bitString, int level) {
void HuffmanEncoding::createHuffmanString(HCNode *root, char *bitString, int level) {
    if (root->left) {
        bitString[level] = '0';
        // bitString.append("0");
        createHuffmanString(root->left, bitString, level + 1);
    }
    if (root->right) {
        bitString[level] = '1';
        // bitString.append("1");
        createHuffmanString(root->right, bitString, level + 1);
    }
    if (root->value()) {
        bitString[level] = 0;
        // bitString.append(0);
        std::string newString(bitString, level + 1);
        this->huffmanCodes.insert({root->value(), newString});
    }
}