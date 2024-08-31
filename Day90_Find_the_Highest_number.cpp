//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& arr){
        // Code here
        int n=arr.size();
        if (n==1) return arr[0];
        if (arr[0]>arr[1]) return arr[0];
        if (arr[n-1]>arr[n-2]) return arr[n-1];
        int left=0, right=n-2;
        
        while(left<=right){
            int mid=(left+right)/2;
            //If arr[mid] is the peak:
            if (arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return arr[mid];
            // If we are in the left:
            if (arr[mid]>arr[mid-1]) left=mid+1;
            // If we are in the right or, arr[mid] is a common point:
            else right=mid-1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends