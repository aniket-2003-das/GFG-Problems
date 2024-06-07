class Solution
{
public:
    #define ll long long
    long long sumOfDivisors(int N)
    {
        // long long sum = 0;
        // long long sum1 = 0;
        // int j=1;
        // while(j<=N){
        //     for(int i=1;i<=j;i++){
        //         if(j%i==0){
        //             sum = sum + i;
        //         }
        //     }
        //     sum1=sum1+sum;
        //     sum=0;
        //     j++;
        // }
        // return sum1;
        
        
        
       /* vector<long long> divisorSum(N, 0);
        // Precompute the sum of divisors for each number up to N
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j ++) {
                if (i%j==0){
                    divisorSum[i-1] += j;
                }
            }
        }
        // Calculate the sum of all sums of divisors
        long long totalSum = 0;
        for (int i = 1; i <= N; i++) {
            totalSum = totalSum + divisorSum[i-1];
        }
        return totalSum;*/
        
        
        
        long long ans=0;
        for(int i=1; i<=N; i++){
            ans = ans + i*(N/i);  //Algorithm of this line decreases complexity
        }
        return ans;
    }
};