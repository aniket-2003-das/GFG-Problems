//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int First(vector<long long> nums, int target, int n){
        int low=0, high=n-1;
        int first=-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) first=mid, high=mid-1;
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return first;
    }

    int Last(vector<long long> nums, int target, int n){
        int low=0, high=n-1;
        int last=-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) last=mid, low=mid+1; 
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return last;        
    }
    
    pair<long,long> indexes(vector<long long> nums, long long target) {
        // code here
        int n=nums.size();
        return {First(nums,target,n), Last(nums,target,n)};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends