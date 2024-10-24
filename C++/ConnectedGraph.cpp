#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isConnected(vector<vector<int>>& adjMat, int v) {
    vector<bool> visited(v, false);
    queue<int> q;

    // Start BFS traversal from vertex 0
    q.push(0);
    visited[0] = true;

    // initiate BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Visit all adjacent vertices of current vertex
        for (int i = 0; i < v; i++) {
            if (adjMat[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    // Check if all vertices are visited
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            return false;
    }
    return true;
}

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;

    vector<vector<int>> adjMat(v, vector<int>(v));

    // Input adjacency matrix
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> adjMat[i][j];
        }
    }

    // Check if the graph is connected
    if (isConnected(adjMat, v)) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
