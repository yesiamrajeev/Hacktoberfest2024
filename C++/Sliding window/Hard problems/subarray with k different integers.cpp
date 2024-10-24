#include <vector>
#include <cstring>

class Solution {
public:
    // Function to calculate the number of subarrays with exactly k distinct elements
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        vector<int> subarrayStartsWithK = countSubarraysStartingPoint(nums, k);
        vector<int> subarrayStartsWithKMinusOne = countSubarraysStartingPoint(nums, k - 1);
        int totalSubarrays = 0;

        // Calculate the difference between the number of subarrays starting with k and k-1 distinct numbers
        for (int i = 0; i < nums.size(); ++i) {
            totalSubarrays += subarrayStartsWithKMinusOne[i] - subarrayStartsWithK[i];
        }

        return totalSubarrays;
    }

    // Helper function to find the earliest starting point of subarrays with at most k distinct elements for each ending point
    vector<int> countSubarraysStartingPoint(vector<int>& nums, int k) {
        int n = nums.size(); // Size of the input array
        vector<int> startPos(n); // Vector to store the starting positions
        int count[n + 1]; // Array to store the count of each number
        memset(count, 0, sizeof(count)); // Initialize the count array with zeros
        int distinctNums = 0; // Number of distinct elements
      
        // Two pointers technique: 'i' is the end pointer, 'j' is the start pointer
        for (int i = 0, j = 0; i < n; ++i) {
            // If we encounter a new element (count is 0), increase the number of distinct elements
            if (++count[nums[i]] == 1) {
                ++distinctNums;
            }
          
            // If distinct elements exceed k, move the start pointer to reduce the number of distinct elements
            for (; distinctNums > k; ++j) {
                // If after decrement count goes to zero, then one distinct element is removed
                if (--count[nums[j]] == 0) {
                    --distinctNums;
                }
            }
          
            // Record the starting position for the subarray ending at 'i' which has at most k distinct elements
            startPos[i] = j;
        }

        return startPos;
    }
};