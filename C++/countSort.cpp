#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countSort(vector<int> &arr)
{
    // Find the maximum element in the array
    int maxVal = *max_element(arr.begin(), arr.end());

    // Create a count array to store the frequency of each element
    vector<int> count(maxVal + 1, 0);

    // Store the count of each element
    for (int i = 0; i < arr.size(); i++)
    {
        count[arr[i]]++;
    }

    // Modify the count array by adding the previous counts (cumulative sum)
    for (int i = 1; i <= maxVal; i++)
    {
        count[i] += count[i - 1];
    }

    // Create an output array to store the sorted elements
    vector<int> output(arr.size());

    // Build the output array by placing elements in correct position
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted array to the original array
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    countSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
