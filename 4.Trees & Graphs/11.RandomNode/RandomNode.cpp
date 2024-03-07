/*
    4.11 Random Node;
    You are implementing a binary search tree class from scratch
    in addition to insert, find, delete, and has a method getRandomNode().
    Which returns a random node from the tree. All nodes should be equally likely to
    be chosen. Design & Implement an algorithm for the getRandomNode, & explain how 
    you would implement the rest of the methods.

    This is a redo, I'm going to start by focusing on the classes that will be 
    the foundation for the solutions.

    ===
    Implemented insert, find, and getRandom, not doing delete because I don't know 
    how to restructure a tree.

    Below is the method I chose to implement, because it was the way I understood the problem.
    I will be studying the books solution as well, in attempts to understand their approach.
*/

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<random>

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;

        TreeNode(int d) {
            this->data = d;
            this->left = nullptr;
            this->right = nullptr;
            this->parent = nullptr;
        }

        void insertData(int d);
        TreeNode* findNode(int d);
        TreeNode* inOrderFind(TreeNode* root, int& d);
        void printTree(TreeNode* root);
};

void TreeNode::insertData(int d) {
    if(d <= this->data) {
        if(this->left == nullptr) {
            this->left = new TreeNode(d);
            this->left->parent = this;
        } 
        else this->left->insertData(d);
    } else {
        if(this->right == nullptr) {
            this->right = new TreeNode(d);
            this->right->parent = this;
        }
        else this->right->insertData(d);
    }
}

TreeNode* TreeNode::findNode(int d) {
    if(this->data == d) return this;
    else if(d <= this->data)
        return this->left != nullptr ? this->left->findNode(d) : nullptr;
    else if(d > this->data)
        return this->right != nullptr ? this->right->findNode(d) : nullptr;

    return nullptr;
}

// solution function
TreeNode* TreeNode::inOrderFind(TreeNode* root, int& d) {
    if(root == nullptr) return nullptr;
    
    TreeNode* left = root->inOrderFind(root->left, d);
    if(left != nullptr) return left;

    if(d == 0) return root;
    d -= 1;

    return root->inOrderFind(root->right, d);
}

void TreeNode::printTree(TreeNode* root) {
    if(root != nullptr) {
        root->printTree(root->left);
        std::cout << root->data << " ";
        root->printTree(root->right);
    }
}

// ====================================================
class Tree {
    private:
        TreeNode* root = nullptr;
        int size = 0;

    public:
        void insertNode(int d);
        TreeNode* find(int d);
        TreeNode* getRandomNode();
        void print();

        // functions for rng
        int randomSeed();
};

// insert Node
void Tree::insertNode(int d) {
    if(root == nullptr) root = new TreeNode(d);
    else root->insertData(d);
    size++;
    return;
}

// find Node 
TreeNode* Tree::find(int d) {
    if(root->data == d) return root;
    return root->findNode(d);
}

// return random Node
TreeNode* Tree::getRandomNode() {
    int rng = randomSeed();

    // call TreeNodes inOrderFind
    std::cout << "\nRandom Number: " << rng << "n";
    return root->inOrderFind(root, rng);
}

// helper functions for getRandomNode
int Tree::randomSeed() {
    std::random_device seed_gen;
    std::default_random_engine rng(seed_gen());
    std::cout << "\nSize" << this->size;
    std::uniform_int_distribution<int> distribution(0, this->size-1);
    return distribution(rng);
}

// print
void Tree::print() {
    root->printTree(root);
}

//===================================================

int main() {
    Tree bst;

    std::vector<int> v = { 20, 10, 30, 5, 15, 17, 3, 7 };
    for(auto a : v) bst.insertNode(a);
    bst.print();
    std::cout << "\n";

    std::cout << "getRandomNumber operated from 0 through N, where N is the amount of nodes in a tree";
    TreeNode* rando = bst.getRandomNode();
    if(rando == nullptr) std::cout << "Random Node: nullptr\n";
    else std::cout << "Random Node: " << rando->data << "\n";

    rando = bst.getRandomNode();
    if(rando == nullptr) std::cout << "Random Node: nullptr\n";
    else std::cout << "Random Node: " << rando->data << "\n";

    rando = bst.getRandomNode();
    if(rando == nullptr) std::cout << "Random Node: nullptr\n";
    else std::cout << "Random Node: " << rando->data << "\n";

    rando = bst.getRandomNode();
    if(rando == nullptr) std::cout << "Random Node: nullptr\n";
    else std::cout << "Random Node: " << rando->data << "\n";

    return 0;
}

/*
    So, not counting the STD random number generator method that I used,
    I'm going to try and answer for the time and space complexity 

    Time: O(N) worst case, where the traversal is through all the odes
    Space: O(V+E), because of the tree. Thankfully, I'm not storing all the nodes and do not
    have to reacreate an array of any sort.

    This is somewhat an expansion and optimization of Option 3 in the book.
*/