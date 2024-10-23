public class MaximumSubArray {

    // Method to find the maximum sum of a subarray using brute force
    public static int maxSubArrayBruteForce(int[] nums) {
        int maxSum = Integer.MIN_VALUE; // Initialize maxSum to the smallest integer

        // Check all possible subarrays
        for (int i = 0; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                int currentSum = 0; // Sum of the current subarray
                for (int k = i; k <= j; k++) {
                    currentSum += nums[k]; // Sum the elements of the subarray
                }
                maxSum = Math.max(maxSum, currentSum); // Update maxSum if currentSum is larger
            }
        }

        return maxSum; // Return the maximum sum found
    }

    public static void main(String[] args) {
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input
        int maxSum = maxSubArrayBruteForce(nums); // Calculate maximum subarray sum
        System.out.println("Maximum Subarray Sum (Brute Force): " + maxSum); // Output result
    }
}
