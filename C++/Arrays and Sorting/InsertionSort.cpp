#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void insertionSort(int n,vector<int>&arr){
    for (int i = 0; i < n; i++)
    {
        int temp=arr[i];
        int j = i-1;
        for (;j>=0; j--)
        {
             if(arr[j]>temp){
                //shift
                arr[j+1]=arr[j];
             }
             else{
                //ruk jao
                break;
             }
        }
        arr[j+1]=temp;
    }
    for(int i=0;i<n;i++){
            cout<<" "<<arr[i];
         }
}


int main(){
    vector<int> arr={20,10,40,30};
    insertionSort(4,arr);
    return 0;
    
}