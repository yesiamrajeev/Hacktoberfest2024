#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans, vector<vector<int>>& finalans, int idx) {
        if (nums.size() == idx) {
            finalans.push_back(ans);
            return;
        }
        // Not include the current element
        helper(nums, ans, finalans, idx + 1);
        
        // Include the current element
        ans.push_back(nums[idx]);
        helper(nums, ans, finalans, idx + 1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalans;
        helper(nums, ans, finalans, 0);
        return finalans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.subsets(nums);

    // Output the subsets
    cout << "Subsets are:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}
