//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

class Candy {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            Solution obj = new Solution();
            int ans = obj.minCandy(n, a);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends

// User function Template for Java

class Solution {
    static int minCandy(int n, int a[]) {
        int ans[] = new int[n];

        Arrays.fill(ans, 1);
        // fix right
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i + 1]) {
                ans[i] = ans[i + 1] + 1;
            }
        }
        // fix left
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                ans[i] = Math.max(ans[i], ans[i - 1] + 1);
            }
        }
        int sum = 0;
        for (int x : ans)
            sum += x;
        return sum;
    }
}