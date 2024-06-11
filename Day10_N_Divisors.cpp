//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
// public:
//     int noOfDivisors(int x){
//         int count = 0;
//         for(int i=1; i<=sqrt(x); i++){
//             if (x%i==0){
//                 count++;
//                 if (i != x/i) { 
//                     count++;
// 	            }
//             }
//         }
//         return count;
//     }
//     int count(int N){
//         // code here
//         int output=0;
//         for(int i=1; i<=N; i++){
//             if(noOfDivisors(i)%2==1){
//                 output++;
//             }
//         }
//         return output;
//     }


public:
    int count(int N){
        // The number of perfect squares less than or equal to N is floor(sqrt(N))
        return floor(sqrt(N));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends