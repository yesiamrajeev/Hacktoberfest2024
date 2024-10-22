/*
Description:-
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

*/

import java.util.Arrays;

public class HouseRobber {

    //recursively compute the maximum loot with memorization
    public static int maxLootMemoized(int[] houses, int n, int[] memo) {
        if (n <= 0) {
            return 0;
        }

        if (n == 1) {
            return houses[0];
        }

        // Check if the result is already computed
        if (memo[n] != -1) {
            return memo[n];
        }

        // calculate the maximum loot 
        // rob the current house and skip the next
        int robCurrent = houses[n - 1] + maxLootMemoized(houses, n - 2, memo);
        
        // skip the current house
        int skipCurrent = maxLootMemoized(houses, n - 1, memo);

        // store the maximum of the two choices in the memo array
        memo[n] = Math.max(robCurrent, skipCurrent);
        return memo[n];
    }

    //calculating the maximum possible loot 
    public static int maxLoot(int[] houses) {
        int n = houses.length;
        int[] memo = new int[n + 1];
        Arrays.fill(memo, -1);
        return maxLootMemoized(houses, n, memo);
    }

    public static void main(String[] args) {
        int[] houses = {6, 7, 1, 3, 8, 2, 4};
        System.out.println(maxLoot(houses));
    }
}