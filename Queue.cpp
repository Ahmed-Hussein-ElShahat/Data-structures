#include <iostream>
#include "Queue.h"

Queue::Queue(){
    frontt = rear = nullptr;
    length = 0;
}
void Queue::enqueue(int data){
    Node *newNode = new Node(data);
    length++;
    if(empty()){
        frontt = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

void Queue::dequeue(){
    if(empty()){
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    Node *temp = frontt;
    if(frontt==rear)
        frontt = rear = nullptr;
    else
        frontt = frontt->next;

    delete temp;
    length--;
}

int Queue::front(){
    if(empty()){
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }
    else return frontt->data;
}

int Queue::size(){
    return length;
}

bool Queue::empty(){
    return frontt == nullptr;
}
void Queue::clear(){
    while(!empty())
        dequeue();
}
Queue::~Queue(){
    clear();
}