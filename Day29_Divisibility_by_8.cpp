//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        
        int len=s.length();
        if(len<=3) {
            int temp=stoi(s);
            if(temp%8==0) return 1;
        }
        
        string last_3_char = s.substr(len-3);
        int temp = stoi(last_3_char);
        
        if(temp%8==0) return 1;
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends