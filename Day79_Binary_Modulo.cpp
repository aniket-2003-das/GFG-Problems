//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string s, int m){
            //code here
            int n=s.size();
            int ans=0;
            
            for (int i=0;i<n;i++) {
                ans=(2*ans)+(s[i]-'0');
                ans=ans%m;
            }
           return ans; 
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends