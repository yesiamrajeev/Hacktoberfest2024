/*Sushil has an array A of N integers - A1,A2,...AN.He constructs a new array from it, the prefix sum array P=[P1,P2,...], where Pi=A1+A2+A3...+Ai.
Sushil hates even numbers but he likes odd numbers, and thus wants to sure there are as many odd numbers as possible in the prefix sum array P. 
He is allowed to play with the array A and rearrange it arbitrarily. 
Find the maximum number of odd numbers in the prefix sum array P if Sushil rearranges the array A optimally.*/
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, count=0;
	    cin>>n;
	    int a[n];
	        for(int i=0; i<n; i++){
	            cin>>a[i];
	        }
	        for(int i=0; i<n; i++){
	           if(a[i]%2==0){
	           count++;
	        }
        }
	    if(count==n){
	        cout<<0<<endl;
	    }
	   // else if(count==n-1){
	   //     cout<<n<<endl;
	   // }
	   // else if(count==n-2){
	   //     cout<<n-1<<endl;
	   // }
	    else {
	        cout<<n-((n-count)/2)<<endl;
	    }
	}
}


