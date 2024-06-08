class Solution {
  public:
    int count = 1;
    void printGfg(int N) {
        // Code here
        if (N < count) return;
        cout << "GFG ";
        count++;
        printGfg(N);
        
    }
};