class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // long long gcd = 1;
        // vector <long long> v;
        // while(gcd <= A){
        //     if (A%gcd!=0 && B%gcd!=0){
        //         gcd++;
        //     }
        // }
        // long long lcm = (A*B)/gcd;
        // v.emplace_back(lcm);
        // v.emplace_back(gcd);
        // return v;
        
        long long a = A; 
        long long b = B;
        while (a>0 && b>0){
            if(a > b){
                a = a%b;
            }
            else{
                b = b%a;
            }
        }
        long long gcd;
        if (a == 0){
            gcd = b;
        }
        else{
            gcd = a;
        }
        long long lcm = (A*B)/gcd;
        return {lcm,gcd};
    }
};