#pragma once

class PQNode {
public:
    char value;
    int frequency;
    PQNode *next;
    PQNode(char value, int frequency);
};