//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int remove_duplicate(vector<int> &arr) {
        // code here
        // set<int> st;
        // for(int i=0; i<arr.size(); i++){
        //     st.insert(arr[i]);
        // }
        // int size = st.size();
        // int index=0;
        // for(auto it : st){
        //     arr[index]=it;
        //     index++;
        // }
        // return size;
        
        
        // 2 pointer approach.
        int i=0;
        for(int j=0; j<arr.size(); j++){
            if(arr[j]!=arr[i]){
                arr[i+1]=arr[j];
                i++;
            }
        }
        return i+1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.remove_duplicate(arr);
        for (int i = 0; i < ans; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends