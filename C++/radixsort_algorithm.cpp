/*
Implementation of Radix Sort Algorithm in C++
By - Arin Sharma (nub-rin)
*/

#include <iostream>

// Function prototypes

int getMax(int[], int); // Function to get the maximum element from the array
void countSort(int[], int, int); // Function to perform counting sort on the array
void radixSort(int[], int); // Function to perform radix sort on the array

// Main function - Entry point of the program
int main(){
    int size_of_array;

    std::cout << "Enter the size of the array: ";
    std::cin >> size_of_array;

    int arr[size_of_array];

    std::cout << "Enter the elements of the array: ";
    for(int i = 0; i < size_of_array; i++){
        std::cin >> arr[i];
    }

    radixSort(arr, size_of_array);

    std::cout << "Sorted array: ";
    for(int i = 0; i < size_of_array; i++){
        std::cout << arr[i] << " ";
    }

    return 0;
}

int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for(int i = 0; i < n; i++){
        count[(arr[i]/exp)%10]++;
    }

    for(int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }

    for(int i = n-1; i >= 0; i--){
        output[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    for(int exp = 1; m/exp > 0; exp *= 10){
        countSort(arr, n, exp);
    }
}