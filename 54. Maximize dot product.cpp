/*
Maximize dot product
EasyAccuracy: 13.27%Submissions: 38K+Points: 2
Given two arrays a and b of positive integers of size n and m where n >= m, the task is to maximize the dot product by inserting zeros in the second array but you cannot disturb the order of elements.

Dot product of array a and b of size n is a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1].

Example 1:

Input: 
n = 5, a[] = {2, 3, 1, 7, 8} 
m = 3, b[] = {3, 6, 7}
Output: 
107
Explanation: 
We get maximum dot product after inserting 0 at first and third positions in second array.
Therefore b becomes {0, 3, 0, 6, 7}. 
Maximum dot product = 2*0 + 3*3 + 1*0 + 7*6 + 8*7 = 107.
Example 2:

Input: 
n = 3, a[] = {1, 2, 3}
m = 1, b[] = {4} 
Output: 
12 
Explanation: 
We get maximum dot product after inserting 0 at first and second positions in second array.
Therefore b becomes {0, 0, 4}. 
Maximum Dot Product = 1*0 + 2*0 + 3*4 = 12.
Your Task:  
You don't need to read input or print anything. Complete the function maxDotProduct() which takes n, m, array a and b as input parameters and returns the maximum value.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ m ≤n ≤ 103
1 ≤ a[i], b[i] ≤ 103


*/

// Intuition:
// - We use dynamic programming to solve this problem.
// - We define a recursive function `help` to calculate the maximum dot product.
// - In the `help` function, we consider two cases:
//     1. If we skip the current element of array `a` (by incrementing `i`), we call `help` recursively with `diff` decreased by 1.
//     2. If we include the current elements of arrays `a` and `b` in the dot product calculation, we call `help` recursively with `i` and `j` both incremented.
// - We store the result of subproblems in a 2D DP array to avoid redundant calculations.
// - Finally, we call the `help` function with initial parameters and return the result.

// Time Complexity: O(n*m), where n is the size of array `a` and m is the size of array `b`.
// Space Complexity: O(n*m), for the DP array.
class Solution{
public:
    // Helper function to calculate maximum dot product
    int help(int i, int j, int n, int m, int a[], int b[], int diff, vector<vector<int>> &dp){
        // Base case: If we reach the end of either array
        if(i == n || j == m)
            return 0;
        
        // If the result for the current subproblem is already calculated, return it
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int sum1 = 0, sum2 = 0;
        
        // Case 1: If we skip the current element of array `a`
        if(diff){
            sum1 = help(i+1, j, n, m, a, b, diff-1, dp);
        } 
        
        // Case 2: If we include the current elements of arrays `a` and `b`
        sum2 = a[i] * b[j] + help(i+1, j+1, n, m, a, b, diff, dp);
        
        // Store the result in DP array and return
        return dp[i][j] = max(sum1, sum2);
    }
    
    // Main function to find maximum dot product
    int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        // Initialize DP array with -1
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
        // Call the helper function with initial parameters
        return help(0, 0, n, m, a, b, n-m, dp);
    } 
};
