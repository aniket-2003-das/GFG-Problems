//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X){
        // code here
        int res=0, diff=INT_MAX;
        sort(A, A+N);
        
        for(int i=0; i<N-2; i++){
            int low=i+1;
            int high = N-1;
            
            while(low<high){
                int sum=A[i]+A[low]+A[high];
                
                if(sum==X) return sum;
                else if(sum<X) low++;
                else high--;
                
                if(abs(X-sum)<diff){
                    diff=abs(X-sum);
                    res=sum;
                }
            } 
        }
        return res;
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
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends