#include "../include/FrequencySet.h"

FrequencySet::FrequencySet() {
    this->head = nullptr;
    this->size = 0;
}

FrequencySet::~FrequencySet() { this->deleteNodes(this->head); }

void FrequencySet::deleteNodes(FSNode *root) {
    if (root->left) this->deleteNodes(root->left);
    if (root->right) this->deleteNodes(root->right);
    delete root;
}

bool FrequencySet::empty() { return this->size == 0; }

void FrequencySet::add(char value) { this->head = this->add(this->head, value); }

FSNode *FrequencySet::add(FSNode *root, char value) {
    if (!root) {
        this->size++;
        return new FSNode(value);
    }
    if (root->value() == value) {
        root->incrementFreq();
    } else if (root->value() > value) {
        root->left = add(root->left, value);
    } else if (root->value() < value) {
        root->right = add(root->right, value);
    }
    return root;
}

void FrequencySet::next(std::pair<char, int> &nextPair) { this->head = this->next(this->head, nextPair); }

FSNode *FrequencySet::next(FSNode *root, std::pair<char, int> &nextPair) {
    if (root->left) root->left = this->next(root->left, nextPair);
    if (root->right) root->right = this->next(root->right, nextPair);
    nextPair.first = root->value();
    nextPair.second = root->frequency();
    delete root;
    root = nullptr;
    return root;
}

// void FrequencySet::deleteNode(FSNode *node, ) {
//     this->size--;
//     std::cout << node->value() << " -> " << node->frequency() << std::endl;
//     delete node;
//     node = nullptr;
// }

// void FrequencySet::addToQueue(HuffmanEncoding *queue) { addToQueue(this->head, queue); }

// void FrequencySet::addToQueue(FSNode *root, HuffmanEncoding *queue) {
//     if (!root) return;
//     if (root->left) addToQueue(root->left, queue);
//     if (root->right) addToQueue(root->right, queue);
//     queue->push(root->value(), root->frequency());
// }

void FrequencySet::print() { this->print(this->head); }

void FrequencySet::print(FSNode *root) {
    if (root->left) print(root->left);
    std::cout << root->value() << " => " << root->frequency() << "\n";
    if (root->right) print(root->right);
}