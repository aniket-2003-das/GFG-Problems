//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution {
int timer = 0;
vector<int> tin, low;
vector<bool> inStack;
stack<int> st;
vector<vector<int>> sccs;

    void dfs(int node, vector<int> adj[]) {
        tin[node]=low[node]=timer++;
        st.push(node);
        inStack[node]=true;

        for(auto it: adj[node]) {
            if(tin[it]==-1) {
                dfs(it, adj);
                low[node]=min(low[node], low[it]);
            } 
            else if(inStack[it]) {
                low[node]=min(low[node], tin[it]);
            }
        }
        if(tin[node]==low[node]) {
            vector<int> scc;
            while(true) {
                int curr_node=st.top(); 
                st.pop();
                inStack[curr_node]=false;
                scc.push_back(curr_node);
                if (curr_node==node) break;
            }
            sort(scc.begin(), scc.end());
            sccs.push_back(scc);
        }
    }

public:
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        tin.assign(V, -1);
        low.assign(V, -1);
        inStack.assign(V, false);

        for (int i=0; i<V; i++) {
            if (tin[i]==-1) {
                dfs(i, adj);
            }
        }
        sort(sccs.begin(), sccs.end());
        return sccs;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends