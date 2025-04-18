//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// class Solution {
// public:
    // void traversal(int node, vector<vector<int>>& isConnected, vector<int>& visited) {
    //     visited[node]=1;
    //     for (int i=0; i<isConnected[node].size(); i++) {
    //         if (isConnected[node][i]==1 && !visited[i]) {
    //             traversal(i, isConnected, visited);
    //         }
    //     }
    // }

    // int numProvinces(vector<vector<int>> isConnected, int V) {
    //     // code here
    //     vector<int> visited(V, 0);
    //     int cnt=0;

    //     for(int i=0; i<isConnected.size(); i++){
    //         if(!visited[i]){
    //             cnt++;
    //             traversal(i, isConnected, visited);
    //         }
    //     }
    //     return cnt;
    // }
// };
    
class Solution {
public:
    int numProvinces(vector<vector<int>> isConnected, int V) {
        DisjointSet ds(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(isConnected[i][j]==1){
                    ds.unionBySize(i, j);
                }
            }
        }
        int cnt=0;
        for(int i=0; i<V; i++){
            // if(ds.findUPar(i)==i) cnt++;
            if(ds.parent[i]==i) cnt++;
            
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