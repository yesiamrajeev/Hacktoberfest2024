#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);  // Initialize result array with -1
    stack<int> s;  // Stack to store indices of elements

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack smaller than or equal to current element
        while (!s.empty() && nums[s.top()] <= nums[i]) {
            s.pop();
        }

        // If stack is not empty, the element on the top of the stack is the next greater
        if (!s.empty()) {
            result[i] = nums[s.top()];
        }

        // Push the current element index onto the stack
        s.push(i);
    }

    return result;
}

int main() {
    vector<int> nums = {4, 5, 2, 25};
    vector<int> result = nextGreaterElement(nums);

    // Print the result
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}
