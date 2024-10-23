#include <iostream>
using namespace std;
// Function for Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n ; 
    //ask user for size of array
    cout <<  "Enter size of Array: " << endl;
    cin >> n;
    int arr[n];
    // Take input array from user.
    cout << "Enter the elements in the array : " <<  endl; 
    for (int i = 0; i < n ; i++ )
      {
        cin >> arr[i] ; 
      }
    cout << "Original array: ";
    printArray(arr, n);

    // Call insertionSort function
    insertionSort(arr, n);

    // Print the Sorted array.
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
