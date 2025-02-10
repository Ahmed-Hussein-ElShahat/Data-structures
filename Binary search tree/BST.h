//
// Created by Ahmed Hussein on 2/9/2025.
//

#ifndef DATA_STRUCTURE_BST_H
#define DATA_STRUCTURE_BST_H

#include "BSTNode.h"

class BST {
private:
    BSTNode *root;
    BSTNode *insert(int data, BSTNode *root);
    BSTNode *findMin(BSTNode *root);
    BSTNode *findMax(BSTNode *root);
    int findHeight(BSTNode *root);
    BSTNode *remove(int data, BSTNode *root);
    void printInOrder(BSTNode *root);
    void printPreOrder(BSTNode *root);
    void printPostOrder(BSTNode *root);
    bool checkBST(BSTNode *root, int minVal, int maxVal);
    bool checkBST_inorder(BSTNode *root);
public:
    BST();
    BSTNode *getRoot();
    void insert(int data);
    int findMin();
    int findMax();
    int findHeight();
    void remove(int data);
    bool search(int data);
    BSTNode *search(int data, BSTNode *root);
    BSTNode * getSuccessor(int data);
    void levelOrder();
    void printInOrder();
    void printPreOrder();
    void printPostOrder();
    bool checkBST();
    void clear(BSTNode *root);
    ~BST();
};


#endif //DATA_STRUCTURE_BST_H
