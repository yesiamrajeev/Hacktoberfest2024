class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int i=nums.size()-1;
       while(i>0){
           if(nums[i-1]<nums[i]){
               break;
           }
           i--;
       } 
       if(i==0){
           reverse(nums,i,nums.size()-1);
           return;
       }

       int index=i-1;
       int j=nums.size()-1;
       while(true){
           if(nums[j]>nums[index]){
               int temp=nums[index];
               nums[index]=nums[j];
               nums[j]=temp;
               break;
           }
           j--;
       }
       reverse(nums, i, nums.size() - 1);
    }
           void reverse(vector<int>& nums,int startindex,int endindex){
           while(startindex<=endindex){
               int temp=nums[startindex];
               nums[startindex]=nums[endindex];
               nums[endindex]=temp;

               startindex++;
               endindex--;
       }
    }
};
