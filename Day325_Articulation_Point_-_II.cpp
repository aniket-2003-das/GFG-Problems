//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
int timer=0;
private:
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<vector<int>> &adj){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child = 0;
        for(auto it: adj[node]){
            if (it==parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it]>=tin[node] && parent!=-1) {
                    mark[node]=1;
                }
                child++;
            }
            else {
                low[node]=min(low[node], tin[it]);
            }
        }
        if(child>1 && parent==-1) mark[node]=1;
    }
public:
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
               dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.size()==0) return {-1};
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends