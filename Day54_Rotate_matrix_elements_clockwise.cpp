//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> rotateMatrix(int M, int N, vector<vector<int>> Mat) {
        // we will be using 4 pointers top, left, right, bottom
        int top=0, left=0, right=N-1, bottom=M-1;
        
        while (top<bottom && left<right){
            int temp=Mat[top][left];
            // Rotate top row (left to right)
            for(int col=left; col<right; col++) swap(temp, Mat[top][col+1]);
            top++;
            // Rotate right column (top to bottom)
            for(int row=top-1; row<bottom; row++) swap(temp, Mat[row+1][right]);
            right--;
            // Rotate bottom row (right to left)
            for(int col=right+1; col>left; col--) swap(temp, Mat[bottom][col-1]);
            bottom--;
            // Rotate left column (bottom to top)
            for (int row=bottom+1; row>top; row--) swap(temp, Mat[row-1][left]);
            left++;
            // Place the last element at the new starting position
            Mat[top-1][left-1]=temp;
        }
        return Mat;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends