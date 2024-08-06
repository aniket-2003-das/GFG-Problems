//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int binarysearch(vector<int> &arr, int target) {
        // code here
        int start=0, end=arr.size()-1;
        int mid=(start+end)/2;
    
        while (start<=end) {
            if (arr[mid]==target) return mid;
            else if (arr[mid]<target) start=mid+1;
            else end=mid-1;
            mid=(start+end)/2;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int res = ob.binarysearch(arr, k);
        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends