class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i =0;
        int j =0;
        vector<int> ans; //new vector created
           sort(nums1.begin(), nums1.end());
           sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                i++;
            }
           else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                ans.push_back(nums1[i]); //when equal element in both array, push in ans, can be nums2[j] also
                i++;
                j++;
            }
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end()); //removes duplicated elements
        return ans;
    }
};
