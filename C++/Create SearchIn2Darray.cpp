class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        //start of flattened matrix
        int low=0;
        //end of flat matrix
        int high=m*n-1;
        while (low<=high){
            int mid=(low+high)/2;
            int row=mid/n;
            int col=mid%n;
            if (matrix[row][col]==target){
                return true;
            }
            else if (target > matrix[row][col]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};
