//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to return the length of the longest subarray with positive product
    int maxLength(vector<int> &arr,int n){
        //code here
        int cur=0, last_idx=0;
        int neg=0, ans=0, first_neg=-1;
    
        while (cur<n) {
            if(!arr[cur]) {
                last_idx=cur+1;
                if(neg%2)
                ans=max(ans, cur-1-first_neg);
                neg=0;
            }
            else {
                if(arr[cur]<0) {
                    neg++;
                    if(neg==1) first_neg=cur;
                }    
                if(!(neg%2)) ans=max(ans, cur-last_idx+1);
            }
            if(cur==n-1 and neg%2) 
                ans=max(ans, cur-first_neg);
            cur++;  
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends