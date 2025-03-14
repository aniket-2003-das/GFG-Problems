//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(100000, 1e9);
        dist[start]=0;
        int mod = 100000;
        if(start==end) return 0;
        
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            for(auto it: arr){
                int num = (it*node)%mod;
                if(steps + 1 < dist[num]){
                    dist[num] = steps + 1;
                    if(num==end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends