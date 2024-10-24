#include <bits/stdc++.h>
#define N 10

// Print the Hosoya triangle of height n.
void printHosoya(int n)
{
    int dp[N][N];
    memset(dp, 0, sizeof(dp));

    // base case.
    dp[0][0] = dp[1][0] = dp[1][1] = 1;

    // For each row.
    for (int i = 2; i < n; i++) {

        // for each column;
        for (int j = 0; j < n; j++) {

            // recursive steps.
            if (i > j)
                dp[i][j] = dp[i - 1][j] + dp[i - 2][j];

            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 2][j - 2];
        }
    }

    // printing the solution
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            std :: cout << dp[i][j] << " ";       

        std :: cout << std :: endl;
    }
}

int main()
{
    int n = 10;
    printHosoya(n);
    return 0;
}