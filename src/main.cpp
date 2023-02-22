#include "../include/FrequencySet.h"
#include "../include/PriorityQueue.h"
#include <fstream>

int main() {
    FrequencySet fs;
    PriorityQueue pq;
    std::ifstream fin("data/large.txt", std::ios::binary);
    char cur;
    while (fin.get(cur)) {
        fs.add(cur);
    }
    fs.print();
    fs.convertToQueue(&pq);
    pq.print();

    return 0;
}