//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size(), m=arr[0].size();
        int row=0, col=m-1;
        int index=-1;
        int count=-1, ans=-1;
        
        while (row<n && col>=0) {
            if (arr[row][col]==1){
                count++;
                col--;
            }
            else row++;
            if(count>ans) {
                ans=count;
                index=row;        
            }
        }
        return index;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends