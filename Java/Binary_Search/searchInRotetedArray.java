// Problem Statement: There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.


import java.util.Scanner;

class searchInRotetedArray {

    public static int searchInRotetedArray(int[] nums, int k) {
        int i = 0;
        int j = nums.length-1;

        while(i<=j){
            int mid = (i+j)/2;

            if(nums[mid] == k){
                return mid;
            }else if(nums[i] <= nums[mid]){
                if(nums[i] <= k && nums[mid] >=k){
                    j = mid-1;
                }else{
                    i = mid+1;
                } 
            }else{
                if(nums[mid] <= k && nums[j] >=k){
                    i = mid+1;
                }else{
                    j = mid-1;
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int k = sc.nextInt();

        int answer = searchInRotetedArray(arr, k);
        
        System.out.println(answer);
    }

}