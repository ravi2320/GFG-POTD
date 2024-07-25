/*
LCM And GCD
Difficulty: BasicAccuracy: 37.02%Submissions: 130K+Points: 1
Given two integers a and b, write a function lcmAndGcd() to compute their LCM and GCD. The function takes two integers a and b as input and returns a list containing their LCM and GCD.

Example 1:

Input: a = 5 , b = 10
Output: 10 5
Explanation: LCM of 5 and 10 is 10, while thier GCD is 5.
Input: a = 14 , b = 8
Output: 56 2
Explanation: LCM of 14 and 8 is 56, while thier GCD is 2.
Expected Time Complexity: O(log(min(a, b))
Expected Auxiliary Space: O(1)

Constraints:
1 <= a, b <= 109
*/

/**
 * Intuition:
 * - **LCM (Least Common Multiple) and GCD (Greatest Common Divisor):** The GCD of two numbers can be computed using the Euclidean algorithm, and the LCM can be derived from the relationship: LCM(A, B) * GCD(A, B) = A * B.
 * - **GCD Calculation:** The GCD is calculated using a loop that repeatedly reduces the larger number by the remainder when the smaller number is divided into it.
 * - **LCM Calculation:** After finding the GCD, the LCM is calculated by dividing the product of the two numbers by their GCD.
 *
 * Time Complexity: O(log(min(A, B)))
 * - The Euclidean algorithm for GCD takes logarithmic time based on the smaller of the two numbers.
 *
 * Space Complexity: O(1)
 * - The algorithm uses a constant amount of space.
 */

class Solution {
  public:
    vector<long long> lcmAndGcd(long long A, long long B) {
        long long originalA = A;
        long long originalB = B;
        long long gcd = 1;

        // Calculate GCD using the Euclidean algorithm
        while (A > 0 && B > 0) {
            if (A < B) {
                B = B % A;
            } else {
                A = A % B;
            }
        }

        // Determine GCD from the final non-zero value
        gcd = (A == 0) ? B : A;

        // Calculate LCM using the relation: LCM * GCD = A * B
        long long lcm = (originalA * originalB) / gcd;

        // Return both LCM and GCD
        return {lcm, gcd};
    }
};
