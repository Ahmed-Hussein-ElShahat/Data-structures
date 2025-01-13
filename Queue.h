#ifndef DATA_STRUCTURE_QUEUE_H
#define DATA_STRUCTURE_QUEUE_H

#include "Node.h"

class Queue {
private:
    Node *frontt;
    Node *rear;
    int length;
public:
    Queue();
    void enqueue(int data);
    void dequeue();
    int front();
    int size();
    bool empty();
    void clear();
    ~Queue();
};


#endif //DATA_STRUCTURE_QUEUE_H
