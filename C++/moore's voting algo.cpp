//Question:
// Given an array of n integers, find the majority element, 
// which is defined as the element that appears more than n/2 times in the array. 
// If no such element exists, return -1.

#include <iostream>
#include <vector>

int mooresVotingAlgorithm(const std::vector<int>& nums) {
    int candidate = -1, count = 0;

    // Phase 1: Finding the candidate
    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Phase 2: Verifying the candidate
    count = 0;
    for (int num : nums) {
        if (num == candidate) {
            count++;
        }
    }

    // Check if the candidate is the majority element
    if (count > nums.size() / 2) {
        return candidate;
    } else {
        return -1;  // No majority element
    }
}

int main() {
    std::vector<int> arr = {2, 2, 1, 1, 2, 2, 2};
    int result = mooresVotingAlgorithm(arr);
    
    if (result != -1) {
        std::cout << "Majority element is: " << result << std::endl;
    } else {
        std::cout << "No majority element found." << std::endl;
    }

    return 0;
}
