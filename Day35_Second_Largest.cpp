//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        // int n=arr.size();
        // int large1=INT_MIN;
        // int large2=INT_MIN;

        // for(int i=0;i<n;i++) large1=max(large1,arr[i]);
        // for(int i=0;i<n;i++){
        //     if(arr[i]>large2 && arr[i]!=large1) large2=arr[i];
        // }
        // return large2;
        
        
        
        if(arr.size()<2) return -1;
        
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=0;i<arr.size();i++){
            if(arr[0]!=arr[i]){
                return arr[i];
            }
        }
        return -1;
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
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends