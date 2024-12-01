//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    bool isPossible(int a, int b){
        //code here
        if(a==b==2) return 0;
        else if((a==2 || b==2) && a!=b) return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b; 
        cin>>a>>b;
        Solution obj;
        bool ans=obj.isPossible(a,b);
        cout<<ans<<"\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends