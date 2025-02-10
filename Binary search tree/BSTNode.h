//
// Created by Ahmed Hussein on 2/9/2025.
//

#ifndef DATA_STRUCTURE_BSTNODE_H
#define DATA_STRUCTURE_BSTNODE_H


class BSTNode {
private:
        int data;
        BSTNode *right;
        BSTNode *left;
public:
        BSTNode();
        BSTNode(int data);
        BSTNode(int data, BSTNode *right, BSTNode *left);
        int getData();
        void setData(int data);
        BSTNode *getRight();
        BSTNode *getLeft();
        void setRight(BSTNode *right);
        void setLeft(BSTNode *left);

        friend class BST;
};


#endif //DATA_STRUCTURE_BSTNODE_H
