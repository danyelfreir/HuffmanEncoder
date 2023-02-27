#include "../include/Encoder.h"

Encoder::Encoder(std::string inputFile, std::string outputFile) {
    this->fin.open(inputFile, std::ios::binary);
    this->fout.open(outputFile, std::ios::binary);
    for (int i = 0; i < MAX_CHAR_VAL; i++) {
        this->frequencyTable[i] = 0;
    }
}

void Encoder::readFile() {
    char character;
    while (this->fin.get(character)) {
        unsigned char unsignedCharacter = (unsigned char)character;
        this->frequencyTable[unsignedCharacter]++;
    }
    this->fin.clear();
    this->fin.seekg(0);
}

void Encoder::writeHeader() {
    char character;
    for (unsigned char i = 0; i < MAX_CHAR_VAL; i++) {
        char s_i = (char)i;
        this->fout.write(&s_i, 1);
        for (int j = 3; j >= 0; j--) {
            character = (char)(this->frequencyTable[i] >> (8 * j));
            this->fout.write(&character, 1);
        }
    }
}

void Encoder::writeBody() {
    char byte = 0;
    int bitPos = 7;
    char cur;
    while (this->fin.read(&cur, 1)) {
        std::string curCompr = this->huffmanCodes[cur];
        for (char letter : curCompr) {
            if (bitPos < 0) {
                this->fout.write(&byte, 1);
                byte = 0;
                bitPos = 7;
            }
            if (letter == '0') {
                bitPos--;
            } else if (letter == '1') {
                byte |= (1 << bitPos);
                bitPos--;
            }
        }
    }
}

void Encoder::encode() {
    this->readFile();
    this->writeHeader();
    this->huffman.populateTree(this->frequencyTable);
    this->huffman.generateCodes(this->huffmanCodes);
    this->writeBody();
    this->fin.close();
    this->fout.close();
}

void Encoder::print() {
    for (auto const &x : this->huffmanCodes) {
        std::cout << (unsigned int)x.first << " -> " << x.second << std::endl;
    }
}
