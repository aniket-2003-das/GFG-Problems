//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // bool dfs(int node, vector<int> graph[], vector<int> &vis, vector<int> &pathvis, vector<int> &check) {
    //     vis[node]=1;
    //     pathvis[node]=1;
    //     check[node]=0;

    //     for(auto it: graph[node]){
    //         if(!vis[it]){
    //             if(dfs(it, graph, vis, pathvis, check)) {
    //                 check[node]=0;
    //                 return 1;
    //             }
    //         }
    //         else if(pathvis[it]){
    //             check[node]=0;
    //             return 1;
    //         }
    //     }
    //     check[node]=1;
    //     pathvis[node]=0;
    //     return 0;
    // }
    
    // vector<int> eventualSafeNodes(int V, vector<int> graph[]) {
    //     vector<int> vis(V, 0);
    //     vector<int> pathvis(V, 0);
    //     vector<int> check(V, 0);
    //     vector<int> safeNodes;

    //     for(int i=0; i<V; i++){
    //         if(!vis[i]){
    //             dfs(i, graph, vis, pathvis, check);
    //         }
    //     }

    //     for(int i=0; i<V; i++){
    //         if(check[i]==1) safeNodes.push_back(i);
    //     }
    //     return safeNodes;
    // }
    
    vector<int> eventualSafeNodes(int V, vector<int> graph[]) {
        vector<vector<int>> adjRev(V);
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            // i->it
            // it->i
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends