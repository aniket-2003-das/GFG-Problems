//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    int idx = 0;
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        
        if(idx+k>=n){
            int i = idx, j = n-1;
            while(i<j){
                swap(arr[i],arr[j]);;
                i++;
                j--;
            }
            return;
        } 
        
        int i = idx, j=idx+k-1;
        while(i<j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        idx+=k;
        reverseInGroups(arr, n, k);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends