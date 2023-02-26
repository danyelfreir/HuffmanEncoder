#include "../include/PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    this->head = nullptr;
    this->_length = 0;
}

void PriorityQueue::push(Node *newNode) {
    if (!this->head || newNode < this->head) {
        newNode->next = this->head;
        this->head = newNode;
    } else {
        Node *current = this->head;
        while (current->next && current->next < newNode) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    this->_length++;
}

int PriorityQueue::getHeadFreq() { return this->head->frequency; }

Node *PriorityQueue::pop() {
    Node *tmp = this->head;
    this->head = this->head->next;
    this->_length--;
    return tmp;
}

int PriorityQueue::length() { return this->_length; }

void PriorityQueue::encode() {
    while (this->_length > 1) {
        HCNode *newNode = new HCNode(this->pop(), this->pop());
        this->push(newNode);
    }
}

void PriorityQueue::print() {
    char string[128];
    this->print(this->head, string, 0);
}

void PriorityQueue::print(Node *root, char *string, int level) {
    if (root->left) {
        string[level] = '0';
        this->print(root->left, string, level + 1);
    }
    if (root->right) {
        string[level] = '1';
        this->print(root->right, string, level + 1);
    }
    std::cout << root->value << " -> " << string << "\n";
}