/*
Sum of first n terms
BasicAccuracy: 23.17%Submissions: 72K+Points: 1
Get Internship at GfG by submitting your Entries in: Data Science Blogathon

banner
Given an integer n, calculate the sum of series 13 + 23 + 33 + 43 + … till n-th term.

Example 1:

Input:
n=5
Output:
225
Explanation:
13+23+33+43+53=225
Example 2:

Input:
n=7
Output:
784
Explanation:
13+23+33+43+53+63+73=784

Your Task:
You don't need to read input or print anything. Your task is to complete the function sumOfSeries() which takes the integer n as a parameter and returns the sum of the cubes of the first n natural numbers.


Expected Time Complexity: O(1)
Expected Auxillary Space: O(1)


Constraints:
1<=n<=50000
*/

// Intuition:
// - To find the sum of the series 1^3 + 2^3 + 3^3 + ... + n^3 using recursion.
// - The base case is when n is 1, where the sum is simply 1^3 = 1.
// - For each recursive call, we calculate the cube of the current number n and add it to the result of the sum for (n-1).

// Approach:
// - Use a recursive function to compute the sum of cubes from 1 to n.
// - The function `sumOfSeries` calls itself with (n-1) and adds the cube of n to the result.
// - This ensures that all cubes from 1 to n are added together.

// Time Complexity: O(n)
// - The function is called n times, where n is the input number.

// Space Complexity: O(n)
// - The recursion depth is n, corresponding to the maximum depth of the call stack.

class Solution {
  public:
    // Function to calculate the sum of cubes of the first n natural numbers
    long long sumOfSeries(long long n) {
        // Base case: when n is 1, the sum is 1^3 = 1
        if (n == 1) {
            return 1;
        }
        
        // Recursive case: return n^3 + sum of series for (n-1)
        return n * n * n + sumOfSeries(n - 1);
    }
};
