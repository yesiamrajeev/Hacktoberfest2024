//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    int mod = 1000000007;
		    int a = 1, b = 2;
		    if(n<3) return n;
		    
		    for(int i=3; i<=n; i++){
		        int temp = a;
		        a = b%mod;
		        b = (temp+a)%mod;
		    }
		    return b;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends