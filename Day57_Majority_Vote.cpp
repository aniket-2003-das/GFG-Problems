//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& v){
        // Code here
        int cnt1=0, cnt2=0;
        int el1=INT_MIN, el2=INT_MIN;

        // Applying the Extended Boyer Moore's Voting Algorithm:
        for(int i=0; i<n; i++){
            if(cnt1==0 && el2!=v[i]){
                cnt1=1;
                el1=v[i];
            }
            else if(cnt2==0 && el1!=v[i]){
                cnt2=1;
                el2=v[i];
            }
            else if(v[i]==el1) cnt1++;
            else if(v[i]==el2) cnt2++;
            else{
                cnt1--, cnt2--;
            }
        }

        vector<int> ls; // list of answers
        cnt1=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(v[i]==el1) cnt1++;
            if(v[i]==el2) cnt2++;
        }
        int mini=int(n/3)+1;
        if(cnt1>=mini) ls.push_back(el1);
        if(cnt2>=mini) ls.push_back(el2);
        

        // if it is told to sort the answer array:
        // sort(ls.begin(), ls.end()); //TC --> O(2*log2) ~ O(1);
        if(ls.size()==0) ls.push_back(-1);
        return ls;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends