//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr1,arr2 : the arrays
    // n, m: size of arrays
    // Set method dont use un ordered set can also be done by map.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {

        set<int> st;
        for(int i=0; i<n; i++)  st.insert(arr1[i]);
        for(int i=0; i<m; i++)  st.insert(arr2[i]);
        vector<int> temp;
        for(auto it : st){
            temp.emplace_back(it);
        }
        return temp;
        
        // 2 Pointer Approach
        // int i = 0, j = 0;
        // vector < int > Union;
        
        // while (i<n && j<m){
        //     if(arr1[i] <= arr2[j]){
        //         if(Union.size()==0 || Union.back()!=arr1[i])   Union.push_back(arr1[i]);
        //         i++;
        //     } 
        //     else{
        //         if(Union.size()==0 || Union.back()!=arr2[j])   Union.push_back(arr2[j]);
        //         j++;
        //     }
        // }
        // while(i<n){
        //     if(Union.back()!=arr1[i])   Union.push_back(arr1[i]);
        //     i++;
        // }
        // while(j<m){
        //     if(Union.back()!=arr2[j])   Union.push_back(arr2[j]);
        //     j++;
        // }
        // return Union;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends