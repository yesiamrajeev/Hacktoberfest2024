                            
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

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
    // Function to perform vertical order traversal
    // and return a 2D vector of node values
    vector<vector<int>> findVertical(Node* root){
        // Map to store nodes based on
        // vertical and level information
        map<int, map<int, multiset<int>>> nodes;
        
        // Queue for BFS traversal, each
        // element is a pair containing node
        // and its vertical and level information
        queue<pair<Node*, pair<int, int>>> todo;
        
        // Push the root node with initial vertical
        // and level values (0, 0)
        todo.push({root, {0, 0}});
        
        // BFS traversal
        while(!todo.empty()){
            // Retrieve the node and its vertical
            // and level information from
            // the front of the queue
            auto p = todo.front();
            todo.pop();
            Node* temp = p.first;
            
            // Extract the vertical and level information
            // x -> vertical
            int x = p.second.first;  
            // y -> level
            int y = p.second.second; 
            
            // Insert the node value into the
            // corresponding vertical and level
            // in the map
            nodes[x][y].insert(temp->data);
            
            // Process left child
            if(temp->left){
                todo.push({
                    temp->left,
                    {
                        // Move left in
                        // terms of vertical
                        x-1, 
                        // Move down in
                        // terms of level
                        y+1  
                    }
                });
            }
            
            // Process right child
            if(temp->right){
                todo.push({
                    temp->right, 
                    {
                        // Move right in
                        // terms of vertical
                        x+1, 
                        // Move down in
                        // terms of level
                        y+1  
                    }
                });
            }
        }
        
        // Prepare the final result vector
        // by combining values from the map
        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                // Insert node values
                // into the column vector
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            // Add the column vector
            // to the final result
            ans.push_back(col);
        }
        return ans;
    }
};

// Helper function to
// print the result
void printResult(const vector<vector<int>>& result) {
    for(auto level: result){
        for(auto node: level){
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the Vertical traversal
    vector<vector<int>> verticalTraversal =
                    solution.findVertical(root);

    // Print the result
    cout << "Vertical Traversal: ";
    printResult(verticalTraversal);

    return 0;
}
                            
                        