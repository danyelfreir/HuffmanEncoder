#include "../include/PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    this->head = nullptr;
    this->_length = 0;
}

PriorityQueue::~PriorityQueue() {
    PQNode *current = this->head;
    while (current) {
        PQNode *tmp = current;
        current = current->next;
        delete tmp;
        tmp = nullptr;
    }
}

void PriorityQueue::push(char value, int frequency) {
    PQNode *newNode = new PQNode(value, frequency);
    if (!this->head || newNode->frequency() < this->head->frequency()) {
        newNode->next = this->head;
        this->head = newNode;
    } else {
        PQNode *current = this->head;
        while (current->next && current->next->frequency() < newNode->frequency()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    this->_length++;
}

PQNode *PriorityQueue::pop() {
    /* Returns the Queue head.
       >>NOT MEMORY SAFE<<
       Remember to delete after use! */
    PQNode *tmp = this->head;
    this->head = this->head->next;
    this->_length--;
    return tmp;
}

int PriorityQueue::length() { return this->_length; }

void PriorityQueue::print() {
    PQNode *current = this->head;
    while (current) {
        std::cout << current->value() << " -> " << current->frequency() << "\n";
        current = current->next;
    }
}