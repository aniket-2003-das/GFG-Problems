//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int k) {
        // complete the function
        int n=arr.size();
        int low=0, high=n-1;
    
        while(low<=high) {
            int mid=(low+high)/2;
            //if mid points the target
            if (arr[mid]==k) return mid;
    
            //if left part is sorted:
            if (arr[low]<=arr[mid]) {
                //element exists:
                if (arr[low]<=k && k<=arr[mid]) high=mid-1;
                //element does not exist:
                else low=mid+1;
            }
    
            // if right part is sorted:
            else { 
                //element exists:
                if (arr[mid]<=k && k<=arr[high]) low=mid+1;
                //element does not exist:
                else high=mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends