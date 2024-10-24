#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> q;

    // Push all initially rotten oranges into the queue
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
        }
    }

    int tm = 0;  // To track the time elapsed
    while (!q.empty()) {
        int k = q.front().first.first;
        int l = q.front().first.second;
        int t = q.front().second;
        tm = max(tm, t);
        q.pop();

        // Check all 4 possible directions (up, down, left, right)
        for (int i = -1; i <= 1; i++) {
            int j;
            for (i == 0 ? j = -1 : j = 0; i == 0 ? j <= 1 : j <= 0; j++) {
                int nrow = k + i;
                int ncol = l + j;
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
    }

    // Check if any fresh oranges are left
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] != 2 && grid[i][j] == 1) {
                return -1;
            }
        }
    }

    return tm;
}

int main() {
    // Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = orangesRotting(grid);
    cout << "Time taken for all oranges to rot: " << result << endl;
    return 0;
}
