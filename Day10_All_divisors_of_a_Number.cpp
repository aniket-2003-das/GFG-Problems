//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void print_divisors(int n) {
        // Code here.
        vector <int> div;
        int N = sqrt(n);
        for(int i=1; i<=N; i++){
            if (n%i==0){
	            div.push_back(i);
	            if (i != n / i) { 
                    div.push_back(n / i);
	            }
            }
        }
        sort(div.begin(), div.end());
        for(int i = 0; i<div.size(); i++){
            cout << div[i] << " ";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        ob.print_divisors(n);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends