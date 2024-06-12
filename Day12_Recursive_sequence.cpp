//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence_sum(int n, int termNo, int ans, int indicator) {
        long long mul = 1;
        if(termNo > n)  return ans%MOD;
        
        for(int j=0; j < termNo; j++) {
            mul = (mul*indicator)%MOD;
            indicator++;
        }
        ans = (ans+mul)%MOD;
        termNo++;
        return sequence_sum(n, termNo, ans, indicator);
    }
    
    const int MOD = 1e9+7;
    
    long long sequence(int n){
        return sequence_sum(n,1,0,1);
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
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends