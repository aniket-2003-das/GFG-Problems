//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int i=0, j=0, c=0;
        bool flag;
        
        while (i<arr1.size() && j<arr2.size()) {
            c++;
            if (arr1[i]>arr2[j]) j++, flag=0;
            else i++, flag=1;
            if (c==k && flag==0) return arr2[j-1];
            else if(c==k && flag==1) return arr1[i-1];
        }
        
        while (i!=arr1.size()) {
            c++;
            i++;
            if(c==k) return arr1[i-1];
        }  
        
        while (j!=arr2.size()) {
            c++;
            j++;
            if(c==k) return arr2[j-1];
        }
        return 0;
        
        // Binary search
        // int n=a.size(), m=b.size();
        // if (m>n) return kthElement(k, b, a);
        // int left=k; //length of left half
    
        // int low=max(0, k-n), high=min(k, m);
        // while (low<=high) {
        //     int mid1=(low+high)>>1;
        //     int mid2=left-mid1;
        //     //calculate l1, l2, r1 r2;
        //     int l1=INT_MIN, l2=INT_MIN;
        //     int r1=INT_MAX, r2=INT_MAX;
        //     if (mid1<m) r1=a[mid1];
        //     if (mid2<n) r2=b[mid2];
        //     if (mid1-1>=0) l1=a[mid1-1];
        //     if (mid2-1>=0) l2=b[mid2-1];
    
        //     if (l1<=r2 && l2<=r1) return max(l1, l2);
    
        //     //eliminate the halves:
        //     else if (l1>r2) high=mid1-1;
        //     else low=mid1+1;
        // }
        // return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends