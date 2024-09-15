//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int fun(int n){
        if(n==0) return 0;
        return (n%10)*(n%10) + fun(n/10);
    }
    int isHappy(int N){
        // code here
        unordered_map<int,bool> visited;
        while(1) {
            int k=fun(N);
            if (visited[k]) return 0;
            else { 
                visited[k]=true;
                if(k==1) return 1;
                N=k;
            }
        }
        return 0;
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
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends