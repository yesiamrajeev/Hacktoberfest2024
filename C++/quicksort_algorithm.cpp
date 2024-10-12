#include <iostream>
#include <vector>

//Author: Luis A. Tavarez - Country (DR - Dominican Republic) - 2024  
//Hacktoberfest2024

// arr: vector of integers to be sorted 
// low: starting index of the subarray to be partitioned
// high: ending index of the subarray to be partitioned

int partition(std::vector<int>& arr,int low, int high){
  int pivot = arr[high];
  int partitionIndex = (low -1);
  
  for(int currentIndex=low; currentIndex < high; currentIndex++){
      if(arr[currentIndex] < pivot){
        currentIndex++;
        std::swap(arr[partitionIndex], arr[currentIndex])
      }
  }

  std::swap(arr[partitionIndex + 1], arr[high]);

  return (partitionIndex + 1);

}


// arr: reference to the vector of integers to be sorted
// low: starting index of the subarray to be sorted
// high: ending index of the subarray to be sorted
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

//Run Code with example 


int main() {

  // Initialize a vector of integers with some unsorted values
  std::vector<int> arr = {34, 7, 23, 32, 5, 62};
  
  std::cout << "Original array: ";
  
  for(int num: arr){
    std:count<<std::endl;
  }
  
  std::count <<std::endl;
  
  quicksort(arr,0, arr.size() - 1);
  
  std::count << "Sorted array: ";
  
  for(int num: arr){
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;

}
