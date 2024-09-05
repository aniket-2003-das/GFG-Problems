//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // int smallestDivisor(vector<int>& nums, int K) {
    int sumByD(vector<int> &arr, int div) {
        int n=arr.size();
        //Find the summation of division values:
        int sum=0;
        for (int i=0; i<n; i++) sum+=ceil((double)(arr[i])/(double)(div));
        return sum;
    }

    int smallestDivisor(vector<int>& arr, int limit) {
        int n=arr.size();
        if (n>limit) return -1;
        int low=1, high =*max_element(arr.begin(), arr.end());

        //Apply binary search:
        while (low<=high) {
            int mid=(low+high)/2;
            if (sumByD(arr, mid)<=limit) {
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends