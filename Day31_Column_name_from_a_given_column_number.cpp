//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // (uppercase alphabets) range from 65 to 90.
        string str = "";
        int rem_num;
        
        while(n){
            rem_num = n%26;
            if(rem_num==0){
                n--;
                str+='Z';
            }
          
            else str+=char(rem_num+64);
            n/=26;
            
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends