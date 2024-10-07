//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;

public class MaxSumwithoutAdjacents {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine().trim());
        while (tc-- > 0) {
            String[] inputLine;
            int n = Integer.parseInt(br.readLine().trim());
            int[] arr = new int[n];
            inputLine = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }

            int ans = new Solution().findMaxSum(arr, n);
            System.out.println(ans);
        }
    }
}
// } Driver Code Ends

// User function Template for Java

class Solution {
    int findMaxSum(int arr[], int n) {
        // code here

        if (n == 1)
            return arr[0];

        int i = 2;
        int res = 0;

        while (i < n) {
            arr[i] = arr[i] + arr[i - 2];
            arr[i - 1] = Math.max(arr[i - 1], arr[i - 2]);
            res = Math.max(arr[i], arr[i - 1]);
            i++;
        }

        return res;
    }
}
