//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends
//User function template for C++
// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> arr, int k) {
    //code here
    int n=arr.size();
    int low=0, high=n-1;

    while(low<=high) {
        int mid=(low+high)/2;
        //if mid points the target
        if (arr[mid]==k) return mid;

        //if left part is sorted:
        if (arr[low]<=arr[mid]) {
            //element exists:
            if (arr[low]<=k && k<=arr[mid]) high=mid-1;
            //element does not exist:
            else low=mid+1;
        }

        // if right part is sorted:
        else { 
            //element exists:
            if (arr[mid]<=k && k<=arr[high]) low=mid+1;
            //element does not exist:
            else high=mid-1;
        }
    }
    return -1;
}