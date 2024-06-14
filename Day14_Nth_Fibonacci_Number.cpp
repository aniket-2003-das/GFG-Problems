//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
       // base cases
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        
        int a = 1, b = 1, c;
        const int mod = 1e9 + 7;
        

        for (int i = 3; i <= n; i++) {
            c = (a+b)%mod;
            a = b;
            b = c;
        }

        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}