/*
    4.12 Paths With Sum: You are given a binay tree in which each node contains
    an interger value (which might be positive or negative). Design an algorithm
    to count the number of paths that sun to a given value. The path does not
    need to start or end at the root or a leaf, but it must go downward 
    (traveling only from parent nodes to children nodes).

    I'm redoing this problem do to some issues with my understanding of the problem.
    My initial solution (which i might still upload) does not take into account cases
    where a path does not start at the root.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

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

// solution function
int pathsWithSum(TreeNode* root, int targetSum, int runningSum, int& paths, 
std::unordered_map<int,int> hTable) {
    if(root == nullptr) return paths;
    runningSum += root->data;
    hTable[runningSum]++;
    int xSum = runningSum - targetSum;
    if(hTable.count(xSum)) paths += hTable[xSum];
    if(runningSum == targetSum) paths++;

    paths = pathsWithSum(root->left, targetSum, runningSum, paths, hTable);
    paths = pathsWithSum(root->right, targetSum, runningSum, paths, hTable);

    //hTable[runningSum]--;

    return paths;
}

int pathsWithSum(TreeNode* root, int targetSum) {
    if(root == nullptr) return 0;
    std::unordered_map<int,int> hTable;
    int paths = 0;
    return pathsWithSum(root, targetSum, 0, paths, hTable);
}

// ==================

// Books solution
void incrementHashTable(std::unordered_map<int,int>& hTable, int key, int delta) {
    int newCount;
    if(hTable.count(key)) newCount = hTable[key] * delta;
    else newCount = 0 + delta;

    if(newCount == 0) hTable.erase(key);
    else hTable[key] = newCount;
}

int countPathsWithSum(TreeNode* root, int targetSum, int runningSum, std::unordered_map<int,int> pathCount) {
    if(root == nullptr) return 0; // base case

    // Count paths with sum ending at the current node
    runningSum += root->data;
    int sum = runningSum - targetSum;
    int totalPaths;
    if(pathCount.count(sum)) totalPaths = pathCount[sum];
    else totalPaths = 0;

    // if running sum equals targetSum, then one additional path starts at root
    if(runningSum == targetSum) totalPaths++;

    // increment pathCount, recurse, then decrement pathCount
    incrementHashTable(pathCount, runningSum, 1);
    totalPaths += countPathsWithSum(root->left, targetSum, runningSum, pathCount);
    totalPaths += countPathsWithSum(root->right, targetSum, runningSum, pathCount);
    incrementHashTable(pathCount, runningSum, -1);
    
    return totalPaths;
}

int countPathsWithSum(TreeNode* root, int targetSum) {
    return countPathsWithSum(root, targetSum, 0, {});
}

// ==================

int main() {
    // going to manually create another tree wiht positive and negative integers
    TreeNode* ten = new TreeNode(10);
    TreeNode* five = new TreeNode(5);
    TreeNode* nThree = new TreeNode(-3);
    TreeNode* three = new TreeNode(3);
    TreeNode* two = new TreeNode(2);
    TreeNode* eleven = new TreeNode(11);
    TreeNode* threeSqr = new TreeNode(3);
    TreeNode* nTwo = new TreeNode(-2);
    TreeNode* one = new TreeNode(1);

    ten->left = five;
    ten->right = nThree;
    five->left = three;
    five->right = two;
    nThree->right = eleven;
    three->left = threeSqr;
    three->right = nTwo;
    two->right = one;

    int results = pathsWithSum(ten, 8);
    std::cout << "Results from my code: " << results << std::endl;

    results = countPathsWithSum(ten, 8);
    std::cout << "Results from books code: " << results << std::endl;

    return 0;
}

/*
    The solution above is from my understanding of steps 1-6 given on page 275.

    It works for the example given on page 272.

    --
    After taking a look at thier code, I can spot a few differences
    1) I pass in my paths variable by reference, they have it as a local variable
    2) They use a seperate function to increment and decrement the hash table
    3) The way they handle null nodes is by returning 0, I return paths

    I can make a guess and say that their version might produce less errors in edge cases.
    Especially since I'm not sure how line 41 and 42 might react.

    I'm going to take the time to translate their solution to C++
    I think its neat that you're able to create a hashtable in the parameters and pass that 
    along through recursion
*/