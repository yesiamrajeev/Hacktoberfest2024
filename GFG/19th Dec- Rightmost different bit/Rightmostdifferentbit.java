//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Rightmostdifferentbit {

    public static void main(String[] args) throws NumberFormatException, IOException {
        Scanner sc = new Scanner(System.in);

        // input number of testcases
        int t = sc.nextInt();
        int m, n;
        while (t-- > 0) {

            Solution obj = new Solution();
            // input m and n
            m = sc.nextInt();
            n = sc.nextInt();
            System.out.println(obj.posOfRightMostDiffBit(m, n));
        }
    }
}

// } Driver Code Ends

// User function Template for Java

class Solution {
    // Function to find the first position with different bits.
    public static int posOfRightMostDiffBit(int m, int n) {
        // Your code here
        if (m == n)
            return -1;
        int pos = 1;
        int x = m ^ n;
        while ((x & 1) != 1) {
            pos++;
            x /= 2;
        }
        return pos;
    }
}
