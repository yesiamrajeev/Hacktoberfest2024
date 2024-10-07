//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

// } Driver Code Ends
//User function Template for Java

class Solution {
    long countWays(int n, int k) {
        long total = k, same = 0, diff = k, mod = (long) 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            same = diff;
            diff = (total % mod * (k - 1) % mod) % mod;
            total = (same + diff) % mod;
        }
        return total;
    }
}

// { Driver Code Starts.

// Driver class
class PaintingtheFence {

    // Driver code
    public static void main(String[] args) throws IOException {
        // Taking input using buffered reader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testcases = Integer.parseInt(br.readLine());
        // looping through all testcases
        while (testcases-- > 0) {
            // int n=Integer.parseInt(br.readLine());
            String line = br.readLine();
            String[] a2 = line.trim().split("\\s+");
            int n = Integer.parseInt(a2[0]);
            int k = Integer.parseInt(a2[1]);

            Solution ob = new Solution();
            // ArrayList<Long> ans=ob.smallestDifferenceTriplet(a,b,c,n);
            long ans = ob.countWays(n, k);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends