//
// Created by Ahmed Hussein on 2/9/2025.
//

#include "BSTNode.h"

BSTNode::BSTNode() {
}

BSTNode::BSTNode(int data){
    this->data = data;
    this->right = nullptr;
    this->left = nullptr;
}

BSTNode::BSTNode(int data, BSTNode *right, BSTNode *left){
    this->data = data;
    this->right = right;
    this->left = left;
}
int BSTNode::getData(){
    return this->data;
}

void BSTNode::setData(int data){
    this->data = data;
}

BSTNode *BSTNode::getRight(){
    return this->right;
}

BSTNode *BSTNode::getLeft(){
    return this->left;
}

void BSTNode::setRight(BSTNode *right){
    this->right = right;
}
void BSTNode::setLeft(BSTNode *left){
    this->left = left;
}
