#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void selectionSort(vector<int>&arr,int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
         swap(arr[minIndex],arr[i]);
         
    }
    for(int i=0;i<n;i++){
            cout<<" "<<arr[i];
         }
}
int main(){
    vector<int> arr={20,10,40,30};
    selectionSort(arr,4);

    return 0;
}