#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    string compareNM(int n, int m){
        if (m > n){
            return "lesser";
        }
        else if (n > m){
            return "greater";
        }
        else {
            return "equal";
        }

    }
};