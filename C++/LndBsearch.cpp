#include<iostream>
#include<stdlib.h>
using namespace std;
int BSearch(int arr[],int n,int k);
int LSearch(int k,int arr[],int n);

int main()
{
    int n;
    int k,x;
    cout<<"Enter the number of elements to be inserted:";
    cin>>n;
    int arr[n];
    cout<<"Enter the data value:";
    bool isDuplicate;
    for (int i = 0; i < n; ) {
        cin >> k;
        isDuplicate = false;
        // Check for duplicates manually
        for (int j = 0; j < i; j++) {
            if (arr[j] == k) {
                isDuplicate = true;
                cout << "Duplicate number encountered. Please enter a different number.\n";
                break;
            }
        }
        if (!isDuplicate) {
            arr[i] = k;
            i++; // Only increment i if the number is unique and inserted
        }
    }
     cout<<"\nUsing Linear Search:";
    cout<<"\nEnter the element whose position is to be searched:";
    cin>>k;
   x=LSearch(k,arr,n);
   if(x==-1)//return -1 if element is not found
   cout<<k<<" is not found";
   else
   cout<<k<<" is found at position "<<x;
   cout<<"\nUsing Binary Search";
   cout<<"\nEnter the element whose position is to be searched:";
    cin>>k;
     x=BSearch(arr,n,k);
   if(x==-1)//return -1 if element is not found
   cout<<"\n"<<k<<" is not found";
   else
   cout<<"\n"<<k<<" is found at position "<<x;
    return 0;
}

int LSearch(int k,int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==k)
        {
            i=i+1;
            return i;
        }
    }
    return -1;
}

int BSearch(int arr[],int n,int k)
{
    //sorting the array
    for(int i=0;i<(n-1);i++)
    {
        for(int j=0;j<(n-i-1);j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"\nThe Sorted array is as follows:";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
   int mid;
   int low=0;
   int high=n-1;
   while(low<=high)
   {
    mid=(low+high)/2;
    if(k>arr[mid])
    {
        low=mid+1;
    }
    else if(k<arr[mid])
    {
        high=mid-1;
    }
    else
    return (mid+1);
   }
   return -1;
}
