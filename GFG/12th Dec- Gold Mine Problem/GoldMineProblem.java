//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GoldMineProblem {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            String inline[] = in.readLine().trim().split("\\s+");
            int n = Integer.parseInt(inline[0]);
            int m = Integer.parseInt(inline[1]);
            String inline1[] = in.readLine().trim().split("\\s+");
            int M[][] = new int[n][m];
            for (int i = 0; i < n * m; i++) {
                M[i / m][i % m] = Integer.parseInt(inline1[i]);
            }

            Solution ob = new Solution();
            System.out.println(ob.maxGold(n, m, M));
        }
    }
}
// } Driver Code Ends

// solution from here
class Solution {
    static int maxGold(int n, int m, int M[][]) {
        // code here
        int arr[][] = new int[n][m];

        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                if (j == m - 1)
                    arr[i][j] = M[i][j];
                else {
                    int ud = (i - 1) >= 0 ? arr[i - 1][j + 1] : 0;
                    int r = Math.max(ud, arr[i][j + 1]);
                    int ld = (i + 1) < n ? arr[i + 1][j + 1] : 0;
                    int max = Math.max(r, ld);

                    arr[i][j] = max + M[i][j];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            res = Math.max(res, arr[i][0]);

        return res;
    }
}