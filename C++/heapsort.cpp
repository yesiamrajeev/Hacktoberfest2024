//This program implements Heap Sort using a min-heap
#include<bits/stdc++.h>
using namespace std;

//This function ensures that a subtree rooted at index i maintains the min-heap property.
//It recursively compares the node at index i with its left (2*i + 1) and right (2*i + 2) children.
//If either of the children is smaller than the current node, it swaps them and recursively heapifies the affected subtree.

void heapify(vector<int>&arr, int n, int i){
  int l = 2*i + 1;
  int r = 2*i + 2;
  int smallest = i;
  if(l < n && arr[l] < arr[smallest]) smallest = l;
  if(r < n && arr[r] < arr[smallest]) smallest = r;
  if(smallest != i){
    swap(arr[i], arr[smallest]);
    heapify(arr, n, smallest);
  }
}

//This function builds a min-heap from an unsorted array.
//It starts from the last non-leaf node (at index n/2 - 1) and calls heapify() for each node, ensuring the min-heap property from the bottom up.

void buildMinHeap(vector<int>&arr, int n){
  for(int i = n/2 - 1; i >= 0; i--){
    heapify(arr, n, i);
  }
}

//First, it calls buildMinHeap() to convert the array into a min-heap.
//Then, it repeatedly swaps the root (the smallest element) with the last unsorted element, reducing the size of the heap by 1 and calling heapify() on the root to restore the min-heap property.
//This process continues until the array is sorted in descending order.

void heap(vector<int>&arr){
  buildMinHeap(arr, arr.size());
  for(int i = arr.size() - 1; i > 0; i--){
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

//It initializes an array arr and calls the heap() function to sort it.
//After sorting, the array is printed in reverse order because it was originally sorted in descending order, and the program prints it from largest to smallest.

int main(){
  vector<int>arr= {12, 7, 20, 10, 5, 16, 8, 15};
  heap(arr);
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<endl;
  }
  return 0;
}