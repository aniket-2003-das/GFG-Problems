//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void rearrange(int arr[], int n) {
        // code here
        vector<int> pos, neg;
        for(int i=0; i<n; i++){
            if(arr[i]>=0) pos.push_back(arr[i]);
            else neg.push_back(arr[i]);
        }
        
        int i=0,j=0,k=0;
        int size_neg = neg.size(), size_pos = pos.size();
        
        while(j<size_pos && k<size_neg){
            if(i%2==0) arr[i] = pos[j++];
            else arr[i] = neg[k++];
            i++;
        }
        
        while(i<n){
            if(size_pos>size_neg) arr[i] = pos[j++];
            else arr[i] = neg[k++];
            i++;
        }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends