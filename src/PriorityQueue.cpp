#include "../include/PriorityQueue.h"

PriorityQueue::PriorityQueue() {
    this->head = nullptr;
    this->_length = 0;
}

void PriorityQueue::push(PQNode *newNode) {
    if (!this->head || this->head->frequency > newNode->frequency) {
        newNode->next = this->head;
        this->head = newNode;
    } else {
        PQNode *current = this->head;
        while (current->next && current->next->frequency < newNode->frequency) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    this->_length++;
}

int PriorityQueue::getHeadFreq() {
    return this->head->frequency;
}

char PriorityQueue::pop() {
    PQNode *tmp = this->head;
    char returnValue = tmp->value;
    this->head = this->head->next;
    this->_length--;
    delete tmp;
    return returnValue;
}

void PriorityQueue::print() {
    /* For debugging */
    PQNode *current = this->head;
    while (current) {
        std::cout << (int)current->value << " => " << current->frequency << "\n";
        current = current->next;
    }
}

int PriorityQueue::length() {
    return this->_length;
}