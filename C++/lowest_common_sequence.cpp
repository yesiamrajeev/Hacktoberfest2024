// This program implements two versions of the Longest Common Subsequence (LCS) algorithm:
    //Recursive LCS with memoization using the function LCS_recursion.
    //Iterative LCS using dynamic programming (DP) with the function LCS.
#include <bits/stdc++.h>
using namespace std;

// This is a recursive function that calculates the LCS length using memoization.
// It checks whether the current characters of both strings (text1[s1] and text2[s2]) are equal.

    //If they match, it adds 1 to the result and calls itself recursively for the next characters.
    //If they don't match, it takes the maximum value between moving to the next character in either text1 or text2.

// It stores previously computed results in the dp table (memoization) to avoid redundant calculations.

int LCS_recursion(long int s1, long int s2, string text1, string text2,
                  vector<vector<int>> &dp) {
  if (s1 < 0 || s2 < 0)
    return 0;
  if (dp[s1][s2] != -1)
    return dp[s1][s2];
  if (text1[s1] == text2[s2])
    return dp[s1][s2] = 1 + LCS_recursion(s1 - 1, s2 - 1, text1, text2, dp);
  return dp[s1][s2] = max(LCS_recursion(s1 - 1, s2, text1, text2, dp),
                          LCS_recursion(s1, s2 - 1, text1, text2, dp));
}

// This is the iterative (bottom-up) version of LCS using dynamic programming.
// It initializes a DP table dp[m+1][n+1], where m is the length of text1 and n is the length of text2.
// It iterates through both strings:

    //If characters match (text1[i-1] == text2[j-1]), it adds 1 to the diagonal value in the table.
    //If characters don't match, it takes the maximum value from the left or above in the DP table.

// The result (dp[m][n]) holds the length of the longest common subsequence.

int LCS_Dynamic(string text1, string text2) {
  int m = text1.length();
  int n = text2.length();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (text1[i - 1] == text2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[m][n];
}

// Two strings text1 = "abcde" and text2 = "ace" are provided.
// The LCS function is called to compute the length of the longest common subsequence between the two strings.
// The result is printed.