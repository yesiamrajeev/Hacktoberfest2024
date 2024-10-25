#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// T. c - O(n)
// n times reverse kar rahe hai, isliye
class Solution {
public:
    bool solve(TreeNode* root,long long int lowerBound,long long int upperBound){
        if(root == NULL){
            return true;
        }
        bool cond1 = (root->val > lowerBound);
        bool cond2= (root->val < upperBound);
        bool leftAns = solve(root->left, lowerBound,root->val);
        bool rightAns = solve(root->right,root->val,upperBound);

        if( cond1 && cond2 && leftAns && rightAns)
            return true;
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {
        
        long long int lowerBound = -2147483657;  // we have to increase the limit
        long long int upperBound = 2147483657;  // we have to increase the limit  
        bool ans = solve(root,lowerBound,upperBound);
       return ans;
    }
};

int main() {
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(4);

    
    root->right->right = new Node(6);
    root->right->left = new Node(3);

   // Creating an instance of the Solution class
    Solution solution;

    // Finding and printing the maximum path sum
    int maxPathSum = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << maxPathSum << endl;


    return 0;
