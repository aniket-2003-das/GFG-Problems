class Solution{
public:
    int evenlyDivides(int N){
        int temp = N;
        int count = 0;
        int digit;
        while (N>=1) {
            digit = (N%10);
            if(digit > 0){
                if (temp%digit == 0){
                    count++;
                }
            }
            N = N/10;
        }
        return count;
    }
};