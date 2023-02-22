#include "../include/FrequencySet.h"

FrequencySet::FrequencySet() {
    this->head = nullptr;
    this->size = 0;
}

FrequencySet::~FrequencySet() {
    // TODO: Implement
}

void FrequencySet::add(char value) {
    this->head = this->add(this->head, value);
}

FSNode *FrequencySet::add(FSNode *root, char value) {
    if (!root) {
        this->size++;
        return new FSNode(value);
    }
    if (root->value == value) {
        root->frequency++;
    } else if (root->value > value) {
        root->left = add(root->left, value);
    } else if (root->value < value) {
        root->right = add(root->right, value);
    }
    return root;
}

void FrequencySet::convertToQueue(PriorityQueue *queue) {
    convertToQueue(this->head, queue);
}

void FrequencySet::convertToQueue(FSNode *root, PriorityQueue *queue) {
    if (!root) return;
    if (root->left) convertToQueue(root->left, queue);
    if (root->right) convertToQueue(root->right, queue);
    queue->push(new PQNode(root->value, root->frequency));
    delete root;
}

void FrequencySet::print() {
    this->print(this->head);
}

void FrequencySet::print(FSNode *root) {
    if (root->left) print(root->left);
    std::cout << root->value << " => " << root->frequency << "\n";
    if (root->right) print(root->right);
}