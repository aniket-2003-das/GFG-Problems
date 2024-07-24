//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        int m=matrix.size(); // number of rows
        int n=matrix[0].size(); // number of columns
        vector<vector<int>> copy(matrix);

        for (int i=0; i<m*n; i++){
            int row=i/n;
            int col=i%n;

            if (copy[row][col]==0){
                int result=0;
                if (row>0){
                    result+=copy[row-1][col];
                    matrix[row-1][col]=0;
                }
                if(col>0){
                    result+=copy[row][col-1];
                    matrix[row][col-1]=0;
                }
                if(col+1<n){
                    result+=copy[row][col+1];
                    matrix[row][col+1]=0;
                }
                if(row+1<m){
                    result+=copy[row+1][col];
                    matrix[row+1][col]=0;
                }
                matrix[row][col]=result;
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends