//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void traversal(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
        visited[node]=1;
        for (int i=0; i<isConnected[node].size(); i++) {
            if (isConnected[node][i]==1 && !visited[i]) {
                traversal(i, isConnected, visited);
            }
        }
    }

    int numProvinces(vector<vector<int>> isConnected, int V) {
        // code here
        vector<int> visited(V, 0);
        int cnt=0;

        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i]){
                cnt++;
                traversal(i, isConnected, visited);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends