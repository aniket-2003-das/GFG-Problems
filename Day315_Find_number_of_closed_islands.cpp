//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
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

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        DisjointSet ds(N*M);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(matrix[i][j]==0) continue;
                int val = i*M + j;
                for(int k=0; k<4; k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    int newval = nr*M + nc;
                    if(nr<0 || nr>=N || nc<=0 || nc>=M) continue;
                    if(matrix[nr][nc]==1 && ds.findUPar(val)!=ds.findUPar(newval)){
                        ds.unionByRank(val,newval);
                    }
                }
            }
        }
        
        int comp=0;
        set<int>pre; 
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                int temp = i*M + j;
                if(matrix[i][j]==1 && ds.findUPar(temp)==temp){
                    comp++;
                    pre.insert(temp);
                }
            }
        }
        // firstrow
        for(int j=0; j<M; j++){
            int q = ds.findUPar(j);
            if(matrix[0][j]==1 && pre.find(q)!=pre.end()){
                comp--;
                pre.erase(q);
            }
        }
        // lastrow
        for(int j=0; j<M; j++){
            int q = ds.findUPar((N-1)*M+j);
            if(matrix[N-1][j]==1 && pre.find(q)!=pre.end()){
                comp--;
                pre.erase(q);
            }
        }
        // firstcol
        for(int i=1; i<N-1; i++){
            int q = ds.findUPar(i*M);
            if(matrix[i][0]==1 && pre.find(q)!=pre.end()){
                comp--;
                pre.erase(q);
            }
        }
        // lastcol
        for(int i=1; i<N-1; i++){
            int q = ds.findUPar(i*M + (M-1));
            if(matrix[i][M-1]==1 && pre.find(q)!=pre.end()){
                comp--;
                pre.erase(q);
            }
        }
        return comp;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
	
	return 0;
	
}


// } Driver Code Ends