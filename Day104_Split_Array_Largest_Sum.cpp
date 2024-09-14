//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int countPartitions(int arr[], int N, int maxSum) {
        int partitions=1;
        long long subarraySum=0;
        for (int i=0; i<N; i++) {
            // insert element to current subarray
            if (subarraySum+arr[i]<=maxSum) {
                subarraySum+=arr[i];
            }
            else {
                //insert element to next subarray
                partitions++;
                subarraySum=arr[i];
            }
        }
        return partitions;
    }

    int splitArray(int arr[], int N, int K) {
        int low=*max_element(arr, arr+N);
        int high=accumulate(arr, arr+N, 0);
        
        while (low<=high) {
            int mid=(low+high)/2;
            int partitions=countPartitions(arr, N, mid);
            if (partitions>K) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends