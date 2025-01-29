/*
Implement Pow
Difficulty: MediumAccuracy: 52.79%Submissions: 15K+Points: 4
Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).

Examples:

Input: b = 3.00000, e = 5
Output: 243.00000
Input: b = 0.55000, e = 3
Output: 0.16638
Input: b = -0.67000, e = -7
Output: -16.49971
Constraints:

-100.0 < b < 100.0
-109 <= e <= 109
Either b is not zero or e > 0.
-104 <= be <= 104
*/

/*
Approach:
1. Use **Divide and Conquer** to optimize exponentiation.
2. If `e` is 0, return 1 (base case).
3. If `e` is negative, compute `1 / power(b, -e)`.
4. Otherwise, recursively compute `power(b, e/2)`.
   - If `e` is even, return `tempAns * tempAns`.
   - If `e` is odd, return `b * tempAns * tempAns`.

Intuition:
- Instead of multiplying `b` `e` times, we **reduce the problem size by half** at each step, making it much faster.
- We leverage the fact that:
  - \(b^e = (b^{e/2})^2\) if `e` is even.
  - \(b^e = b \times (b^{e/2})^2\) if `e` is odd.

Time Complexity:
- \(O(\log e)\), since the exponent is divided by 2 at each step.

Space Complexity:
- \(O(\log e)\) for recursive stack space.

*/

class Solution {
  public:
    double power(double b, int e) {
        // Base case: Any number raised to power 0 is 1.
        if (e == 0) {
            return 1;
        }
        
        // Handle negative exponent by taking reciprocal.
        if (e < 0) {
            return 1 / power(b, -e);
        }
        
        // Compute power recursively for e/2.
        double tempAns = power(b, e / 2);
        
        // If exponent is even, return squared value.
        if (e % 2 == 0) {
            return tempAns * tempAns;
        }
        // If exponent is odd, multiply extra base `b`.
        else {
            return b * tempAns * tempAns;
        }
    }
};


class Solution {
  public:
    double power(double b, int e) {
        double result = 1.0;
        long long exp = e; // Use long long to handle `e = INT_MIN`

        if (exp < 0) {
            b = 1 / b;
            exp = -exp;
        }

        while (exp > 0) {
            if (exp % 2 == 1) { // If exponent is odd, multiply result with base
                result *= b;
            }
            b *= b;   // Square the base
            exp /= 2; // Reduce exponent by half
        }

        return result;
    }
};
