//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimalSum(int N, int X){
        int count=0;
        while(N>0){
            for(int i=11;i>=0;i--){
                int p=pow(X,i);
                if(p<=N){
                    N=N-p;
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, X;
        cin>>N>>X;
        
        Solution ob;
        cout<<ob.minimalSum(N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends