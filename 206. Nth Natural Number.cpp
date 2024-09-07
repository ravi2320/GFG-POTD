/*
Nth Natural Number
Difficulty: MediumAccuracy: 29.99%Submissions: 70K+Points: 4
Given a positive integer n. You have to find nth natural number after removing all the numbers containing the digit 9.

Examples :

Input: n = 8
Output: 8
Explanation: After removing natural numbers which contains digit 9, first 8 numbers are 1,2,3,4,5,6,7,8 and 8th number is 8.
Input: n = 9
Output: 10
Explanation: After removing natural numbers which contains digit 9, first 9 numbers are 1,2,3,4,5,6,7,8,10 and 9th number is 10.
Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ n ≤ 109
*/

/*
**Problem Statement:**
- Given a number `n`, find the nth number in a sequence where all numbers are represented in base 9 instead of base 10. In other words, treat the sequence as if digits `9` do not exist.

**Approach:**
1. **Base Conversion to 9-based Representation:**
   - The goal is to convert a number from base 10 to base 9. This essentially means treating the number as if the digit `9` does not exist and incrementing numbers that cross the boundary where `9` would normally appear.
   - For example, converting `n = 9` to base 9 gives us `10` (in the sequence without digit `9`).

2. **Steps:**
   - Start with the number `n`.
   - While `n` is greater than 0, extract the last digit in base 9 by performing `n % 9`.
   - Add this digit to the result, multiplied by the current power of 10 (`factor`).
   - Divide `n` by 9 and repeat the process.
   - Continue until `n` becomes zero.

**Time Complexity:**
   - O(log₉(n)): Each iteration divides `n` by 9, so the number of iterations is proportional to the number of digits in the base 9 representation.

**Space Complexity:**
   - O(1): The space used is constant, as only a few variables are maintained.

**Example:**
   - Input: `n = 9`
   - Output: `10` (since 9 in base 10 corresponds to `10` in base 9).

**Edge Cases:**
   - For small values of `n` (such as `n = 1`), the result should be directly the same in both base 10 and base 9.

*/

class Solution {
  public:
    long long findNth(long long n) {
        // Variable to store the result in base 9
        long long ans = 0;
        
        // Factor helps in constructing the base 9 number, starting from the least significant digit
        long long factor = 1;

        // Convert n from base 10 to base 9 by extracting digits and multiplying by factor (powers of 10)
        while(n > 0){
            // Extract the current digit in base 9
            ans = factor * (n % 9) + ans;
            
            // Move to the next power of 10 for the result
            factor *= 10;
            
            // Reduce n by a factor of 9
            n /= 9;
        }
        
        return ans;  // Return the number in the "base 9" representation
    }
};
