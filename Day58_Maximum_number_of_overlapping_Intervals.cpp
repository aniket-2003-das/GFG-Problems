//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int overlap(vector<pair<int,int>>intervals, int n){
        //Write your code here
        int ans=0,cnt=0;
        map<int, int> mpp;
        for(auto pair : intervals) mpp[pair.first]++, mpp[pair.second+1]--;
        
        for(auto i : mpp) {
            cnt+=i.second;
            ans=max(ans, cnt);
            // cout<<i.first<<"===>"<<i.second<<endl;
            // cout<<cnt<<endl;
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
	    int n;
	    cin >> n;
	    vector<pair<int,int>>intervals;
	    for(int i = 0; i < n; i++){
	        int a, b;
	        cin >> a >> b;
	        intervals.push_back({a, b});
	    }
	    Solution ob;
	    int ans = ob.overlap(intervals, n);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends