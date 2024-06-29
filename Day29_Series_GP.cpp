//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int mod=1000000007;
    
    long long power(long long x, int n){
        
        long long result=1;
        while (n>0){
            if (n&1){
                result = (result*x)%mod;
            }
            x = (x*x)%mod;
            n >>= 1;
        }
        return result;
    }
    
   	int Nth_term(int a, int r, int n){
   	    unsigned long long ans = a*power(r,n-1);
   	    return ans%mod;
   	}    
};
//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, r, n;
		cin >> a >> r >> n;
		Solution ob;
		int ans = ob.Nth_term(a, r, n);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends