#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

class Node {
   public:
    int value;
    char frequency;
    Node(int value, char frequency) {
        this->value = value;
        this->frequency = frequency;
    }

    bool operator<(const Node &that) { return this->frequency < that.frequency; }

    bool operator>(const Node &that) { return this->frequency > that.frequency; }
};

int main() {
    std::priority_queue<std::pair<int, char> > q1;
    std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char> >,
                        std::greater<std::pair<int, char> > >
        q2;
    int b = 10;

    for (int i = 10; i >= 0; i--) {
        std::pair<int, char> newNode(++b, i);
        q1.push(newNode);
        q2.push(newNode);
    }

    while (!q1.empty()) {
        std::pair<int, char> cur = q1.top();
        std::cout << cur.first << " -> " << cur.second << "\n";
        q1.pop();
    }
    while (!q2.empty()) {
        std::pair<int, char> cur = q2.top();
        std::cout << cur.first << " -> " << cur.second << "\n";
        q2.pop();
    }

    return 0;
}