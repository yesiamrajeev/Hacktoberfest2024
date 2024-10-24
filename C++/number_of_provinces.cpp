#include <bits/stdc++.h>
using namespace std;

/* This function performs a depth-first search (DFS) on the given node to explore all connected nodes (provinces). It marks the current node as visited and recursively explores its unvisited neighbors. */

/* Parameters: */
/*     node: The current node being visited. */
/*     arr: The adjacency matrix representing connections between provinces. */
/*     vis: A vector that tracks whether a node has been visited. */
/*     N: The total number of nodes (provinces). */

void dfs(int node, vector<vector<int>> arr, vector<bool> &vis, int N) {
  vis[node] = 1;
  for (int i = 0; i < N; i++) {
    if (arr[node][i] == 1 && node != i && vis[i] == 0) {
      dfs(i, arr, vis, N);
    }
  }
}

/* This function calculates the number of connected components (or provinces) in the graph represented by the adjacency matrix isConnected. It iterates through each node, performing a DFS if the node has not yet been visited. Each DFS call represents discovering a new province. */
/* Parameters: */

/*     isConnected: A reference to the adjacency matrix representing province connections. */

int findCircleNum(vector<vector<int>> &isConnected) {
  int N = isConnected.size();
  vector<bool> vis(N, 0);
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      dfs(i, isConnected, vis, N);
      count++;
    }
  }
  return count;
}

/* This is the driver function where the input isConnected matrix is initialized, and the findCircleNum function is called. It prints the number of provinces found. */

int main(){
    //Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout<<endl<<"Number of provinces: "<<findCircleNum(isConnected)<<endl;
    return 0;
}