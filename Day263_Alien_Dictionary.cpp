//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>> &adj){
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in toposort so remove it form indegree.
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return topo;
    }

    string findOrder(vector<string> &words) {
        // code here
        int N = words.size();
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        unordered_set<char>present_chars;
        
        // Mark all unique characters as present.
        for(auto it: words) {
            for (char c: it) {
                present_chars.insert(c);
            }
        }
        
        for(int i=0; i<N-1; i++){
            string S1 = words[i];
            string S2 = words[i+1];
            int len = min(S1.size(), S2.size());
            // Check for invalid ordering (prefix issue)
            if (S1.size()>S2.size() && S1.substr(0, len)==S2.substr(0, len)) return "";
            
            for(int ptr=0; ptr<len; ptr++){
                if(S1[ptr]!=S2[ptr]){
                    adj[S1[ptr]-'a'].push_back(S2[ptr]-'a');
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(26, adj);
        string ans = "";
        for(auto it: topo){
            // Include only present characters
            if(present_chars.count(it+'a')) ans=ans+char(it+'a');
        }
        
        // If order includes all present characters, return it; otherwise, return ""
        return (ans.size()==present_chars.size()) ? ans:"";
    }
    
    
    
    
    
};

//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends