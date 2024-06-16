//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        if(x==1) return 1;
        long long int start=0;
        long long int end=x/2;
        
        while(start<=end){
            long long int mid=start+(end-start)/2;
            if(mid*mid==x) return mid;
            if( (mid*mid<x) && ((mid+1)*(mid+1)>x) ) return mid;
            
            else if( (mid*mid<x) && ((mid+1)*(mid+1)<=x) ){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends