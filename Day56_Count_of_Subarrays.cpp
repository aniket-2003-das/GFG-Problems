//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ll long long


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	#define ll long long
	ll countSubarray(int arr[], int n, int k) {
        // code here
        ll count=0, x=1;
        for(int i=0; i<n; i++){
            if(arr[i]>k){
                count+=(n-i)*x; 
                x=1; 
            }
            else x++;
        }
        return count;
        /* n-i is count for further sub array starting from arr[i],
        (n=i)x is the same answer repeated for length when arr[i]>k is first found,
        as the current subarray elements can permute in themshelves keeping contigious
        condition in mind. 
        total sub-Array = n*(n+1)/2,
        total sub-sequence = 2^n 
        */
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.countSubarray(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends