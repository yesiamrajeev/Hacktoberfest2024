// Author: Luis A. Tavarez - Country (DR - Dominican Republic) - 2024  
// Hacktoberfest 2024
// C#

using System;

class Program
{
    // Binary Search Algorithm
    static int BinarySearch(int[] arr, int target)
    {
        int start = 0;
        int end = arr.Length - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            // If the element is present at the middle
            if (arr[mid] == target)
            {
                return mid;
            }

            // If target is greater, ignore the left half
            if (arr[mid] < target)
            {
                start = mid + 1;
            }
            // If target is smaller, ignore the right half
            else
            {
                end = mid - 1;
            }
        }

        // Return -1 if the element is not present
        return -1;
    }

    static void Main(string[] args)
    {
        int[] array = { 2, 3, 4, 10, 40 };
        int target = 10;
        int result = BinarySearch(array, target);

        if (result != -1)
        {
            Console.WriteLine("Element found at index: " + result);
        }
        else
        {
            Console.WriteLine("Element not found.");
        }
    }
}
