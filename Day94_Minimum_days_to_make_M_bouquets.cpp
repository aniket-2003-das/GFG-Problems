//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int n=bloomDay.size();
        int cnt=0;
        int noOfB=0;
        // count number of bouquets:
        for (int i=0; i<n; i++) {
            if (bloomDay[i]<=day) cnt++;
            else {
                noOfB+=(cnt/k);
                cnt=0;
            }
        }
        noOfB+=(cnt/k);
        return noOfB>=m;
    }

    int solve(int m, int k, vector<int>& bloomDay) {
        long long val= m*1ll*k*1ll;
        int n=bloomDay.size();
        if (val>n) return -1; // impossible case.
        //find maximum and minimum:
        int mini=INT_MAX, maxi=INT_MIN;
        for (int i=0; i<n; i++) {
            mini=min(mini, bloomDay[i]);
            maxi=max(maxi, bloomDay[i]);
        }
        //apply binary search:
        int low=mini, high=maxi;
        while (low<=high) {
            int mid=(low+high)/2;
            if (possible(bloomDay, mid, m, k)) {
                high=mid-1;
            }
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
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends