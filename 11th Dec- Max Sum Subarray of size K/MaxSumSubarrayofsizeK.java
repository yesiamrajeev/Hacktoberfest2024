
//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class MaxSumSubarrayofsizeK {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {

            int N = sc.nextInt();
            int K = sc.nextInt();
            ArrayList<Integer> Arr = new ArrayList<Integer>(N);

            // Appending new elements at
            // the end of the list
            for (int i = 0; i < N; i++) {
                int x = sc.nextInt();
                Arr.add(x);
            }

            Solution ob = new Solution();
            System.out.println(ob.maximumSumSubarray(K, Arr, N));
        }
    }
}

// } Driver Code Ends
// solution starts
class Solution {
    static long maximumSumSubarray(int K, ArrayList<Integer> Arr, int N) {
        long curr_sum = 0, ans = Integer.MIN_VALUE;

        for (int i = 0; i < K; i++)
            curr_sum += Arr.get(i);

        ans = Math.max(ans, curr_sum);
        int j = 0;
        for (int i = K; i < N; i++) {
            curr_sum -= Arr.get(j++); // remove first ele of window
            curr_sum += Arr.get(i); // add new ele.
            ans = Math.max(ans, curr_sum);
        }
        return ans;
    }
};