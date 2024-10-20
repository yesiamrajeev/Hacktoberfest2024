// Author: Luis A. Tavarez - Country (DR - Dominican Republic) - 2024  
// Hacktoberfest2024


#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 8, 6, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printf("Sorted array: ");
    printArray(arr, size);
    return 0;
}
