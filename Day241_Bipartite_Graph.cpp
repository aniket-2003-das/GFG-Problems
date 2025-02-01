//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    // bool check(int start, vector<vector<int>>& graph, vector<int> &colour){
    //     queue<int> q;
    //     q.push(start);
    //     colour[start] = 0;
        
    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();
    //         for(auto it: graph[node]){
    //             if(colour[it]==-1){
    //                 colour[it]=!colour[node];
    //                 q.push(it);
    //             }
    //             else if(colour[it]==colour[node]) return 0;
    //         }
    //     }
    //     return 1;
    // }

    // bool isBipartite(vector<vector<int>>& graph) {
    //     int n = graph.size();
    //     vector<int> colour(n, -1);
    //     for(int i=0; i<n; i++){
    //         if(colour[i]==-1){
    //             if(check(i, graph, colour)==0) return 0;
    //         }
    //     }
    //     return 1;
    // }
    
    
     bool check(int node, int col, vector<vector<int>>& graph, vector<int> &colour){
        colour[node] = col;
        for(auto it: graph[node]){
            if(colour[it]==-1){
                if(check(it, !col, graph, colour)==0) return 0;
            }
            else if(colour[it]==col) return 0;
        }
        return 1;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);
        for(int i=0; i<n; i++){
            if(colour[i]==-1){
                if(check(i, 0, graph, colour)==0) return 0;
            }
        }
        return 1;
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
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends