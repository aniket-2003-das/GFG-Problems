class Solution{
    public:
    //use recursive function by not declare variable globally and locally in function input.
    // void printNos(int N, int current = 1) {
    //     if (current > N) return;
    //     cout << current << " ";
    //     printNos(N, current + 1);
    // }
    
    
    // Resursion By not Declaring Count. Iterate N to 1 and then start print.
    void printNos(int N)
    {
      if(N==0) return;
      printNos(N-1);
      cout<<N<<" ";
    }
    
    
    // Complete this function (Update Count Method)
    // int count = 1;
    // void printNos(int N)
    // {
    //     if (count > N) return;
    //     cout << count << " ";
    //     count++;
    //     printNos(N);
    // }
};