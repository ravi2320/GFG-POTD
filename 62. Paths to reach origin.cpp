/*
Paths to reach origin
MediumAccuracy: 53.93%Submissions: 42K+Points: 4
Matrix Partners India: Exclusive Job-A-Thon | Apply to 15+ Companies via 1 Hiring Challenge | Starting from 29th April onwards

banner
You are standing on a point (x, y) and you want to go to the origin (0, 0) by taking steps either left or down i.e. from each point you are allowed to move either in (x-1, y) or (x, y-1). Find the number of paths from point to origin.

Example 1:

Input:
x = 3, y = 0 
Output: 
1
Explanation: Path used was -  (3,0)  --> ( 2,0) --> (1,0) --> (0,0).We can see that there is no other path than this, so we return 1.
Example 2:

Input:
x = 3, y = 6
Output: 
84 
Explanation:
There are total 84 possible paths.
Your Task:
Since this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function ways() that takes integer x and y as parameters and returns the total number of paths from point(x,y) to the origin(0,0) % 1000000007.

Expected Time Complexity: O(x*y).
Expected Auxiliary Space: O(x*y).

Constraints:
0 ≤ x, y ≤ 500


*/

// Intuition:
// This class provides a solution to find the number of ways to reach the bottom-right corner of a grid
// starting from the top-left corner, with the restriction that you can only move right or down at each step.
// It uses dynamic programming to efficiently compute the number of ways for each position in the grid.

// Time Complexity: O(x * y)
// - 'x' and 'y' are the dimensions of the grid.
// - The algorithm computes the number of ways for each position in the grid once,
//   resulting in a time complexity proportional to the number of grid cells.

// Space Complexity: O(x * y)
// - The algorithm uses a 2D dynamic programming array of size (x+1) * (y+1) to store intermediate results.

#include <vector>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7; 

    // Helper function to recursively compute the number of ways
    int help(int x, int y, vector<vector<int>> &dp) {
        // Base cases: reaching top-left corner or moving out of bounds
        if (x == 0 && y == 0)
            return 1;
        if (x < 0 || y < 0)
            return 0;
            
        // If already computed, return the stored result
        if (dp[x][y] != -1)
            return dp[x][y];
        
        // Recursive calls to compute the number of ways
        int a = help(x - 1, y, dp); // Move down
        int b = help(x, y - 1, dp); // Move right
        
        // Store the result in the DP table and return
        return dp[x][y] = (a + b) % mod;
    }

    // Function to find the number of ways to reach the bottom-right corner
    int ways(int x, int y) {
        // Initialize a DP table with all elements set to -1
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        // Start the recursive computation from the top-left corner
        return help(x, y, dp);
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    int x = 3, y = 3;
    cout << "Number of ways to reach (" << x << ", " << y << "): " << obj.ways(x, y) << endl; // Output: 6
    return 0;
}
