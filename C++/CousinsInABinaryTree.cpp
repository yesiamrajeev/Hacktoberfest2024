/*
Given the root of a binary tree with unique values and the values of two different nodes of the tree
x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or 
false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.
Note that in a binary tree, the root node is at the depth 0, and children of each depth k node 
are at the depth k + 1.
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    // Constructor for creating a node with no children
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    // Constructor for creating a node with a given value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // Constructor for creating a node with a given value and children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int parx, pary; // Parents of nodes x and y
    int levx, levy; // Levels (depths) of nodes x and y

    // Depth-first search to find the parents and levels of x and y
    void dfs(TreeNode* root, int x, int y, int lev) {
        if (root == nullptr) return; // Base case: if the node is null

        // Check if the left or right child is x and record parent and level
        if ((root->left != nullptr && root->left->val == x) || (root->right != nullptr && root->right->val == x)) {
            parx = root->val;
            levx = lev + 1;
        }
        // Check if the left or right child is y and record parent and level
        if ((root->left != nullptr && root->left->val == y) || (root->right != nullptr && root->right->val == y)) {
            pary = root->val;
            levy = lev + 1;
        }

        // Recur for left and right children
        dfs(root->left, x, y, lev + 1);
        dfs(root->right, x, y, lev + 1);
    }

    // Function to check if x and y are cousins
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, x, y, 0); // Start DFS from root at level 0
        // Nodes are cousins if they have the same level but different parents
        return (levx == levy) && (parx != pary);
    }
};

// Helper function to create a binary tree with elements from 1 to 10
TreeNode* createBinaryTree() {
    // Creating nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    
    return root; // Return the root of the created tree
}

int main() {
    // Create the binary tree
    TreeNode* root = createBinaryTree();
    
    // Create an instance of Solution
    Solution solution;
    
    // Check if nodes with values 4 and 5 are cousins
    bool result1 = solution.isCousins(root, 4, 5);
    cout << "Are 4 and 5 cousins? " << (result1 ? "Yes" : "No") << endl; // Expected: No
    
    // Check if nodes with values 8 and 9 are cousins
    bool result2 = solution.isCousins(root, 8, 9);
    cout << "Are 8 and 9 cousins? " << (result2 ? "Yes" : "No") << endl; // Expected: No
    
    // Check if nodes with values 6 and 7 are cousins
    bool result3 = solution.isCousins(root, 6, 7);
    cout << "Are 6 and 7 cousins? " << (result3 ? "Yes" : "No") << endl; // Expected: Yes
    
    // Check if nodes with values 9 and 10 are cousins
    bool result4 = solution.isCousins(root, 9, 10);
    cout << "Are 9 and 10 cousins? " << (result4 ? "Yes" : "No") << endl; // Expected: Yes

    return 0; // Return success
}
