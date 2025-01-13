#ifndef DATA_STRUCTURE_NODE_H
#define DATA_STRUCTURE_NODE_H


class Node {
private:
    int data;
    Node *next;
public:
    Node();
    Node(int data);
    Node(int data, Node *next);
    int getData();
    void setData(int data);
    Node *getNext();
    void setNext(Node *next);

    friend class LinkedList;
};


#endif //DATA_STRUCTURE_NODE_H
