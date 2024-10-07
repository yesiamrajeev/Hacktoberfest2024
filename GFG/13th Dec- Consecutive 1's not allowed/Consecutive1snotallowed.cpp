//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++



class Solution{
public:
	// #define ll long long
	 int mod=1e9+7;
    ll countStrings(int n) {
        ll f=1;
        ll s=2;
        
        for(int i=2;i<=n;i++){
            ll t=(f+s)%mod;
            f=s;
            s=t;
        }
        return s;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends