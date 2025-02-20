//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>>& adj) {
    //     vis[node]=1;
    //     for(auto it: adj[node]){
    //         if(!vis[it]) dfs(it, vis, st, adj);
    //     }
    //     st.push(node);
    // }
    // // Function to return list containing vertices in Topological order.
    // vector<int> topologicalSort(vector<vector<int>>& adj) {
    //     // Your code here
    //     int N = adj.size();
    //     vector<int> vis(N, 0);
    //     stack<int> st;
        
    //     for(int i=0; i<N; i++){
    //         if(!vis[i]){
    //             dfs(i, vis, st, adj);
    //         }
    //     }
        
    //     vector<int> ans;
    //     while(!st.empty()){
    //         ans.push_back(st.top());
    //         st.pop();
    //     }
    //     return ans;
    // }
    
    
    // Kahn's Algorithm | Topological Sort Algorithm | BFS.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int N = adj.size();
        vector<int> indegree(N, 0);
        for(int i=0; i<N; i++){
            for(auto it: adj[i]) indegree[it]++;
        }
        
        queue<int> q;
        for(int i=0; i<N; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            // if node is in topo sort
            // so pls remove it from indegree
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return topo;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends