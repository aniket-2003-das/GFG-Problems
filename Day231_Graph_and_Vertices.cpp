//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // Function to calculate factorial
    long long factorial(int n) {
        if (n==0 || n==1) return 1;
        return n*factorial(n-1);
    }
    // Function to calculate nCm
    long long nCm(int n, int m) {
        if (m>n) return -1;
        return factorial(n)/(factorial(m)* factorial(n-m));
    }
  
    long long count(int n) {
        // your code here
        if(n==1) return 1;
        int power = nCm(n, 2);
        return pow(2, power);  
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
        cout << ob.count(n) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends