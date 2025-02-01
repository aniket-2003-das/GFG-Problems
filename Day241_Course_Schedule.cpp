//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:  
    bool dfs(vector<vector<int>>& preList, int node, vector<int>& vis, vector<int>& ans){
        if (vis[node]==1) return true;
        if (vis[node]==2) return false;
        vis[node]=1;

        for(int it: preList[node]) {
            if(dfs(preList, it, vis, ans)) {
                return true; 
            }
        }
        vis[node]=2;
        ans.push_back(node);
        return false;
    }
    
    vector<int> findOrder(int numCourses, int m, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preList(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> ans;

        for(auto it: prerequisites) {
            preList[it[0]].push_back(it[1]);
        }
        for(int i=0; i<numCourses; i++) {
            if (vis[i]==0) {
                if (dfs(preList, i, vis, ans)) return {};
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends