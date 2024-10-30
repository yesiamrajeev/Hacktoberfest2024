#include<iostream>
using namespace std;
#include <array>
#include <bits/stdc++.h>
//Book Allocation Problem
bool isPossible(int arr[],int n,int m,int mid){
    int studentCount=1;
    int pageSum=0;
    for(int i=0;i<n;i++){
        if (pageSum+arr[i]<=mid)
        {
             pageSum+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m ||arr[i]>mid){
                return false;
            }
            pageSum=arr[i];
        }    
    }
    return true;
}
// int allocateBooks(int arr[],int n,int m){
//  int s=0;
//  int sum=0;
// int ans=-1; 
//  for(int i=0;i<n;i++){
//     sum+=arr[i];
//  }   
//  int e=sum;
//  int mid=s+(e-s)/2;

//  while (s<=e)
//  {
//     if (isPossible(arr,n,m,mid)){
//         ans=mid;
//         e=mid-1;
//     }
//     else{
//      s=mid+1;   
//     }
//      int mid=s+(e-s)/2;
//     }
//  return ans;
// }
    bool isPossible2(vector<int> &stalls,int k,int mid){
        int cowCount=1;
        int lastPos=stalls[0];
        int size= sizeof(stalls)/sizeof(int);
        for(int i=0;i<size;i++){
            if(stalls[i]-lastPos>=mid){
                cowCount++;
                if(cowCount==k){
                    return true;
                }
                lastPos=stalls[i];
            }
        } 
        return false;
    }
    int agressiveCows(vector<int> &stalls,int k){
        sort(stalls.begin(),stalls.end());
        int s=0;
        int maxi=-1;
        int size= sizeof(stalls)/sizeof(int);
        for(int i=0;i<size;i++){
            maxi=max(maxi,stalls[i]);
        } 
        int e=maxi;
        int ans=-1;
        int mid=s+(e-s)/2;
        while (s<=e)
        {
            if (isPossible2(stalls,k,mid))
            {
               ans=mid;
               s=mid+1; 
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }

int main(){
    //    int arr[]={10,20,30,40};
    //     int n=4;
    //     int m=2;
    //     cout<<allocateBooks(arr,n,m);
     vector<int> stalls = {1, 2, 3};
     int k=2;
     cout<<agressiveCows(stalls, k);
    return 0;
}