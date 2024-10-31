/*
  PROBLEM
    Maximum Number of Moves in a Grid
   
    You are given a 0-indexed m x n matrix grid consisting of positive integers.

    You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

    From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
    Return the maximum number of moves that you can perform.

    LeetCode: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        // Get dimensions of the grid
        int ans = 0;  // Variable to store maximum moves possible
        int m = grid.size();     // Number of rows
        int n = grid[0].size();  // Number of columns
        
        // Initialize DP array with -1 to mark unvisited cells
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        // Try starting from each cell in the first column
        for(int i = 0; i < m; i++) {
            calculate(grid, dp, ans, 0, i, 0, m, n);
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
    
    int calculate(vector<vector<int>>& grid, vector<vector<int>>& dp, int& ans, 
                 int prev, int r, int c, int m, int n) {
        // Base cases:
        // 1. Out of bounds check
        // 2. Current value not strictly greater than previous value
        if(r < 0 || r >= m || c >= n || prev >= grid[r][c]) {
            return 0;
        }
        
        // If this cell has been computed before, return cached result
        if(dp[r][c] != -1) {
            return dp[r][c];
        }
        
        // Recursive calls for all three possible moves:
        // Up-right diagonal
        int u = calculate(grid, dp, ans, grid[r][c], r-1, c+1, m, n);
        // Right
        int f = calculate(grid, dp, ans, grid[r][c], r, c+1, m, n);
        // Down-right diagonal
        int d = calculate(grid, dp, ans, grid[r][c], r+1, c+1, m, n);
        
        // Store maximum of all possible moves from current cell
        dp[r][c] = max({u, f, d});
        // Update global maximum moves
        ans = max(ans, dp[r][c]);
        
        // Return moves from current cell (+1 for current move)
        return dp[r][c] + 1;
    }
};

int main() {
    // Test cases
    vector<vector<vector<int>>> testCases = {
        {
            {2,4,3,5},
            {5,4,9,3},
            {3,4,2,11},
            {10,9,13,15}
        },
        {
            {3,2,4},
            {2,1,9},
            {1,1,7}
        }
    };
    
    Solution solution;
    
    // Process each test case
    for(int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Grid:\n";
        
        // Print input grid
        for(const auto& row : testCases[i]) {
            for(int val : row) {
                cout << val << " ";
            }
            cout << "\n";
        }
        
        // Calculate and print result
        int result = solution.maxMoves(testCases[i]);
        cout << "Maximum possible moves: " << result << "\n\n";
    }
    
    return 0;
}
