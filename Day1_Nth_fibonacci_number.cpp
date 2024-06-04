#include<bits/stdc++.h>
using namespace std;

int main()
{
        int a = 1;
        int b = 1;
        int n, result;

        cin>>n;

        if (n == 1 || n == 2) {
                result = 1;
        }
        else{
                for (int i = 3; i <= n; i++) {
                result = a + b;
                a = b;
                b = result;
                }
                result = result;
        }
        cout << result;
        return 0;
}
