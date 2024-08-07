//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findMissing(int a[], int b[], int n, int m) { 
        // Your code goes here
	    unordered_set<int> st;
	    for(int i=0;i<m;i++) st.insert(b[i]);
	    
	    vector<int> ans;
	    for(int i=0;i<n;i++) {
	        if(st.count(a[i])==0) ans.push_back(a[i]);
	    }
	    return ans;
	} 
};
	

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin>>n;
        int m;
        cin>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin >> b[i];
        vector<int> ans;
        

        Solution ob;
        ans=ob.findMissing(a,b,n,m);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends