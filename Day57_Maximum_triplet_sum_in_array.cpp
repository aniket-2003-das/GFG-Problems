//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxTripletSum(int a[], int n){
        // Complete the function
        sort(a, a+n);
        return a[n-1]+a[n-3]+a[n-2];
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; int a[n];
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    Solution ob;
	    cout <<ob.maxTripletSum(a, n);
	    cout<<"\n";
	}
return 0;
}
// } Driver Code Ends