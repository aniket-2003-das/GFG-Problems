//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countTriplets(int Arr[], int N, int L, int R) {
        // code here
        sort(Arr, Arr+N);
        int count=0, i=0;
        
        while(i<N-2){
            int j=i+1;
            while(j<N-1){
                int sum = Arr[i]+Arr[j];
                int a, b;
                
                if(L-sum>Arr[j]) a=lower_bound(Arr, Arr+N, L-sum)-Arr;
                else a=j+1;
                
                if(a>=N){
                    j++;
                    continue;
                }
                
                if(R-sum>Arr[j]){
                    b=lower_bound(Arr, Arr+N, R-sum)-Arr;
                    if(b<N && Arr[b]==R-sum) b++;
                } 
                else b=a;
                count+=b-a; // Count valid triplets
                j++;
            }
            i++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}
// } Driver Code Ends