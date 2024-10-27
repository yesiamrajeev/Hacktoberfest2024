/*
Problem Statement:
1523. Count Odd Numbers in an Interval Range
Given two non - negative integers low and high.Return the count of odd numbers between low and high(inclusive).

Example 1:

Input: low = 3, high = 7
Output : 3
Explanation : The odd numbers between 3 and 7 are[3, 5, 7].
Example 2 :

Input : low = 8, high = 10
Output : 1
Explanation : The odd numbers between 8 and 10 are[9].
	*/




//Sollution

#include <iostream>
using namespace std;

class Solution {
public:
    // Function to count odd numbers between two integers a and b. Including a and b

    int CountOdds(int a, int b) {
        // Calculate the range (difference) between a and b
        int c = b - a;

        // Case 1: If the range c is even and the upper bound b is odd
        // This ensures the count includes the upper bound if it is odd
        if (c % 2 == 0 && b % 2 == 1) {
            return c / 2 + 1; // Add 1 to account for the last odd number
        }
        // Case 2: If the range (c) is odd
        // This means there's an odd count within the range itself
        else if (c % 2 == 1) {
            return c / 2 + 1; // Add 1 to account for the extra odd in the range
        }
        // Case 3: If the range (c) is even and the upper bound (b) is even
        // This means there are no extra odds to account for at the end
        else {
            return c / 2; // Simply return half of the range as the count of odds
        }
    }
};

/* Driver program to test the function */
int main() {
    Solution solution;

    // Test case 1: Range [0, 20] || The odd numbers are: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19
    cout  << solution.CountOdds(0, 20) << endl; // Expected output: 10

    // Test case 2: Range [11, 21] || The odd numbers are: 11, 13, 15, 17, 19, 21
    cout<< solution.CountOdds(11, 21) << endl; // Expected output: 6

    // Test case 3: Range [1, 1] || The odd number is: 1
    cout  << solution.CountOdds(1, 1) << endl; // Expected output: 1

    return 0;
}