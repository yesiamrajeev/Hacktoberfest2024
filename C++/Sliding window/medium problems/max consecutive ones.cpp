class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;   // Initialize left pointer
        int right = 0;  // Initialize right pointer
        int maxOnesLength = 0;  // Variable to store the maximum length of subarray

        // Iterate through the array with the right pointer
        while (right < nums.size()) {
            // If we encounter a 0, decrement k (the flip count)
            if (nums[right] == 0) {
                --k;
            }

            // Move the right pointer to the next element
            ++right;

            // If k is negative, it means we've flipped more 0s than allowed
            while (k < 0) {
                // If the left element is 0, we increment k 
                // since we are moving past the flipped zero
                if (nums[left] == 0) {
                    ++k;
                }
                // Move the left pointer to the right, effectively shrinking the window
                ++left;
            }

            // Update maxOnesLength if the current window is larger
            maxOnesLength = max(maxOnesLength, right - left);
        }
      
        // Return the maximum length of the subarray
        return maxOnesLength;
    }
};