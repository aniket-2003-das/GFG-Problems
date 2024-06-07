class Solution {
  public:
    double switchCase(int choice, vector<double> &arr) {
        switch (choice) {
            case 1:
                return M_PI*arr[0]*arr[0];
                break;
            case 2:
                return arr[0]*arr[1];
                break;
        }
    }
};