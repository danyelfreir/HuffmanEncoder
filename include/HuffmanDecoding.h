#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>

#include "HCNode.h"

class HuffmanDecoding {
private:
	std::map<char, std::string> huffmanCodes;
public:
	HuffmanDecoding();
	void loadHeaders(std::ifstream &fin);
    void decode(std::ofstream &fout, std::ifstream &fin, HCNode *queueHead);
};