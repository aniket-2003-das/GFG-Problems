//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Brute force doesnt work
        // int cnt=0;
        // for (int i=0; i<n; i++){
        //     for (int j=0; j<m; j++){
        //         if(a[i]==b[j]) cnt++;
        //     }
        // }
        // return cnt;
        
        unordered_set<int>s1,s2;
        int cnt=0;
        
        for(int i=0; i<n; i++) {
            s1.insert(a[i]);
        }
        for(int i=0; i<m; i++) {
            s2.insert(b[i]);
        }
    
        for(auto it : s2) {
            if(s1.find(it)!=s1.end()) {
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends