#include "../include/HuffmanDecoding.h"

HuffmanDecoding::HuffmanDecoding(std::string inputFile, std::string outputFile) {
    fin.open(inputFile, std::ios::binary);
    fout.open(outputFile, std::ios::binary);
    this->queueHead = nullptr;
    this->_size = 0;
}

void HuffmanDecoding::readHeaders() {
    char charCount;
    char character;
    char charCodeLen;
    unsigned short charCode = 0;
    char tmp;
    fin.read(&charCount, 1);
    for (int i = 0; i < charCount; i++) {
        charCode = 0;
        fin.get(character);
        fin.get(charCodeLen);
        fin.get(tmp);
        charCode = (charCode | tmp) << 8;
        fin.get(tmp);
        short tmp2 = ((short)tmp) & 0xFF;
        charCode = charCode | tmp2;
        this->queue.push(new HDNode(character, (int)charCodeLen, (int)charCode));
    }
}

void HuffmanDecoding::generateHuffmanTree() {
    while (!this->queue.empty()) {
        // this->print();
        HDNode *current = this->queue.top();
        this->queueHead = this->insert(this->queueHead, current, 0);
        this->queue.pop();
        std::cout << current->value << " -> " << current->bitString << "\n";
    }
}

HDNode *HuffmanDecoding::insert(HDNode *root, HDNode *value, int level) {
    if (!root) return value;
    if (!root->left && ((root->bitString >> ((root->bitStringLen - 1 - level) & 1)) == 0)) {
        int mask = 1;
        for (int i = 0; i < root->bitStringLen - 1 - level; i++) {
            mask |= 1 << i;
        }
        root->left = new HDNode(0, root->bitStringLen - 1 - level, (root->bitString >> level) & mask);
    } else if (!root->right && ((root->bitString >> ((root->bitStringLen - 1 - level) & 1)) == 1)) {
        int mask = 1;
        for (int i = 0; i < root->bitStringLen - 1 - level; i++) {
            mask |= 1 << i;
        }
        root->right = new HDNode(0, root->bitStringLen - 1 - level, (root->bitString >> level) & mask);
    }

    if ((root->bitString >> ((root->bitStringLen - 1 - level) & 1)) == 0) {
        root->left = this->insert(root->right, value, level + 1);
    } else if ((root->bitString >> ((root->bitStringLen - 1 - level) & 1)) == 1) {
        root->right = this->insert(root->right, value, level + 1);
    }
    return root;
}

void HuffmanDecoding::decode() {
    this->readHeaders();
    this->generateHuffmanTree();
    this->print();
    // char currentChar;
    // int bit;
    // int bitPos = 7;
    // HDNode *currentNode = queueHead;
    // while (fin.get(currentChar)) {
    // for (int i = 7; i >= 0; i--) {
    //     if (bitPos < 0) bitPos = 7;
    //     bit = (currentChar >> bitPos) & 1;
    //     if (bit) {
    //         currentNode = currentNode->right;
    //         bitPos--;
    //     } else {
    //         currentNode = currentNode->left;
    //         bitPos--;
    //     }
    //     if (currentNode->value()) {
    //         fout << currentNode->value();
    //         currentNode = queueHead;
    //     }
    // }
    // }
}

void HuffmanDecoding::print() {
    // this->print(this->queueHead);
    while (!this->queue.empty()) {
        HDNode *tmp = this->queue.top();
        std::cout << tmp->value << " -> " << tmp->bitString << std::endl;
        this->queue.pop();
    }
}

void HuffmanDecoding::print(HDNode *root) {
    if (root->left) this->print(root->left);
    if (root->right) this->print(root->right);
    std::cout << root->value << " -> " << root->bitString << "\n";
}