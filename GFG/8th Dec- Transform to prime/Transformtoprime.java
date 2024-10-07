
//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Transformtoprime {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcases = Integer.parseInt(br.readLine());
        while (testcases-- > 0) {
            int n = Integer.parseInt(br.readLine());
            String line1 = br.readLine();
            String[] a1 = line1.trim().split("\\s+");
            int a[] = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(a1[i]);
            }
            Solution ob = new Solution();
            int ans = ob.minNumber(a, n);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends
// User function Template for Java
// Solution as followes
class Solution {
    boolean[] primes;
    int MAX;

    Solution() {
        MAX = 1000001;
        primes = new boolean[MAX];
        Arrays.fill(primes, true);
        primes[1] = false;

        for (int i = 2; i * i < MAX; i++) {
            if (primes[i]) {
                for (int j = i * 2; j < MAX; j += i) {
                    primes[j] = false;
                }
            }
        }
    }

    public int minNumber(int arr[], int N) {
        int sum = 0;

        for (int i = 0; i < N; i++)
            sum += arr[i];

        int st = sum;

        while (primes[st] == false)
            st++;

        return st - sum;
    }
}