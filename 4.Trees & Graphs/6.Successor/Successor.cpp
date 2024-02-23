/*
    4.6 Successor: Write an algorithm to find the "next" node
    (i.e., in-order successor) of a given node in a binary search tree.

    You may asssume that each node has a link to its parent.
*/

#include <vector>
#include <iostream>
#include <algorithm>

class TreeNode {
    public:
        int data;
        TreeNode* parent;
        TreeNode* left;
        TreeNode* right;

        TreeNode (int d) {
            this->data = d;
            this->parent = nullptr;
            this->left = nullptr;
            this->right = nullptr;
        }
};

/*
    from the target node
    if there is a right node, return that
    else move up to the parent
    if the parent is less than, move up to the parent
    else
    if there is a right tree traverse it
    traverse lef tuntil right before the nullptr
    then return that node
*/

// my solution =================================================
TreeNode* Successor(TreeNode* root) {
    // if it can go right, go right then all the way
    if(root->right != nullptr){
        root = root->right;
        while(root->left != nullptr){
            root = root->left;
        }
        return root;
    } else { // travel up the parents while parent data is less than d
        int d = root->data;
        while(root != nullptr && root->data <=d) 
            root = root->parent;
    }
    if(root == nullptr) return nullptr;
    return root;
}
// ==================================================================

// the books solution ========================================
TreeNode* leftMostChild(TreeNode* root) {
    if(root == nullptr) return nullptr;

    while(root->left != nullptr) {
        root = root->left;
    }
    return;
}

TreeNode* getSuccessor(TreeNode* root) {
    if(root == nullptr) return nullptr;

    // if right child exists, traverse right and then all the way left
    if(root->right != nullptr){
        return leftMostChild(root->right);
    } else {
        TreeNode* q = root;
        TreeNode* x = q->parent;

        // Go up until we're on the left instead of the right
        while(x != nullptr && x->left != q) {
            q = x;
            x = x->parent;
        }
        return x;
    }
}
// ==============================================================

/*
    Time: O(<n)
    I'm not sure how to calculate the time on this solution

    Since we don't operate through all of the tree, nor is there a case where we traverse through all
    of the nodes, unless all nodes but one carry the same value, but then it wouldn't be a BST

    I do know that its less than N, where N is all the nodes in the tree

    Space: O(1)
*/