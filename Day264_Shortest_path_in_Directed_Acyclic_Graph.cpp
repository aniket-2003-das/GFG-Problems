//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    void topoSort(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st){
        vis[node]=1;
        for(auto it: adj[node]){
            int v = it.first;
            if(!vis[v]) topoSort(v, adj, vis, st);
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);

        for(int i=0; i<E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        vector<int> vis(V, 0);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]) topoSort(i, adj, vis, st);
        }
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if (dist[node] != 1e9) {
                for(auto it: adj[node]){
                    int V = it.first;
                    int wt = it.second;
                    if(dist[node]+wt<dist[V]) dist[V] = wt + dist[node];
                }
            }
        }
        for(int i=0; i<V; i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends