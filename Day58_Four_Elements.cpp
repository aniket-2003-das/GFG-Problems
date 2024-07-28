//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

bool find4Numbers(int A[], int n, int X);

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, i, x;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin>>x;
        cout << find4Numbers(a, n, x) << endl;

    }
    return 0;
}
// } Driver Code Ends
//User function Template for C++
bool find4Numbers(int A[], int n, int X){
    sort(A, A+n);
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--){
            int k=i+1;
            int l=j-1;
            while(k<l){
                int sum= A[i]+A[j]+A[k]+A[l];
                if(sum==X) return true;
                else if(sum<X) k++;
                else l--;
            }
        }
    }
    return false;  
}