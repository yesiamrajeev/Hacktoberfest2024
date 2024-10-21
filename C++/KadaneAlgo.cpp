class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = size(nums), ans = nums[0];
        int curSum=nums[0];
            for(int j = 1; j < n ; j++) {
                curSum=max(nums[j],nums[j]+curSum);
                ans = max(ans, curSum); 
            }  
     return ans;
    }
};
