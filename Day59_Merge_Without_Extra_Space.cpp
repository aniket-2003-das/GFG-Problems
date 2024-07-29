//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
public:
    void merge(long long arr1[], long long arr2[], int n, int m) {
        int left=n-1;
        int right=0;
        //Swap elements till arr1[left] is smaller than arr2[right]:
        while (left>=0 && right<m) {
            if (arr1[left]>arr2[right]) {
                swap(arr1[left], arr2[right]);
                left--, right++;
            }
            else break;
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends