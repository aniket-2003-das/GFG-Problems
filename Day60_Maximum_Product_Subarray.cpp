//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long ans=LONG_MIN;
        long long c=1;
        long long t=1;
        
        for(int i=0;i<n;i++){
            c=c*arr[i];    
            t=t*arr[n-1-i];
            
            ans=max(ans,c);
            ans=max(ans,t);
            
            if(c==0) c=1;
            if(t==0) t=1;
        }
        return(ans);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends