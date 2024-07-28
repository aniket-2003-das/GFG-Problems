//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
         // Code here
        int n=arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            // if the current interval not in the last interval
            if(ans.empty() || arr[i][0]>ans.back()[1]) ans.push_back(arr[i]);
            // if the current interval lies in the last interval
            else ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends