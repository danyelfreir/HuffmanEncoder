#include "../include/Node.h"

Node::Node(char value, int frequency) {
    this->_value = value;
    this->_frequency = frequency;
}

char Node::value() { return this->_value; }

int Node::frequency() { return this->_frequency; }