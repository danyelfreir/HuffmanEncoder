#include "../include/Decoder.h"

Decoder::Decoder(std::string inputFile, std::string outputFile) {
    this->fin.open(inputFile, std::ios::binary);
    this->fout.open(outputFile, std::ios::binary);
}

void Decoder::readHeader() {
    char character = 0;
    char tmp = 0;
    int frequency = 0;
    char numOfSymbols = 0;
    fin.read(&numOfSymbols, 1);
    for (int i = 0; i < numOfSymbols; i++) {
        fin.read(&character, 1);
        for (int j = 3; j >= 0; j--) {
            fin.read(&tmp, 1);
            frequency |= ((unsigned int)tmp << (8 * j));
        }
        std::cout << character << " -> " << frequency << std::endl;
        frequency = 0;
    }
}