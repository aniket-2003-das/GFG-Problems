//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void rotateMatrix(vector<vector<int>>& a, int n) {
	    for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(a[i][j], a[j][i]);
            }
        }
        
        for(int i=0; i<n; i++){
            int l=0;
            int r=n-1;
            while(l<r){
                swap(a[l][i], a[r][i]);
                l++;
                r--;
            }
        }
        return;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++) {
            vector<int> a;
            for (int j = 0; j < n; j++) {
                cin >> x;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        Solution ob;
        ob.rotateMatrix(arr, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends