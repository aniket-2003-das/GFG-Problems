//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Should return true if there exists a triplet in the
    // array arr[] which sums to x. Otherwise false
    bool find3Numbers(int arr[], int n, int x) {
        // Your Code Here
        sort(arr, arr+n);
        for(int i=0; i<n; i++) {
            int left=i+1;
            int right=n-1;
            while(left<right) {
                int sum=arr[i]+arr[left]+arr[right];
                if(sum==x) return true; 
                else if (sum<x) left++; 
                else right--; 
            }
        }
        return false; 
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends