class Solution {
  public:
    // Resursion By not Declaring Count. start print and then iterate Iterate N to 1 to print numbers.
    void printNos(int N) {
        // code here
        if (N==0) return;
        cout << (N) << " ";
        printNos(N-1);
    }
};