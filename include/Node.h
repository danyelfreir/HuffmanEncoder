#pragma once

class Node {
   protected:
    char _value;
    int _frequency;

   public:
    Node(char value, int frequency);
    char value();
    int frequency();
};