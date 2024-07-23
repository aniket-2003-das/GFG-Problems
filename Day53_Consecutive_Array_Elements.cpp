//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
	bool areConsecutives(long long arr[], int n){ 
	    // Your code goes here
        sort(arr, arr+n);
        for(int i=0; i<n-1; i++){
            if(arr[i]+1==arr[i+1]) continue;
            else return false;
        }
        return true;
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
	    long long a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       
        Solution ob;
        if(ob.areConsecutives(a, n) == true)
	        cout<<"Yes";
	    else
	        cout<<"No";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends