//
// Created by Ahmed Hussein on 2/9/2025.
//

#include <iostream>
#include <queue>
#include "BST.h"

BST::BST(){
    root = nullptr;
}

BSTNode *BST::getRoot(){
    return root;
}

void BST::insert(int data){
    root = insert(data, root);
}
BSTNode* BST::insert(int data, BSTNode *root){
    if(root == nullptr) {
        root = new BSTNode(data);
    }
    else if(data > root->data){
        root->right = insert(data, root->right);
    }
    else {
        root->left = insert(data, root->left);
    }
    return root;
}

BSTNode *BST::findMin(BSTNode *root){
    BSTNode *temp = root;
    if(root==nullptr) return nullptr;

    while(temp->left != nullptr) temp = temp->left;
    return temp;
}
int BST::findMin(){
    if(root==nullptr) {
        std::cout << "The tree is empty\n";
        return -1;
    }
    return findMin(root)->data;
}

BSTNode *BST::findMax(BSTNode *root){
    BSTNode *temp = root;
    if(root==nullptr) return nullptr;

    while(temp->right != nullptr) temp = temp->right;
    return temp;
}
int BST::findMax(){
    if(root==nullptr) {
        std::cout << "The tree is empty\n";
        return -1;
    }
    return findMax(root)->data;
}

int BST::findHeight(){
    return findHeight(root);
}

int BST::findHeight(BSTNode *root) {
    if(root==nullptr) return -1;
    return std::max(findHeight(root->left), findHeight(root->right)) + 1;
}

void BST::remove(int data) {
    root = remove(data, root);
}
BSTNode *BST::remove(int data, BSTNode *root){
    if(root==nullptr){
        std::cout << "The tree is empty\n";
        return nullptr;
    }
    if(data > root->data) root->right = remove(data, root->right);
    else if(data < root->data) root->left = remove(data, root->left);
    else{ //the node is found
        if(root->left == nullptr && root->right ==nullptr){ //node has no children
            delete root;
            root = nullptr;
        }
        else if(root->right==nullptr){ // node has a left child only
            BSTNode *temp = root->left;
            delete root;
            root = temp;
        }
        else if(root->left==nullptr) {//node has right child only
            BSTNode *temp = root->right;
            delete root;
            root = temp;
        }
        else{ //node has two children
            BSTNode *temp = findMax(root->left);
            root->data = temp->data;
            root->left = remove(temp->data, root->left);
        }
    }
    return root;
}

bool BST::search(int data){
    return search(data, root);
}
BSTNode *BST::search(int data, BSTNode *root){
    if(root==nullptr) return root;
    else if(root->data == data) return root;
    else if(data > root->data) return search(data, root->right);
    else return search(data, root->left);
}

//method to get the inorder successor of a node
BSTNode *BST::getSuccessor(int data){
    BSTNode *curr = search(data, root);
    if(curr == nullptr){
        std::cout<<"No node carry the given value\n";
        return nullptr;
    }
    if(curr->right)return findMin(curr->right);
    else{
        BSTNode *successor = nullptr;
        BSTNode *ancestor = root;
        while(data != ancestor->data){
            if(data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else ancestor = ancestor->right;
        }
        return successor;
    }
}

void BST::levelOrder(){
    if(root==nullptr) return;

    std::queue<BSTNode *> q;
    q.push(root);
    while(!q.empty()){
        BSTNode *current = q.front();
        //visit the current node
        std::cout << current->data << " ";

        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);

        q.pop();
    }
}

void BST::printInOrder(){ printInOrder(root); }
void BST::printInOrder(BSTNode *root){
    if(root==nullptr)return;

    printInOrder(root->left);
    std::cout<< root->data << " ";
    printInOrder(root->right);
}

void BST::printPreOrder() { printPreOrder(root); }
void BST::printPreOrder(BSTNode *root) {
    if(root==nullptr) return;

    std::cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void BST::printPostOrder(){ printPostOrder(root); }
void BST::printPostOrder(BSTNode *root){
    if(root== nullptr)return;

    printPostOrder(root->left);
    printPostOrder(root->right);
    std::cout<< root->data << " ";
}

bool BST::checkBST(){
    return checkBST(root, INT_MIN, INT_MAX);
}
bool BST::checkBST(BSTNode *root, int minVal, int maxVal){
    if(root==nullptr)return true;
    return root->data >= minVal && root->data < maxVal && checkBST(root->left, minVal, root->data) && checkBST(root->right, root->data, maxVal);
}

//another solution using inorder traversal
bool BST::checkBST_inorder(BSTNode *root){
    static BSTNode *prev = nullptr;
    if(root==nullptr)return true;
    if(!checkBST_inorder(root->left))return false;
    if(prev && prev->data > root->data) return false;
    prev = root;
    return checkBST_inorder(root->right);
}

void BST::clear(BSTNode *root){
    if(root==nullptr)return;
    clear(root->right);
    clear(root->left);

    delete root;
}

BST::~BST(){
    clear(root);
}