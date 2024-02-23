/*
    4.5 ValidateBST: Implement a function to check if a bianry tree is a 
    binary search tree

    We just need to check if it is a binary search tree

    The conditions for a BST are left < root < right
    and the entire left side has to be smaller than the root
    the entire right side has to be larger than the root
*/

#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>

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
};

void inOrder(TreeNode* root) {
    if(root == nullptr) return;

    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
}

void validateBST(std::stack<int>& s, TreeNode* root){
    if(root != nullptr){
        validateBST(s, root->left);

        s.push(root->data);

        validateBST(s, root->right);
    }
}

bool validateBST(TreeNode* root) {
    std::stack<int> st;
    validateBST(st, root);
    
    while(!st.empty()) {
        int a = st.top();
        st.pop();
        if(!st.empty() && a < st.top()) return false;
    }
    return true;
}

// books solution
bool checkBST(TreeNode* root, int min, int max){
    if(root == nullptr) return true;

    //if data is out of bounds, return false
    if(root->data <= min || root->data > max) return false;

    /*
        To check the left side of the tree, our max is our root
        To check the right side of the tree, our min is our root
    */
    if(!checkBST(root->left, min, root->data) || !checkBST(root->right, root->data, max))
        return false;
    
    return true;
}
bool checkBST(TreeNode* root) {
    // use INT_MIN & INT_MAX to set initial values
    return checkBST(root, INT_MIN, INT_MAX);
}

int main() {
    TreeNode* eight = new TreeNode(8);
    TreeNode* four = new TreeNode(4);
    TreeNode* ten = new TreeNode(10);
    TreeNode* two = new TreeNode(2);
    TreeNode* twelve = new TreeNode(12);
    TreeNode* twenty = new TreeNode(20);

    eight->left = four;
    eight->right = ten;
    four->left = two;
    four->right = twelve;
    ten->right = twenty;

    inOrder(eight); std::cout << std::endl;

    if(validateBST(eight)) std::cout << "True" << std::endl;
    else std::cout << "false" << std::endl;
    std::cout << std::endl;

    if(checkBST(eight)) std::cout << "CheckBST: True" << std::endl;
    else std::cout << "checkBST: false" << std::endl;
    
    return 0;
}