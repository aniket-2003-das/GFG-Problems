//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution{
public:
    vector<int> findSubarray(int n, int a[]){
        int start=0;
        int idx1=0, idx2=0; // Idx1 is Possible start index for current subarray
        int sum=0;
        int mxlen=0;
        int mxsum=INT_MIN;

        for(int i=0; i<n; i++){
            if(a[i]>=0){
                sum+=a[i];
                int nlen=i-idx1+1;
                if (sum>mxsum || (sum==mxsum && nlen>mxlen) ) {
                    mxsum=sum;
                    start=idx1;
                    idx2=i;
                    mxlen=nlen;
                }
            } 
            else{
                sum=0;
                idx1=i+1;
            }
        }

        vector<int> ans;
        if (mxsum==INT_MIN) return {-1};
        for (int i=start; i<=idx2; i++) ans.push_back(a[i]);
        return ans;
    }
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(n, a);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends