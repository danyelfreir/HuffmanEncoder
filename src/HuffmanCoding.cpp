#include "../include/HuffmanCoding.h"

HuffmanCoding::HuffmanCoding() {
    this->queueHead = nullptr;
    int _size = 0;
}

HCNode *HuffmanCoding::getHead() { return this->queueHead; }

void HuffmanCoding::push(char value, int frequency) {
    HCNode *newNode = new HCNode(value, frequency, nullptr, nullptr);
    if (!this->queueHead || newNode->frequency() < this->queueHead->frequency()) {
        newNode->next = this->queueHead;
        this->queueHead = newNode;
    } else {
        HCNode *current = this->queueHead;
        while (current->next && current->next->frequency() < newNode->frequency()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    this->_size++;
}

void HuffmanCoding::push(HCNode *newNode) {
    if (!this->queueHead || newNode->frequency() < this->queueHead->frequency()) {
        newNode->next = this->queueHead;
        this->queueHead = newNode;
    } else {
        HCNode *current = this->queueHead;
        while (current->next && current->next->frequency() < newNode->frequency()) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    this->_size++;
}

HCNode *HuffmanCoding::pop() {
    HCNode *tmp = this->queueHead;
    this->queueHead = this->queueHead->next;
    this->_size--;
    return tmp;
}

void HuffmanCoding::populate(PriorityQueue *queue) {
    while (queue->length() > 0) {
        PQNode *pqnode = queue->pop();
        this->push(pqnode->value(), pqnode->frequency());
        delete pqnode;
    }
}

void HuffmanCoding::encode() {
    while (this->_size > 1) {
        HCNode *nodeA = this->pop();
        HCNode *nodeB = this->pop();
        HCNode *newNode = new HCNode(0, nodeA->frequency() + nodeB->frequency(), nodeA, nodeB);
        this->push(newNode);
    }
}

void HuffmanCoding::decode() {
    // IMPLEMENT
}

void HuffmanCoding::print() {
    char string[64];
    this->print(this->queueHead, string, 0);
}

void HuffmanCoding::print(HCNode *root, char *string, int level) {
    if (root->left) {
        string[level] = '0';
        print(root->left, string, level + 1);
    }
    if (root->right) {
        string[level] = '1';
        print(root->right, string, level + 1);
    }
    if (root->value()) {
        printf("%c -> %s\n", root->value(), string);
    }
}