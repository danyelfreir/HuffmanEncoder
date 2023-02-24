#include "../include/HuffmanDecoding.h"

HuffmanDecoding::HuffmanDecoding() {
	// TODO
}

void HuffmanDecoding::loadHeaders(std::ifstream &fin) {
	// TODO
}

/*
	Header hugmynd -> | 8-bit stafur | 8-bit lengd kóða | 16/32-bit kóði |
	Í encode fallinu, þegar búið er að encodea alla stafina, bæta þessum upplýsingum í gagnagrind,
	og skrifa svo í headerinn.
*/

void HuffmanDecoding::decode(std::ofstream &fout, std::ifstream &fin, HCNode *queueHead) {
    char currentChar;
    int bit;
    int bitPos = 7;
    HCNode *currentNode = queueHead;
    while (fin.get(currentChar)) {
        for (int i = 7; i >= 0; i--) {
            if (bitPos < 0) bitPos = 7;
            bit = (currentChar >> bitPos) & 1;
            if (bit) {
                currentNode = currentNode->right;
                bitPos--;
            } else {
                currentNode = currentNode->left;
                bitPos--;
            }
            if (currentNode->value()) {
                fout << currentNode->value();
                currentNode = queueHead;
            }
        }
    }
}