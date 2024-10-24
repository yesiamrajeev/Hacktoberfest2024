import java.util.Arrays;

public class FibonacciWithMultipleApproaches {
    public static void main(String[] args) {
        System.out.println(fibonacciRecursive(50));
    }

    public static long fibonacciRecursive(long n) { // with time complexity ≈ O(2^n) and space complexity = O(n)
        if (n == 0 || n == 1) {
            return n;
        }
        return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
    }

    public static long fibonacciDP(int n) { // with time complexity = O(n) and space complexity = O(n) + O(n) [Recursive stack space i.e. auxiliary space]
        long[] dp = new long[n+1];
        Arrays.fill(dp, -1);
        return fibonacciDP(dp, n);
    }

    private static long fibonacciDP(long[] dp, int n) {
        if (n == 0 || n == 1) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = fibonacciDP(dp, n-1) + fibonacciDP(dp, n-2);
    }

    public static long fibonacciTabulation1(int n) { // with time complexity = O(n) and space complexity = O(n)
        long[] dp = new long[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    public static long fibonacciTabulation2(int n) { // with time complexity = O(n) and space complexity = O(1)
        long prev1 = 0;
        long prev2 = 1;
        for (int i = 2; i <= n; i++) {
            long curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }
}
