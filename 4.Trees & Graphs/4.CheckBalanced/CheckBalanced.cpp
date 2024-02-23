/*
    4.4 Implement a function to check if a binary tree is balanced.

    For the purposes of this question, a balanced tree is defined 
    to be a tree such that the heights of the two subtress
    of any node never differ by more than one.

    I know that this problem, is going to involve moving 
    pointers around. I don't have a clue of how to do that at the moment.
    So it would be a good idea to watch a lecture on the idea
    behind balanacing a tree, if I can see how to do it, i can
    get a step closer to figuring it out.

*/

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int d){
            this->data = d;
            this->left = nullptr;
            this->right = nullptr;
        }
};

void postOrder(TreeNode* root) {
    if(root = nullptr) return;

    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << std::endl;
}

// my solution
int checkHeight(TreeNode* root) {
    if(root == nullptr) return -1;

    int a = checkHeight(root->left);
    int b = checkHeight(root->right);
    return std::max(a,b)+1;
}

bool checkBalanced(TreeNode* root) {
    if(root == nullptr) return true;
    int a = checkHeight(root->left);
    int b = checkHeight(root->right);
    if(abs(a-b) > 1) return false;
    return true;
} // had some issues with edge cases

// books solution 
int gHeight(TreeNode* root) {
    if(root == nullptr) return -1;

    int a = gHeight(root->left);
    if(a == INT_MIN) return INT_MIN;

    int b = gHeight(root->right);
    if(b == INT_MIN) return INT_MIN;

    if(abs(a-b) > 1 ) return INT_MIN;

    return std::max(a,b)+1; 
}

bool gBalance(TreeNode* root) {
    return gHeight(root) != INT_MIN;
}

int main() {
    /*
        I need to check at least these examples
        
        1. Balanced Tree -> returns true
        2. Unbalanced Tree -> returns false
        3. Empty Tree   -> returns true
    */

   TreeNode* ten = new TreeNode(10);
   TreeNode* five = new TreeNode(5);
   TreeNode* twelve = new TreeNode(12);
   TreeNode* twenty = new TreeNode(20);
   TreeNode* three = new TreeNode(3);
   TreeNode* nine = new TreeNode(9);
   TreeNode* eighteen = new TreeNode(18);
   TreeNode* seven = new TreeNode(7);

   // this example is unbalanced

   ten->left = five;
   ten->right = twenty;
   five->right = twelve;
   twenty->left = three;
   twenty->right = seven;
   three->left = nine;
   three->right = eighteen;

   //postOrder(ten);

   // if(checkBalanced(ten) == true) std::cout << "True" << std::endl;
   // else std::cout << "False" << std::endl;

   TreeNode* tOne = new TreeNode(1);
   TreeNode* tTwo = new TreeNode(2);
   TreeNode* tThree = new TreeNode(3);
   TreeNode* tFour = new TreeNode(4);
   TreeNode* tFive = new TreeNode(5);
   TreeNode* tSix = new TreeNode(6);
   TreeNode* tSeven = new TreeNode(7);

   tFour->left = tTwo;
   tFour->right = tSix;
   tTwo->left = tOne;
   tTwo->right = tThree;
   tSix->left = tFive;
   tSix->right = tSeven;

   postOrder(tFour);

   if(checkBalanced(tFour) == true) std::cout << "True" << std::endl;
   else std::cout << "false" << std::endl;

   return 0;
}