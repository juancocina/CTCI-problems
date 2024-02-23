/*
    4.2 Given a sorted (increasing order) array with unique integer elements,
    write an algorithm to create a binary search tree with minimal heights.
*/

#include<vector>
#include<iostream>
#include<algorithm> // for sort()

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            this->data = d;
        }
};

void printTree(Node* root) { // printing in pre-order traversal
    if(root == nullptr) return; // base case

    std::cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

// i have to declare this above or the function at line 33 won't recognize line 34 as valid
Node* buildMinTree(std::vector<int> v, int start, int end);

Node* buildMinTree(std::vector<int> v){
    return buildMinTree(v, 0, v.size()-1);
}

Node* buildMinTree(std::vector<int> v, int start, int end) {
    if(start > end) return nullptr;

    int midPoint = (start+end) /2;
    Node* n = new Node(v[midPoint]);

    n->left = buildMinTree(v, start, midPoint-1);
    n->right = buildMinTree(v, midPoint+1, end);
    return n;
}

int main() {
    std::vector<int> v {4, 2, 17, 1, 5, 23, 47, 20, 3, 14, 28};

    sort(v.begin(), v.end());

    for(auto a : v)
        std::cout << a << " ";
    
    std::cout << "\n";

    Node* head = buildMinTree(v);
    printTree(head);

    return 0;
}