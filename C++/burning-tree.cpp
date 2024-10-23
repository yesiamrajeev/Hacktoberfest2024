#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int burnTree(vector<vector<int>>& tree, int startNode, int n) {
    queue<int> q;
    vector<bool> visited(n, false);
    q.push(startNode);
    visited[startNode] = true;
    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        bool burned = false;
        for (int i = 0; i < size; i++) {
            int current = q.front();
            q.pop();
            for (int neighbor : tree[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    burned = true;
                }
            }
        }
        if (burned) time++; 
    }
    return time;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    
    vector<vector<int>> tree(n);
    int edges = n - 1;

    cout << "Enter edges in the tree (node1 node2): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int startNode;
    cout << "Enter starting node for the fire: ";
    cin >> startNode;

    int burnTime = burnTree(tree, startNode, n);
    cout << "Time taken for the entire tree to burn: " << burnTime << " seconds" << endl;

    return 0;
}
