//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class SmithNumber {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(read.readLine());

            Solution ob = new Solution();
            System.out.println(ob.smithNum(n));
        }
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    static int smithNum(int n) {
        // code here
        int s1 = Sum(n), s2 = getSum(n);
        // System.out.println(s1);
        if (s1 == -1) // prime
            return 0;

        return (s1 == s2) ? 1 : 0;

    }

    static int Sum(int n) {
        int curr = n;
        int sum = 0;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                sum += getSum(i);
                n /= i;
            }
        }
        if (n > 1)
            sum += getSum(n);

        if (n == curr) // prime number eg 7
            return -1;

        return sum;
    }

    static int getSum(int n) {
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }

}