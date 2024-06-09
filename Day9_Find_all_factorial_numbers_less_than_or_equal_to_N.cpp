//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long number = 1;
    long long factorial = 1;
    vector<long long> factorials;
    
    vector<long long> factorialNumbers(long long N)
    {
        if (factorial <= N){
            factorials.push_back(factorial);
            number = number + 1;
            factorial = factorial*number;
            factorialNumbers(N);
        }
        if (factorial > N) return factorials;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends