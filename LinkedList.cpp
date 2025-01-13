//
// Created by Ahmed hesen on 1/13/2025.
//

#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
    length = 0;
}

//inserting functions
void LinkedList::insertAtBegin(int data){
    length++;
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertNode(int data){
    Node* temp = head;
    Node *newNode = new Node(data);

    length++;
    if(head==nullptr) { //if the list is empty then the new node is the head
        head = newNode;
        return;
    }
    while(temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}
void LinkedList::insertNode(int data, int n){
    Node* temp = head;
    Node* newNode = new Node(data);
    if(n>length) {
        std::cout << "Index out of range" << std::endl;
        return;
    }

    length++;
    if(n==0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    for(int i=0; i<n-1; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}
//deleting functions
void LinkedList::deleteNodeAt(int n){
    Node *temp = head;
    if(head==nullptr)return;
    if(n>=length){
        std::cout << "Index out of range" << std::endl;
        return;
    }

    length--;
    if(n==0) {
        head = temp->next;
        delete temp;
        return;
    }
    for(int i=0; i<n-1; i++)
        temp = temp->next;

    Node* toDelete = temp->next;
    temp->next = toDelete->next;

    delete toDelete;
}

void LinkedList::deleteFront(){
    if(empty())return;

    length--;
    Node* temp = head;
    head = head->next;
    delete temp;
}
//reversing functions
void LinkedList::reverse(){
    Node* prev=nullptr;
    Node* current=head;
    Node *next;

    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void LinkedList::reverseRecursively(){
    reverseRecursively(head);
}

void LinkedList::reverseRecursively(Node* node){
    if(node->next==nullptr){
        head = node;
        return;
    }
    reverseRecursively(node->next);
    Node* temp = node->next;
    temp->next = node;
    node->next = nullptr;
}

//printing functions
void LinkedList::printList(){
    Node* temp = head;
    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void LinkedList::printReverse(){
    printReverse(head);
    std::cout << std::endl;
}
void LinkedList::printReverse(Node* node){
    if(node==nullptr)return;
    printReverse(node->next);
    std::cout << node->data << " ";
}

int LinkedList::size(){
    return length;
}

bool LinkedList::empty(){
    return head==nullptr;
}

void LinkedList::clear(){
    while(!empty())
        deleteFront();
}

LinkedList::~LinkedList() { clear(); }