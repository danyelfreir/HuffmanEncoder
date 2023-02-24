#include <fstream>

#include "../include/FrequencySet.h"
#include "../include/HuffmanCoding.h"
#include "../include/PriorityQueue.h"

int main() {
    FrequencySet *fs = new FrequencySet();
    PriorityQueue *pq = new PriorityQueue();
    HuffmanCoding *hc = new HuffmanCoding();

    std::ifstream fin("data/large.txt", std::ios::binary);
    char cur;
    while (fin.get(cur)) {
        fs->add(cur);
    }
    std::cout << "From set: " << std::endl;
    fs->print();
    fs->addToQueue(pq);
    delete fs;
    std::cout << "From queue: " << std::endl;
    pq->print();
    hc->populate(pq);
    delete pq;
    hc->encode();
    std::cout << "From huffmans: " << std::endl;
    hc->print();

    return 0;
}