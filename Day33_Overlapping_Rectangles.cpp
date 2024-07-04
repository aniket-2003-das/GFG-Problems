//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // L1 left top, R1 Right bottom
        int left1=L1[0];
        int top1=L1[1];
        int right1=R1[0];
        int bottom1=R1[1];

        // L2 left top, R2 Right bottom
        int left2=L2[0];
        int top2=L2[1];
        int right2=R2[0];
        int bottom2=R2[1];

       if(left1>right2 || right1<left2) return 0;
       else if(top1<bottom2 || bottom1>top2) return 0;
       else return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}
// } Driver Code Ends