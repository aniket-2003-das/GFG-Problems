//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool isPrime(int num){
        for (int i=2; i<=sqrt(num); i++){
            if (num%i==0) return false;
        }
        return true;
    }
    
    int isTwistedPrime(int N) {
        // code here
        int N1 = N;
        int M=0;
        
        while(N1>0){
            M = M*10 + N1%10;
            N1/=10;
        }

        if(isPrime(N) && isPrime(M)) return 1;
        else return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isTwistedPrime(N) << "\n";
    }
}
// } Driver Code Ends