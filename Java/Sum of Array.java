
// Importing Necessary Header Files  
import java.util.*;
class Solution {
    int sum(int arr[], int n) {
        int sum=0; // Initiaizing a variable called Sum to zero of type int 
        for(int i=0;i<n;i++) // for loop used to iterate all the elements present
        {
            sum=sum+arr[i];  //array elements and sum value will be added  
           
        } // for loop closing
         return sum; // return the final sum 
        
    } // closing of function
} // closing class 
