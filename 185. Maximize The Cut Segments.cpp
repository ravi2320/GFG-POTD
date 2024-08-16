/*
Maximize The Cut Segments
Difficulty: MediumAccuracy: 24.29%Submissions: 224K+Points: 4
Given an integer n denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum. Return the maximum number of cut segments possible.

Note: if no segment can be cut then return 0.

Examples:

Input: n = 4, x = 2, y = 1, z = 1
Output: 4
Explanation: Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
Input: n = 5, x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.
Expected Time Complexity : O(n)
Expected Auxiliary Space: O(n)

Constraints
1 <= n, x, y, z <= 104
*/

/*
Intuition:
- This problem is a variation of the unbounded knapsack problem, where the goal is to maximize the number of cuts that can be made on a segment of length `n` using segments of lengths `x`, `y`, or `z`.
- The problem can be solved using dynamic programming (DP) where the state `dp[i]` represents the maximum number of segments that can be obtained from a segment of length `i`.

Time Complexity:
- The solution has a time complexity of O(n), where `n` is the length of the segment.
- This is because we iterate over the segment length and for each length, we calculate the possible number of cuts by checking the three possible segment sizes.

Space Complexity:
- The space complexity is O(n) due to the DP array `dp` of size `n+1` used to store intermediate results.
*/

class Solution
{
    public:
    // Function to find the maximum number of cuts using recursion with memoization.
    int solve(int n, int x, int y, int z, vector<int> &dp){
        
        if(n == 0) return 0;  // Base case: no length to cut, so 0 cuts.
        
        if(n < 0) return INT_MIN;  // If the length becomes negative, return a large negative number to indicate invalid cuts.
        
        if(dp[n] != -1){
            return dp[n];  // If already computed, return the stored result.
        }
        
        // Recursively compute the maximum cuts by considering cutting lengths x, y, or z.
        int a = solve(n-x, x, y, z, dp) + 1;
        int b = solve(n-y, x, y, z, dp) + 1;
        int c = solve(n-z, x, y, z, dp) + 1;
        
        // Store and return the maximum of the three possibilities.
        return dp[n] = max(a, max(b, c));
    }
    
    // Function to find the maximum number of cuts using tabulation.
    int solveTab(int n, int x, int y, int z){
        vector<int> dp(n+1, INT_MIN);  // Initialize dp array with a large negative number.
        
        dp[0] = 0;  // Base case: No cuts are needed for length 0.
        
        for(int i=1; i<=n; i++){
            // Check if the segment can be cut by length x, y, or z, and take the maximum number of cuts possible.
            if(i-x >= 0)
                dp[i] = max(dp[i], dp[i-x] + 1);
                
            if(i-y >= 0)
                dp[i] = max(dp[i], dp[i-y] + 1);
                
            if(i-z >= 0){
                dp[i] = max(dp[i], dp[i-z] + 1);
            }
        }
        
        return dp[n];
    }

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Uncomment the following lines to use the recursive memoization solution.
        // vector<int> dp(n+1, -1);
        // int ans = solve(n, x, y, z, dp);
        
        // Using the tabulation method to find the answer.
        int ans = solveTab(n, x, y, z);
        
        // If the result is negative, it means no cuts were possible, so return 0.
        return ans < 0 ? 0 : ans;
    }
};
