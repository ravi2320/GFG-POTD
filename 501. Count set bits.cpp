/*
Count set bits
Difficulty: MediumAccuracy: 35.77%Submissions: 247K+Points: 4
You are given a number n. Find the total count of set bits for all numbers from 1 to n (both inclusive).

Examples :

Input: n = 4
Output: 5
Explanation: For numbers from 1 to 4. for 1: 0 0 1 => 1 set bit, for 2: 0 1 0 => 1 set bit, for 3: 0 1 1 => 2 set bits, for 4: 1 0 0 => 1 set bit. Therefore, the total set bits are 5.
Input: n = 17
Output: 35
Explanation: From numbers 1 to 17(both inclusive), the total number of set bits are 35.
Constraints:
1 ≤ n ≤ 108
*/

/*
Intuition:
-----------
We want to count total number of set bits (1s) in the binary representation
of all numbers from 1 to n.

A brute-force approach counts set bits for each number → O(n log n).
We can do much better using **pattern observation** based on powers of 2.

Key Insight:
------------
For any number n:

1. Let x = largest exponent such that (1 << x) <= n.
   Example: n = 13 → 2^3 = 8 is the largest power of 2 ≤ 13 → x = 3.

2. Total set bits from 1 to (2^x - 1):
      x * 2^(x-1)
   Reason: Among numbers 0 to 2^x - 1, each bit position appears equally.

3. Most significant bit (MSB) in numbers from 2^x to n:
      (n - 2^x + 1)
   These numbers all have their MSB = 1.

4. Remaining set bits from smaller range:
      countSetBits(n - 2^x)

Final Formula:
--------------
countSetBits(n) =
      x * 2^(x - 1)
    + (n - 2^x + 1)
    + countSetBits(n - 2^x)

This reduces the problem size logarithmically.

Time Complexity:
----------------
O(log n)  
Each recursive step reduces n by the highest power of 2.

Space Complexity:
-----------------
O(log n) recursion depth.

*/

class Solution {
public:

    // Helper: return largest exponent c where 2^c <= n
    int max2(int n) {
        int c = 0;
        // Keep shifting until (1 << c) exceeds n
        while ((1 << c) <= n) {
            c++;
        }
        return c - 1;  // highest exponent where 2^c <= n
    }

    // Count total set bits from 1 to n
    int countSetBits(int n) {

        // Base case: no set bits below 1
        if (n == 0)
            return 0;

        // Find highest power of 2 ≤ n → exponent x
        int x = max2(n);

        // 1) Count set bits in all numbers from 1 to (2^x - 1)
        int bitsTill2x = x * (1 << (x - 1));

        // 2) Count MSB bits in numbers from 2^x to n
        int msbBits = n - (1 << x) + 1;

        // 3) Recursively count remaining bits
        int rest = countSetBits(n - (1 << x));

        // Total
        return bitsTill2x + msbBits + rest;
    }
};
