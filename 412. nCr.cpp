/*
nCr
Difficulty: MediumAccuracy: 14.82%Submissions: 326K+Points: 4
Given two integer values n and r, the task is to find the value of Binomial Coefficient nCr

A binomial coefficient nCr can be defined as the coefficient of xr in the expansion of (1 + x)n that gives the number of ways to choose r objects from a set of n objects without considering the order.
The binomial coefficient nCr is calculated as : C(n,r) = n! / r! * (n-r) !
Note: If r is greater than n, return 0.
It is guaranteed that the value of nCr will fit within a 32-bit integer.

Examples:

Input: n = 5, r = 2
Output: 10
Explaination: The value of 5C2 is calculated as 5!/(5−2)!*2! = 5!/3!*2! = 10.
Input: n = 2, r = 4
Output: 0
Explaination: Since r is greater than n, thus 2C4 = 0
Input: n = 5, r = 0
Output: 1
Explaination: The value of 5C0 is calculated as 5!/(5−0)!*0! = 5!/5!*0! = 1.
Constraints:
1 ≤ n ≤ 100
1 ≤ r ≤ 100
*/

/*
Approach:
- We use a mathematical formula to calculate combinations (nCr):
  nCr = n! / (r! * (n - r)!)
  But to avoid overflow and optimize, we calculate it using:
  nCr = (n-r+1)/1 * (n-r+2)/2 * ... * n/r
- This reduces computation and helps avoid large factorials.

Intuition:
- We compute the product iteratively to minimize intermediate value size and avoid using large factorials.
- This approach also avoids using extra space for factorial arrays or recursion.

Time Complexity: O(r)
- Loop runs for r iterations.

Space Complexity: O(1)
- Only a few variables are used.

*/

class Solution {
public:
    int nCr(int n, int r) {
        // If r > n, the combination is not defined
        if (r > n) return 0;

        long long ans = 1;

        // Compute nCr iteratively using the formula
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
        }

        return ans;
    }
};