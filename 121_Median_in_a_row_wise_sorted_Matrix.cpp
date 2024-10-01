//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int upperBound(vector<int> mat, int num) {
        int n=mat.size();
        int low=0, high=n-1;
        int cnt=n;

        while (low<=high) {
            int mid=low+(high-low)/2;
            if (mat[mid]>num) {
                cnt=mid;
                high=mid-1;
            } 
            else low=mid+1;
        }
        return cnt;
    }

    int NoOfSmallerNum(vector<vector<int>> &mat, int num) {
        int n=mat.size();
        int cnt=0;
        for (int i=0; i<n; i++) cnt+=upperBound(mat[i], num);
        return cnt;
    }
    
    int median(vector<vector<int>> &mat, int R, int C){
        // code here
        int low=INT_MAX;
        int high=INT_MIN;

        for (int i=0; i<R; i++) {
            if (mat[i][0]<low) low=mat[i][0];
            if (mat[i][C-1]>high) high=mat[i][C-1];
        }

        int req=(R*C)/2;
        int ans=-1; 
        while (low <= high) {
            int mid=low+(high-low)/2;
            int smallernum=NoOfSmallerNum(mat, mid);

            if (smallernum>req) {
                ans=mid; 
                high=mid-1;
            } 
            else low=mid+1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends