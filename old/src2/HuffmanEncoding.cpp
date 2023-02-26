#include "../include/HuffmanEncoding.h"

HuffmanEncoding::HuffmanEncoding(std::string inputFile, std::string outputFile) {
    this->fin.open(inputFile, std::ios::binary);
    this->fout.open(outputFile, std::ios::binary);
    this->queueHead = nullptr;
    for (int i = 0; i < MAX_CHAR_VAL; i++) {
        this->frequencyTable[i] = 0;
    }
    this->_size = 0;
}

void HuffmanEncoding::compress(FrequencySet &fSet) {
    char current;
    while (this->fin.get(current)) {
        std::cout << current << std::endl;
        this->frequencyTable[current] = this->frequencyTable[current] + 1;
        // fSet.add(current);
    }
    for (int i = 0; i < MAX_CHAR_VAL; i++) {
        if (this->frequencyTable[i] > 0) {
            this->push(i, frequencyTable[i]);
        }
    }
    this->generateHuffmanTree();
    this->writeHeaders();
    // this->fin.close();
    // this->fout.close();
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

void HuffmanEncoding::generateHuffmanTree() {
    while (this->_size > 1) {
        HCNode *nodeA = this->pop();
        HCNode *nodeB = this->pop();
        HCNode *newNode = new HCNode(0, nodeA->frequency() + nodeB->frequency(), nodeA, nodeB);
        this->push(newNode);
    }
    char bitString[64];
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

void HuffmanEncoding::writeHeaders() {
    char codeCount = (char)this->huffmanCodes.size();
    this->fout.write(&codeCount, 1);
    for (auto &code : this->huffmanCodes) {
        this->fout.write(&code.first, 1);
        char codeLen = code.second.size() - 1;
        this->fout.write(&codeLen, 1);
        short shortCode = this->codeStringToShort(code.second);
        char shortCodeUpper = (char)(shortCode >> 8);
        char shortCodeLower = (char)shortCode;
        this->fout.write(&shortCodeUpper, 1);
        this->fout.write(&shortCodeLower, 1);
    }
}

short HuffmanEncoding::codeStringToShort(std::string bitString) {
    unsigned short shortCode = 0;
    int bitPos = bitString.size();
    for (char letter : bitString) {
        bitPos--;
        if (letter == '1') {
            shortCode |= 1 << (bitPos - 1);
        } else if (letter == '0') {
            shortCode |= 0 << (bitPos - 1);
        }
    }
    return shortCode;
}

void HuffmanEncoding::encode() {
    std::vector<unsigned char> bytes;
    unsigned char byte = 0;
    int bitPos = 7;
    char cur;
    while (this->fin.get(cur)) {
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
        this->fout << b;
    }
}

void HuffmanEncoding::print() {
    for (auto &code : this->huffmanCodes) {
        std::cout << code.first << " -> " << code.second << "\n";
    }
}

void HuffmanEncoding::createHuffmanString(HCNode *root, char *bitString, int level) {
    if (root->left) {
        bitString[level] = '0';
        createHuffmanString(root->left, bitString, level + 1);
    }
    if (root->right) {
        bitString[level] = '1';
        createHuffmanString(root->right, bitString, level + 1);
    }
    if (root->value()) {
        bitString[level] = 0;
        std::string newString(bitString, level + 1);
        this->huffmanCodes.insert({root->value(), newString});
    }
}