//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int findDays(int weights[], int n, int cap) {
        int days=1; 
        int load=0;
        for (int i=0; i<n; i++) {
            if (load+weights[i]>cap) {
                days+=1; 
                load=weights[i];
            }
            //load the weight on the same day.
            else load+=weights[i];
        }
        return days;
    }

    int leastWeightCapacity(int weights[], int n, int days) {
        int low=*std::max_element(weights, weights + n);
        int high=std::accumulate(weights, weights + n, 0);

        while (low <= high) {
            int mid=(low+high)/2;
            int numberOfDays=findDays(weights, n, mid);
            if (numberOfDays<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, D;
        cin >> N;

        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        cin >> D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr, N, D) << endl;
    }
    return 0;
}
// } Driver Code Ends