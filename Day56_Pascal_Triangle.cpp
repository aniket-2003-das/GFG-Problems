//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code shows false because of modulo at 144.
        int MOD = 1000000007;
        // long long ans=1;
        // vector<long long> res;
        // for(int i=0; i<n; i++){
        //     res.push_back(ans);
        //     ans=(ans*(n-i-1))%MOD;
        //     ans=(ans/(i+1))%MOD;
        // }
        // return res;
        

        vector<vector<long long>> result;
        for (int i=0; i<n; i++) {
            vector<long long> row(i+1, 1);
            for (int j=1; j<i; j++) {
                row[j] = (result[i-1][j-1]+result[i-1][j])%MOD;
            }
            result.push_back(row);
        }
        return result[n-1];
    }
};

//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends