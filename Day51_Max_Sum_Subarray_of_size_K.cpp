//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &Arr , int N){
        // code here 
    long sum=0;
    long ans=LONG_MIN;
    
    for(int i=0; i<k; i++) sum+=Arr[i];
    ans=sum;
    
    for(int i=k;i<N;i++){
        sum+=Arr[i];
        sum-=Arr[i-k];
       if(sum>ans) ans=sum;
    }
    return ans;
    }
};
 
//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends