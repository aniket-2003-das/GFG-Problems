//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pairCount(int x, int y){
        // code here
        int target=x*y;
        int count=0;
        int i;
        
        for(i=1; i*i<target ;i++){
            if(target%i==0){
                if(__gcd(i, target/i)==x){
                      count=count+2 ;
                }
            }
        }
        
        if(target%i==0){
            if(__gcd(i,target/i)==x && i==(target/i)) {
                count++ ;
            }
        }
        return count ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y;
        cin>>x>>y;
        
        Solution ob;
        cout<<ob.pairCount(x, y)<<endl;
    }
    return 0;
}
// } Driver Code Ends