//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
	int findK(vector<vector<int>> &a, int n, int m, int k){
        int left=0, top=0, right=m-1, bottom=n-1;
        int ind=0;
        while(1){
            if(left>right) break;
            for (int i=left; i<=right; i++){
                ind++;
                if(ind==k) return a[top][i];
                //   arr.push_back(a[top][i]);
            }
            top++;
            
            
            if(top>bottom) break;
            for(int i=top; i<=bottom; i++){
                ind++;
                if(ind==k) return a[i][right];
                //   arr.push_back(a[i][right]);
            }
            right--;
            
            
            if(left>right) break;
            for(int i=right; i>=left; i--) {
                ind++;
                if(ind==k) return a[bottom][i];
                //   arr.push_back(a[bottom][i]);
            }
            bottom--;
            
            
            if(top>bottom) break;
            for(int i=bottom; i>=top; i--){
                ind++;
                if(ind==k) return a[i][left];
                //   arr.push_back(a[i][left]);
            }
            left++;
        }
        return -1;
	}
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends