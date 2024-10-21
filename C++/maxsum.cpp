#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArraySum(const std::vector<int>& nums) {
    int currentMax = nums[0];
    int globalMax = nums[0];

    for (size_t i = 1; i < nums.size(); i++) {
        currentMax = std::max(nums[i], currentMax + nums[i]);
        globalMax = std::max(globalMax, currentMax);
    }

    return globalMax;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input

    int maxSum = maxSubArraySum(nums);
    std::cout << "The maximum sum of the subarray is: " << maxSum << std::endl;

    return 0;
}
