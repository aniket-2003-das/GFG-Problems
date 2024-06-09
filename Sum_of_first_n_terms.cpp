class Solution {
  public:
    long long ans = 0;
    long long sumOfSeries(long long n) {
        // code here
        if (n == 0) return ans;
        ans = ans + n*n*n;   
        sumOfSeries(n-1);
    }
};