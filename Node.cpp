#include "Node.h"

Node::Node() {
}

Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

Node::Node(int data, Node *next) {
    this->data = data;
    this->next = next;
}

int Node::getData() { return data; }

void Node::setData(int data) { this->data = data; }

Node * Node::getNext() { return next; }

void Node::setNext(Node *next) { this->next = next; }

