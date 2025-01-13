#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#include "Node.h"

class Stack {
private:
    Node *topNode;
    int size;
public:
    Stack();
    void push(int data);
    void pop();
    int top();
    bool empty();
    int getSize();
    void clear();
    ~Stack();
};


#endif //DATA_STRUCTURE_STACK_H
