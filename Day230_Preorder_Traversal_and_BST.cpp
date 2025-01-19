//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int i=0;
    // Striver only upperbound approach not works.
    void solve(int arr[], int& N,int mini,int maxi){
        if(i>=N) return;
        if(arr[i]<mini || arr[i]>maxi) return ;

        int curr=arr[i++];
        solve(arr,N,mini,curr);
        solve(arr,N,curr,maxi);
        return;
        
    }
    int canRepresentBST(int arr[], int N) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        solve(arr,N,mini,maxi);
        if(i>=N) return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends