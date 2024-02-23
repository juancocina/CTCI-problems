/*
    Fist Common Ancestor: Design an algorithm & write code to find the 
    first common ancestor of two nodes in a binary tree
*/

#include<iostream>

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

void printPostOrder(TreeNode* root) {
    if(root != nullptr) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        std::cout << root->data << " ";
    }
}

bool checkforNodes(TreeNode* root, TreeNode* target) {
    if(root == target) return true;

    if(checkforNodes(root->left, target)) return true;
    if(checkforNodes(root->right, target)) return true;

    return false;
}

// tOne = Target node one, tTwo = Target Node Two
TreeNode* firstCommonAncestor(TreeNode* root, TreeNode* tOne, TreeNode* tTwo) {
    // Condition 1: Nodes are present on the left side -> traverse left
    //both nodes present on the left side
    if(checkforNodes(root->left, tOne) && checkforNodes(root->left, tTwo)) {
        firstCommonAncestor(root->left, tOne, tTwo);
    }

    // Condition 2: Nodes are present on the right side -> traverse right
    //both nodes present on the right side
    else if(checkforNodes(root->right, tOne) && checkforNodes(root->right, tTwo)) {
        firstCommonAncestor(root->right, tOne, tTwo);
    }

    // Condition 3: Nodes are in different subtrees -> return root aka first common ancestor
    else if((checkforNodes(root->left, tOne) && checkforNodes(root->right, tTwo)) || 
    (checkforNodes(root->left, tTwo) && checkforNodes(root->right, tOne))) return root;

    // Condition 4: Nodes are not present in the tree at all -> return nullptr
    return nullptr;
}
// this algorithm returns root if
// (l && r == false) && (l && r == true)

int main() {
    TreeNode* one = new TreeNode(1);
    TreeNode* two = new TreeNode(2);
    TreeNode* three = new TreeNode(3);
    TreeNode* four = new TreeNode(4);
    TreeNode* five = new TreeNode(5);
    TreeNode* six = new TreeNode(6);
    TreeNode* seven = new TreeNode(7);
    TreeNode* eight = new TreeNode(8);

    four->left = three;
    four->right = five;
    three->left = seven;
    three->right = two;
    five->left = one;
    five->right = six;
    two->right = eight;

    // I gotta figure out a way to build trees without having to hard code them each time
    
    // For this example, four is our root
    // We are looking for the first common ancestor in Nodes Seven and Eight
    // We can use the same tree for a second exmaple which I will explain later

    TreeNode* result = firstCommonAncestor(four, seven, eight);
    if(result == nullptr) std::cout << "No First Common Ancestor found\n";
    else std::cout << "First Common Ancestor: " << result->data << std::endl;


    return 0;
}

/*
    As of writing this, my script is returning a false when it should be returning true
    when check for the presence of a node

    I guess its not idea to double up on recursive calls lol

    I took a peak at the books code, I'm on the right track, but theres some things that I'm missing

    There some really detailed things about the way they structure their algorithm that I'm lacking

    I need to think of how i'm using my returns and boolean checks.
*/