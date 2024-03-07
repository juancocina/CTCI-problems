/*
    4.10 Check Subtree: T1 and T2 are two very larger binary trees, with T1 being
    much bigger than T2. Create an algorithm to determine if T2 is a subtree of T1.

    A tree T2 is a subtree of T1 if there exists a node in T1 such that 
    the subtree of n is identical to T2.
    That is, if you cut off the tree at node, the two trees would be identical.

    Before I start coding up a solution, there are two approaches here
    One, traverse both tress, gather a string, and a check if one is a substring of the other

    Two, use recursion, find a node T1 that matches out T2, then perform a type of 
    traversal on both trees, if there is a node that doesn't match, then the T2
    is not a subtree of T1.
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int d) {
            this->data = d;
            this->left = nullptr;
            this->right = nullptr;
        }

        void createBST(int d);
};

void TreeNode::createBST(int d) {
    if(d <= this->data) {
        if(this->left == nullptr) this->left = new TreeNode(d);
        else this->left->createBST(d);
    } else {
        if(this->right == nullptr) this->right = new TreeNode(d);
        else this->right->createBST(d);
    }
}

TreeNode* findNode(TreeNode* root, int target) {
    if(root != nullptr) {
        if(root->data == target) return root;
        findNode(root->left, target);
        findNode(root->right, target);
    }
    return nullptr;
}

// the reason i'm using an '&' to dictate nullptr is to counteract
// trees with duplicate values but with different structures
void nodesToString(TreeNode* root, std::string& s) {
    if(root == nullptr) { s+= "&"; return; }
    else {
        s+= "'" + std::to_string(root->data) + "'";
        nodesToString(root->left, s);
        nodesToString(root->right, s);
    }
    return;
}

bool checkST(TreeNode* t1, TreeNode* t2) {
    if(t1 == nullptr || t2 == nullptr) return false;
    std::string s1; nodesToString(t1, s1);

    std::string s2; nodesToString(t2, s2);
    if(s1.find(s2) != std::string::npos) return true;

    return false;
} // end of first approach

// second approach using recursion
bool matchTree(TreeNode* t1, TreeNode* t2) {
    // base cases that return true or false
    if(t1 == nullptr && t2 == nullptr) // both trees have reached an endpoint; match!
        return true;
    else if(t1 == nullptr || t2 == nullptr) // one tree has reached an endpoint; no match
        return false;
    else if(t1->data != t2->data) // data does not match; no match
        return false;

    // recurse left & right
    return matchTree(t1->left, t2->left) && matchTree(t1->right, t2->right);
}

bool isSubtree(TreeNode* t1, TreeNode* t2) {
    // base cases that return either true or false
    if(t1 == nullptr) return false; // no big tree exists
    else if(t1->data == t2->data && matchTree(t1, t2))
        return false;

    // recurse left || right
    return isSubtree(t1->left, t2) || isSubtree(t1->right, t2); 
}

bool checkSubtree(TreeNode* root, TreeNode* subTree) {
    if(subTree == nullptr) return true;
    return isSubtree(root, subTree);
}

int main() {
    // example from leetcode
    // t1, one is the root
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    one->left = two;
    one->right = three;

    // t2
    TreeNode* oneT2 = new TreeNode(1);
    oneT2->left = new TreeNode(2);
    
    if(checkST(one, oneT2)) std::cout << "True\n";
    else std::cout << "False\n";

    return 0;
}

/*
    For the purely recursive approach -
        Time complexity: O(N * kM)
        Where N is the number of nodes in the first tree and 
        kM is the number of times the second trees root appears in the first tree

        Space Complexity: O(n * m)
        Where n is the number of nodes in tree 1 and m is the number of nodes is m
*/