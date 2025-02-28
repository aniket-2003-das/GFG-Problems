//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    // vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    //     // Code here
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //     vector<int> distTo(adj.size(), 1e9);
    //     distTo[src]=0;
    //     pq.push({0, src});
        
    //     while(!pq.empty()){
    //         int node = pq.top().second;
    //         int dis = pq.top().first;
    //         pq.pop();
    //         for(auto it: adj[node]){
    //             int V = it.first;
    //             int W = it.second;
    //             if(dis+W < distTo[V]){
    //                 distTo[V] = dis + W;
    //                 pq.push({dis+W, V});
    //             }
    //         }
    //     }
    //     return distTo;
    // }
    
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        set<pair<int, int>> st;
        vector<int> distTo(adj.size(), 1e9);
        distTo[src]=0;
        st.insert({0, src});
        
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for(auto it: adj[node]){
                int adjtnode = it.first;
                int W = it.second;
                if(dis+W < distTo[adjtnode]){
                    // erase it exist
                    if(distTo[adjtnode]!=1e9) st.erase({distTo[adjtnode], adjtnode});
                    distTo[adjtnode] = dis + W;
                    st.insert({distTo[adjtnode], adjtnode});
                }
            }
        }
        return distTo;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends