/*
    4.9 A binary serach tree was created by traversing through an array
    from left to right and inserting each element. Given a binary search tree
    with distinct elements, print all possible arrays that could have led to this tree

    This is a redo of the problem, I had a previous attempt, but did not understand the process
    behind the solution, so I'm trying it again with hopefully, a better grasp on the problem
    after looking at the book

    As I wrote in the other .cpp, this is a recursion problem. 
    Two main subproblems are
    1) traversing the tree and gathering infoprmation about the tree
    2) Weaving the lists together to create the final lists

    Since we know we have the root node, in the example given in the book, 50, 
    we just need to grab the left subtree and right subtree, then merge all 
    the possible combinations together.

    I'm going to start with weaving the lists, the gathering data 

    Trust and Focus 
*/

#include<vector>
#include<unordered_set>
#include<list>
#include<algorithm>
#include<cstdlib>
#include<iostream>

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

void TreeNode::createBST(int d){
    if(d <= this->data)
        if(this->left == nullptr)
            this->left = new TreeNode(d);
        else this->left->createBST(d);
    else 
        if(this->right == nullptr) 
            this->right = new TreeNode(d);
        else this->right->createBST(d);
}


void printLevelOrder(TreeNode* root) {
    if(root == nullptr) return;
    std::list<TreeNode*> q;

    q.push_back(root);

    while(!q.empty()){
        TreeNode* top = q.front();
        q.pop_front();
        std::cout << top->data << " ";
        if(top->left != nullptr) q.push_back(top->left);
        if(top->right != nullptr) q.push_back(top->right);
    }
    std::cout << std::endl;

    return;
}

// prototype
void weaveLists(std::list<int> first, std::list<int> second,
 std::vector<std::list<int>>& results, std::list<int> prefix);

// 1 gather the data through traversing the tree
std::vector<std::list<int>> genSequences(TreeNode* root){
    std::vector<std::list<int>> results;

    if(root == nullptr) {
        results.push_back({});
        return results;
    }

    std::list<int> prefix;
    prefix.push_back(root->data);

    // recurse left and right
    std::vector<std::list<int>> lSeq = genSequences(root->left);
    std::vector<std::list<int>> rSeq = genSequences(root->right);

    // pass info to weaveLists
    for(auto f : lSeq) {
        for(auto s : rSeq) {
            std::vector<std::list<int>> weaved;
            weaveLists(f, s, weaved, prefix);
            for(auto w : weaved) results.push_back(w);
        }
    } // i think this set of nested loops may make it O(N^3)

    return results;
}

void weaveLists(std::list<int> first, std::list<int> second,
 std::vector<std::list<int>>& results, std::list<int> prefix) {
    if(first.empty() || second.empty()) {
        std::list<int> res;
        // add first list
        for(auto a : first) res.push_back(a);
        // add second list 
        for(auto b : second) res.push_back(b);
        // push prefix to front 
        for(auto rIt = prefix.rbegin(); rIt != prefix.rend(); ++rIt) {
            res.push_front(*rIt);
        }
        results.push_back(res);
        return;
    }

    //resursive cases
    int firstClone = first.front();
    first.pop_front();
    prefix.push_back(firstClone);
    weaveLists(first, second, results, prefix);
    prefix.pop_back();
    first.push_front(firstClone);

    int secClone = second.front();
    second.pop_front();
    prefix.push_back(secClone);
    weaveLists(first, second, results, prefix);
    prefix.pop_back();
    second.push_front(secClone);
}

int main() {
    std::vector<int> nodes = {50, 20, 60, 10, 25, 70, 5, 15, 65, 80};

    TreeNode* bst = nullptr;
    for(auto a : nodes) {
        if(bst == nullptr) bst = new TreeNode(a);
        else bst->createBST(a);
    }

    printLevelOrder(bst);

    // call solution function after this
    std::vector<std::list<int>> ans = genSequences(bst);

    for(auto a : ans) {
        for(auto b : a) {
            std::cout << b << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}