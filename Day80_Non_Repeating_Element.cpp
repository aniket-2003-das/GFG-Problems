//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int firstNonRepeating(vector<int>& arr) {
        // Complete the function
        unordered_map<int,int> ans;
        
        for(int i=0;i<arr.size();i++) ans[arr[i]]++;
    
        for(int i=0;i<arr.size();i++){
            int key = arr[i];
            auto temp = ans.find(key);
            if(temp->second == 1)
                return key;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.firstNonRepeating(nums) << endl;
    }
}

// } Driver Code Ends