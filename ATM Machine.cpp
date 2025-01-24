#include <bits/stdc++.h>
using namespace std;

void Paa() {
    int N, K;
    cin>>N>>K;
    vector<int> arr(N, 0);
    
    for(int i=0; i<N; i++){
        cin>>arr[i];  
        if(arr[i]<=K) {
            K-=arr[i];
            cout<<1;
        }
        else cout<<0;
    }
    cout<<endl;
}

int main() {
	// your code goes here
    int T;
    cin>>T;
    while(T--) Paa();
}