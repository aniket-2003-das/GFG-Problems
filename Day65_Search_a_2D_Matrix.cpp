//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int matSearch (vector <vector<int>> &matrix, int N, int M, int X){
	    // your code here
        if (N==0) return 0; 
        
        int i=0, j=M-1;  

        while (i<N && j>=0) {
            if (matrix[i][j]==X) return 1; 
            else if (matrix[i][j]>X) j--;  
            else i++;
        }
        return 0; 
	}
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends