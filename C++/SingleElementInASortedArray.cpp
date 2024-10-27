//You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

//Return the single element that appears only once.

//Your solution must run in O(log n) time and O(1) space


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = (low + high) / 2;

          
            if (mid % 2 == 1) {
                mid--;
            }

     
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
               
                high = mid;
            }
        }

       
        return nums[low];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 5, 5}; // Example input

    int singleElement = solution.singleNonDuplicate(nums);
    cout << "The single non-duplicate element is: " << singleElement << endl;

    return 0;
}
