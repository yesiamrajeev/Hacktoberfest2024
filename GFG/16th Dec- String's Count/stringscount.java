
//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());

        while (t > 0) {
            long n = Integer.parseInt(br.readLine().trim());
            Solution ob = new Solution();
            System.out.println(ob.countStr(n));
            t--;
        }
    }
}
// } Driver Code Ends

class Solution {
    static long countStr(long n) {

        return 1 + 2 * n + n * (n - 1) / 2 + n * (n - 1) + n * (n - 1) * (n - 2) / 2;
    }
}