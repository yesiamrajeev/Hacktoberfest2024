// Longest Common Subsequence(LCS)
//  Given two strings, S1 and S2, the task is to find the length of the Longest Common Subsequence.If there is no common subsequence, return 0. A subsequence is a string generated from the original string by deleting 0 or more characters and without changing the relative order of the remaining characters.For example, subsequences of “ABC” are “”, “A”, “B”, “C”, “AB”, “AC”, “BC” and “ABC”.In general a string of length n has 2n subsequences.

// LCS problem has great applications like diff                                                                                                                          utility(find the difference between two files) that we use in our day to day software development.
// Input : S1 = “ABC”, S2 = “ACD” Output : 2 Explanation : The longest subsequence which is present in both strings is “AC”.

//                                                         Input : S1 = “AGGTAB”,
//         S2 = “GXTXAYB”
//                  Output : 4 Explanation : The longest common subsequence is “GTAB”.

//                                           Input : S1 = “ABC”,
//         S2 = “CBA”
//             Output : 1 Explanation : There are three common subsequences of length 1, “A”, “B” and “C” and no common subsequence of length more than 1.

// A Naive recursive implementation of LCS problem
#include <bits/stdc++.h>
using namespace std;

// Returns length of LCS for S1[0..m-1], S2[0..n-1]
int lcs(string &S1, string &S2, int m, int n)
{
    // Base case: If either string is empty, the length of LCS is 0
    if (m == 0 || n == 0)
        return 0;

    // If the last characters of both substrings match
    if (S1[m - 1] == S2[n - 1])
        // Include this character in LCS and recur for remaining substrings
        return 1 + lcs(S1, S2, m - 1, n - 1);

    else
    {
        // If the last characters do not match
        // Recur for two cases:
        // 1. Exclude the last character of S1
        // 2. Exclude the last character of S2
        // Take the maximum of these two recursive calls
        return max(lcs(S1, S2, m, n - 1), lcs(S1, S2, m - 1, n));
    }
}

int main()
{
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int m = S1.size();
    int n = S2.size();

    cout << "Length of LCS is " << lcs(S1, S2, m, n);

    return 0;
}
