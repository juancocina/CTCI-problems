/*
    4.3 Given a binary tree, design an algorithm which creates a linked list
    of all the nodes at each depth(eg if you have a tree with depth D, you'll 
    have D linked lists)

    I've got a good idea of how to traverse the tree,
    a modified version of BFS, but there comes a point where I need to create
    a linked lists for each level
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

//==================
// section for treeNode

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

// section for listNode
class ListNode {
    public:
        TreeNode* data;
        ListNode* next;

        ListNode(TreeNode* r){
            this->data = r;
            this->next = nullptr;
        }
};

// prototype function
void appendToList(ListNode** head, TreeNode* r);
/////////////////

void printTree(TreeNode* root) {
    if(root == nullptr) return; // base case

    std::cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
    return;
}

// reusing assets from previous problem to build trees
// i have to declare this above or the function won't be recognized as valid
TreeNode* buildMinTree(std::vector<int> v, int start, int end);

TreeNode* buildMinTree(std::vector<int> v) {
    return buildMinTree(v, 0, v.size()-1);
}

TreeNode* buildMinTree(std::vector<int> v, int start, int end) {
    if (start > end) return nullptr;

    int midPoint = (start+end) / 2;
    TreeNode* n = new TreeNode(v[midPoint]);

    n->left = buildMinTree(v, start, midPoint-1);
    n->right = buildMinTree(v, midPoint+1, end);
    return n;
}

// i'm going to assume all nodes in tree are unique
std::vector<ListNode*> listOfDepths(TreeNode* root) {
    std::vector<ListNode*> lists;
    std::unordered_set<int> visited;
    std::queue<TreeNode*> q;

    if(root = nullptr) return lists;
    visited.insert(root->data);
    q.push(root);

    while(!q.empty()) {
        int qSize = q.size();
        ListNode* n = nullptr;

        for(int i = 0; i < qSize; i++){
            TreeNode* r = q.front();
            appendToList(&n, r);
            q.pop();
            if((r != nullptr && r->left != nullptr) && !visited.count(r->left->data)) {
                visited.insert(r->left->data);
                q.push(r->left);
            }
            if((r != nullptr && r->right != nullptr) && !visited.count(r->right->data)) {
                visited.insert(r->right->data);
                q.push(r->right);
            }
        }
        lists.push_back(n);
    }
    return lists;
}

void appendToList(ListNode** head, TreeNode* r) {
    ListNode* n = new ListNode(r);
    if(*head == nullptr){
        *head = n;
        return;
    }

    ListNode* cur = *head;
    while(cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = n;
    return;
}

//////////////////////////////////////

int main() {
    std::vector<int> v {4, 2, 17, 1, 5, 23, 47, 20, 3, 14, 28};

    sort(v.begin(), v.end());

    for(auto a: v){
        std::cout << a << " ";
    }

    std::cout << "\n";

    TreeNode* head = buildMinTree(v);
    printTree(head);
    std::cout << std::endl;
    std::vector<ListNode*> listVector = listOfDepths(head);
    for(int i = 0; i < listVector.size(); i++){
        ListNode* cur = listVector[i];
        while(cur != nullptr){
            std::cout << cur->data->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

    return 0;
}


