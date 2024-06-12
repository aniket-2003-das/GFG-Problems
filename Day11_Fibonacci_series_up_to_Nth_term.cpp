//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod= 1000000007;
  
    void findFib(vector<int>&ans, int n, int &f1,int &f2){
            if(n==1) return;
            int result = (f1+f2)%mod;
            f1=f2;
            f2=result;
            ans.push_back(result);
            findFib(ans,n-1,f1,f2);
      }
      
        vector<int> Series(int n) {
            // Code here
            vector<int>ans;
            int f1=0; 
            int f2=1;
            ans.push_back(f1);
            ans.push_back(f2);
            findFib(ans,n,f1,f2);
            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends