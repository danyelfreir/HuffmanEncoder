#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Decoder {
   private:
    static int const MAX_CHAR_VAL = 255;
    std::ifstream fin;
    std::ofstream fout;

   public:
    Decoder(std::string inputFile, std::string outputFile);
    void readHeader();
};