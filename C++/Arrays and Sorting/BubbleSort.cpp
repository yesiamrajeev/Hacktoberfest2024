#include <iostream>
using namespace std;
#include <bits/stdc++.h>

void bubbleSort(vector<int> &arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        // for round1 to n-1
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        // process element till n-1 th index
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            // already sorted
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}
int main()
{
    vector<int> arr = {20, 10, 40, 30};
    bubbleSort(arr, 4);
    return 0;
}