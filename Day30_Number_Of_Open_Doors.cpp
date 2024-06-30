//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int noOfOpenDoors(long long N) {
        // A door toggles its state each time its number is a multiple of i.
        // A door ends up being open if it is toggled an odd number of times.
        // Only square numbers have an odd number of divisors.
        // This is because the divisors of a non-square number come in pairs
        return sqrt(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.noOfOpenDoors(N) << endl;
    }
    return 0;
}
// } Driver Code Ends