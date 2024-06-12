//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void help(int N, int from, int aux, int to, vector<pair<int,int>> &ans){
        if(N==0) return;
        if(N==1) {
             ans.push_back({from, to});
             return;
        }

        help(N-1,  from,to,aux,  ans);
        ans.push_back({from,to});
        help(N-1,  aux,from,to,  ans);
        
        return;
    }
    
    
    // steps to complete TOH = 2^N - 1;
    vector<int> shiftPile(int N, int n){
        vector<pair<int,int>> ans;
        vector<int> RET;
        
        help(N,  1, 2, 3,  ans);
        
        RET.push_back((ans[n-1]).first);
        RET.push_back((ans[n-1]).second);
        
        return RET;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends