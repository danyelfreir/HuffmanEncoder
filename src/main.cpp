#include <fstream>

#include "../include/FrequencySet.h"
#include "../include/HuffmanEncoding.h"
#include "../include/HuffmanDecoding.h"
#include "../include/PriorityQueue.h"

int main() {
    FrequencySet *fs = new FrequencySet();
    PriorityQueue *pq = new PriorityQueue();
    HuffmanEncoding *hc = new HuffmanEncoding();
    // HuffmanDecoding *hd = new HuffmanDecoding();
    std::ifstream fin;
    std::ofstream fout;

    fin.open("data/large.txt", std::ios::binary);
    char cur;
    while (fin.get(cur)) {
        fs->add(cur);
    }
    fin.close();
    fs->addToQueue(pq);
    delete fs;
    hc->populate(pq);
    delete pq;
    hc->generateHuffmanTree();
    fin.open("data/large.txt", std::ios::binary);
    fout.open("test.cmpr", std::ios::binary);
    hc->encode(fout, fin);
    fin.close();
    fout.close();
    fin.open("test.cmpr", std::ios::binary);
    fout.open("test_out.txt");
    // hc->decode(fout, fin);

    return 0;
}