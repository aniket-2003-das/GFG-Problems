//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    # define long long ll
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left=low;
        int right=mid+1;

        // Storing elements in temp array in a sorted manner.
        while (left<=mid && right<=high) {
            if (arr[left]<=arr[right]) temp.push_back(arr[left++]);
            else temp.push_back(arr[right++]);
        }
        while(left<=mid) temp.push_back(arr[left++]);
        while(right<=high) temp.push_back(arr[right++]);
        
        // transfering all elements from temporary to arr //
        for (int i=low; i<=high; i++) arr[i]=temp[i-low];
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int right=mid+1;
        int cnt=0;
        for (int i=low; i<=mid; i++) {
            while (right<=high && arr[i]>(2ll*arr[right])) right++;
            cnt+=(right-(mid+1));
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt=0;
        if (low>=high) return cnt;
        int mid=(low+high)/2 ;
        cnt+=mergeSort(arr, low, mid);
        cnt+=mergeSort(arr, mid+1, high);
        cnt+=countPairs(arr, low, mid, high); //Modification
        merge(arr, low, mid, high); // merging sorted halves
        return cnt;
    }

    int countRevPairs(int n, vector<int> arr){
        return mergeSort(arr, 0, n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends