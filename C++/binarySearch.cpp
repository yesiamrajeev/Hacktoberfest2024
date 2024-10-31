#include<iostream>
using namespace std;

int binarySearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        //go to right wala part
        if(key>arr[mid]){
            start=mid+1;

        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;

    }
 return -1;
}

 int getpivot(int arr[],int n){
        int s=0;
        int e=n-1;
        int mid=s+(e-s)/2;
        while(s<e){
            if (arr[mid]>=arr[0]){
                s=mid+1;
            }
            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }

    long long int SqrtInteger(int x){
        int s=0;
        int e=x;
        int ans=-1;
       long long int mid=s+(e-s)/2;
        while(s<=e){
            long long int square=mid*mid;
            if(square==x){
                return mid;
            }
            if(square<x){
                ans=mid;
                s=mid+1;
            }
            else
           e= mid-1;
        mid=s+(e-s)/2;
        }
        return ans;
    }
    double morePrecision(int n,int precision,int tempSol){
        double factor=1;
        double ans=tempSol;
        for(int i=0;i<precision;i++){
             factor=factor/10;
        for (double j=0;j*j<n;j=j+factor){
            ans=j;
        }
    }
    return ans;
    }

int main(){
    // int even[6]={2,4,6,8,12,18};
    // int odd[5]={3,8,11,14,16};   

    // int evenIndex=binarySearch(even,6,18);
    // cout<<"Index of 18 is "<<evenIndex<<endl;
   
    // int oddIndex=binarySearch(odd,5,16);
    // cout<<"Index of 16 is "<<oddIndex<<endl;
     
    // int arr[5]={3,8,10,17,1};
    // cout<<"Pivot is "<<getpivot(arr,5)<<endl;
    
  int n;
  cout<<"Enter the number "<<endl;
  cin>>n;
  int tempSol=SqrtInteger(n);
cout<<"Answer is "<<morePrecision(n,3,tempSol);
    return 0;
}