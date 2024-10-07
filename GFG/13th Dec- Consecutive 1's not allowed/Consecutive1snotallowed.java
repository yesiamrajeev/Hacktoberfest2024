//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class Consecutive1snotallowed {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());

            long ans = new Solution().countStrings(n);

            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    long countStrings(int n) {
        // code here
        if (n == 1)
            return 2;
        long one = 1, zero = 1, total = one + zero;

        while (n-- > 1) {
            one = zero;
            zero = total;
            total = (one + zero) % 1000000007;
        }

        return total % 1000000007;
    }
}