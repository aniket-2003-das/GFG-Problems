//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
        if (m==1) return 1;
        int low = 1;
        int high = m;
        
        while (low<=high) {
            int mid = (low+high)/2;
            long long mid_pow=1;
            
            for (int i=0; i<n; ++i) {
                mid_pow *= mid;
                if (mid_pow > m) break;
            }
            
            if (mid_pow == m) return mid;
            else if (mid_pow < m) low = mid + 1;
            else{
                high = mid - 1;
            }
        }
        return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends