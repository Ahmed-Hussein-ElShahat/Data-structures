#include "Stack.h"

Stack::Stack(){
    topNode = nullptr;
    size=0;
}

void Stack::push(int data){
    Node* newNode = new Node(data);
    newNode->next = topNode;
    topNode = newNode;
    size++;
}

void Stack::pop(){
    if(empty())return;
    Node* temp = topNode;
    topNode = temp->next;
    delete temp;
    size--;
}

int Stack::top() {
    return topNode->data;
}

bool Stack::empty(){
    return topNode==nullptr;
}

int Stack::getSize(){
    return size;
}
void Stack::clear(){
    while(!empty()){
        pop();
    }
}
Stack::~Stack(){
    clear();
}