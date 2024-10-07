
//{ Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class Subarraywith0sum {
    public static void main(String[] args) {
        // code
        // code

        // taking input using class Scanner
        //THIS IS A LEARNING EXPERIENCE 
        Scanner scan = new Scanner(System.in);

        // taking total number of testcases
        int t = scan.nextInt();
        while (t > 0) {
            // taking total count of elements
            int n = scan.nextInt();

            // Declaring and Initializing an array of size n
            int arr[] = new int[n];

            // adding elements to the array
            for (int i = 0; i < n; i++) {
                arr[i] = scan.nextInt();
            }

            t--;

            // calling the method findSum
            // and print "YES" or "NO" based on the result
            System.out.println(new Solution().findsum(arr, n) == true ? "Yes" : "No");
        }
    }

}
// } Driver Code Ends

// solution from here
class Solution {

    static boolean findsum(int arr[], int n) {
        // Your code here
        int sum = 0;
        HashSet<Integer> set = new HashSet<>();
        set.add(0);

        for (int i = 0; i < n; i++) {
            sum = sum + arr[i];
            if (set.contains(sum))
                return true;
            set.add(sum);
        }

        return false;
    }
}
