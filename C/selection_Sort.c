#include<stdio.h>

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n){
    int i, j, index;
    
    for(i=0; i<n-1; i++){
        index=i;
        for(j=i+1; j<n; j++){
            if(arr[j]< arr[index]){
                index=j;
            }
        }
        
        swap(&arr[index], &arr[i]);
    }
}

void display(int arr[], int n){
    int i;
    for(i =0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);
    
    printf("Sorted array: ");
    display(arr, n);

    return 0;
}