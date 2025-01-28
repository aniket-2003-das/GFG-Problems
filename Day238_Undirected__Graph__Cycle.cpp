//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // bool detect(int src, vector<vector<int>> &adj, vector<int> &vis){
    //     vis[src]=1;
    //     queue<pair<int, int>> q;
    //     q.push({src, -1});
        
    //     while(!q.empty()){
    //         int node = q.front().first;
    //         int parent = q.front().second;
    //         q.pop();
    //         // it = iterator is the adjacent node.
    //         for(auto it: adj[node]){
    //             if(!vis[it]){
    //                 vis[it]=1;
    //                 q.push({it, node});
    //             }
    //             else if(parent!=it) return true;
    //         }
    //     }
    //     return false;
    // }
    
    bool detect(int node, int parent, vector<int> &vis, vector<vector<int>> &adj){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                if(detect(it, node, vis, adj)==true) return true;
            }
            else if(parent!=it) return true;
        }
        return false;
    }

    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        vector<int> vis(adj.size(), 0);
        for(int i=0; i<adj.size(); i++){
            if(!vis[i]){
                // if(detect(i, adj, vis)) return true;
                if(detect(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends