//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numOfDiv(int m, int n, int a, int b) {
        // code here
        int count = 0;
        for(int i=m; i<=n; i++){
            if(i%a==0) count++;
            if(i%b==0) count++;
            if(i%a==0 && i%b==0) count--;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m,n,a,b;
        
        cin>>m>>n>>a>>b;

        Solution ob;
        cout << ob.numOfDiv(m,n,a,b) << endl;
    }
    return 0;
}
// } Driver Code Ends