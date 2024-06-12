//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void output(int N, vector<int> &s, bool decrease){
        s.push_back(N);
        if (N <= 0) decrease = false;  // Switch to increasing when N is 0 or negative
        if (!decrease && N == s[0]) return;  // Stop when we return to the original number
        if (decrease) output(N - 5, s, true);
        else output(N + 5, s, false);
    }

    vector<int> pattern(int N){
        vector<int> s;
        output(N, s, true);
        return s;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends