//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& path, vector<int>& vis) {
        vis[node]=1;
        path[node]=1;
    
        for (auto it: adj[node]) {
            if(!vis[it]) {
                if(dfs(it, adj, path, vis)) return 1;
            } 
            else if (path[it]) return 1;
        }
        path[node]=0;
        return 0;
    }
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> path(V, 0);
        vector<int> vis(V, 0);
    
        for (int i=0; i<V; i++) {
            if (!vis[i] && dfs(i, adj, path, vis)) return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends