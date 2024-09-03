//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool possible(vector<int> piles, int mid, int h){
        long long hours=0;
        for(int i=0; i<piles.size(); i++){
            hours+=piles[i]/mid;
            piles[i]%=mid;
            if(piles[i]>0) hours++;
            if(hours>h) return false;
        }
        return true;
    }

    int KoKoEat(vector<int>& piles, int h) {
        int min=1;
        int max=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(min<=max){
            int mid=(min+max)/2;
            if(possible(piles, mid, h)){
                ans=mid;
                max=mid-1;
            }
            else min=mid+1;
        }
        return ans;
    }
};





//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;

        cout << ob.KoKoEat(arr, k);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends