//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
       long  ans = 0, sum = 0;
        for(int i = 0; i < N; i++){
            if(i < K) 
                sum += Arr[i];
            else{
                ans = max(ans,sum);
                sum += Arr[i];
                sum -= Arr[i-K];
            }
        }
        ans = max(ans,sum);
        return ans;
    }
};

//{solution starts 
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends