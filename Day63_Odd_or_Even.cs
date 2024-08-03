//{ Driver Code Starts
// Initial Template for C#

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
 
namespace DriverCode {

class GFG {
    static void Main(string[] args) {
        int testcases; // Taking testcase as input
        testcases = Convert.ToInt32(Console.ReadLine());
        while (testcases-- > 0) // Looping through all testcases
        {
            int N = Convert.ToInt32(Console.ReadLine()); // Input for size of
            Solution obj = new Solution();
            string res = obj.oddEven(N);
            Console.Write(res);
            Console.Write("\n");
        }
    }
}
}

// } Driver Code Ends
// User function Template for C#
class Solution {
    // Complete this function
    // Function to return "EVEN" or "ODD" based on the number.
    public string oddEven(int N) {
        // Check if the number is even or odd
        if (N % 2 == 0) return "even";
        else return "odd";
    }
}