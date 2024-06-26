//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	int isDivisible(string s){
	    
        int decimalNumber = 0;
     
        for(char c : s) {
            decimalNumber = decimalNumber*2 + (c-'0');
            decimalNumber %= 3;  // Keep only the remainder 
        }
        
        if(decimalNumber==0) return 1;
        return 0;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends