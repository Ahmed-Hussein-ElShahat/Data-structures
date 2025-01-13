//
// Created by Ahmed hesen on 1/13/2025.
//

#ifndef DATA_STRUCTURE_LINKEDLIST_H
#define DATA_STRUCTURE_LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
    Node *head;
    int length;
    void printReverse(Node* node);
    void reverseRecursively(Node* node);
public:
    LinkedList();



    //inserting functions
    void insertAtBegin(int data);
    void insertNode(int data);
    void insertNode(int data, int n);

    //deleting functions
    void deleteNodeAt(int n);
    void deleteFront();

    //reversing functions
    void reverse();
    void reverseRecursively();

    //printing functions
    void printList();
    void printReverse();

    int size();
    bool empty();

    void clear();
    ~LinkedList();
};


#endif //DATA_STRUCTURE_LINKEDLIST_H
