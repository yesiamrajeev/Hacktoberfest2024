                            
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to check if two
    // binary trees are identical
    bool isIdentical(Node* node1, Node* node2){
        // If both nodes are NULL,
        // they are identical
        if(node1 == NULL && node2 == NULL){
            return true;
        }
        // If only one of the nodes is
        // NULL, they are not identical
        if( node1== NULL || node2==NULL){
            return false;
        }
        // Check if the current nodes
        // have the same data value
        // and recursively check their
        // left and right subtrees
        return ((node1->data == node2->data)
            && isIdentical(node1->left, node2->left)
                && isIdentical(node1->right, node2->right));
    }
};


int main() {
    // Node1
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    // Node2
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    Solution solution;
    
    if (solution.isIdentical(root1, root2)) {
        cout << "The binary trees are identical." << endl;
    } else {
        cout << "The binary trees are not identical." << endl;
    }

    return 0;
}
                            
                        