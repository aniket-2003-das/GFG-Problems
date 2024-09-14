//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int countPainters(int boards[], int n, long long time, int k) {
        int painters=1;
        long long boardsPainter=0;
        for (int i=0; i<n; i++) {
            if (boardsPainter+boards[i]<=time) boardsPainter+=boards[i];
            else {
                painters++;
                boardsPainter=boards[i];
                if (painters>k) return painters; // Early termination if painters exceed k.
            }
        }
        return painters;
    }
    
    long long minTime(int boards[], int n, int k) {
        long long low=*max_element(boards, boards+n);
        long long high=accumulate(boards, boards+n, 0LL); // Ensure accumulation as long long
    
        while (low<=high) {
            long long mid=low+(high-low)/2;
            int painters=countPainters(boards, n, mid, k);
            if (painters<=k) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends