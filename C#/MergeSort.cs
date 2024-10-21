// Author: Luis A. Tavarez - Country (DR - Dominican Republic) - 2024  
// Hacktoberfest2024
// C# 

using System;

class MergeSort
{
    public static void Merge(int[] arr, int left, int mid, int right)
    {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int[] leftArray = new int[n1];
        int[] rightArray = new int[n2];
        Array.Copy(arr, left, leftArray, 0, n1);
        Array.Copy(arr, mid + 1, rightArray, 0, n2);

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (leftArray[i] <= rightArray[j])
            {
                arr[k++] = leftArray[i++];
            }
            else
            {
                arr[k++] = rightArray[j++];
            }
        }

        while (i < n1)
        {
            arr[k++] = leftArray[i++];
        }

        while (j < n2)
        {
            arr[k++] = rightArray[j++];
        }
    }

    public static void Sort(int[] arr, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            Sort(arr, left, mid);
            Sort(arr, mid + 1, right);
            Merge(arr, left, mid, right);
        }
    }
}

class Program
{
    public static void Main()
    {
        int[] arr = { 12, 11, 13, 5, 6, 7 };
        MergeSort.Sort(arr, 0, arr.Length - 1);

        Console.WriteLine("Sorted array is:");
        Console.WriteLine(string.Join(" ", arr));
    }
}
