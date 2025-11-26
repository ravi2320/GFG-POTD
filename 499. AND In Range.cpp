/*
AND In Range
Difficulty: MediumAccuracy: 50.0%Submissions: 11K+Points: 4
You are given two integers l and r. Find the result after applying the series of Bitwise AND ( & ) operation on every natural number between the range l to r (including both).

Examples:

Input: l = 8, r = 13
Output: 8
Explanation: 
8 AND 9 AND 10 AND 11 AND 12 AND 13 = 8.
Input: l = 2, r = 3
Output: 2
Explanation: 2 AND 3 = 2.
Constraints:
1 ≤ l ≤ r ≤ 109
*/

/*
Intuition:
-----------
To compute bitwise AND of all numbers in the range [l, r], observe that:
If l and r differ at any bit position, then in that position (and all lower bits),
the AND will be 0 — because the range contains all combinations of 0 and 1 there.

So the only part of the result that remains is the **common prefix** (same higher bits)
between l and r.

Approach:
---------
1. Right-shift both numbers until they become equal.
   - This removes differing lower bits.
   - Count how many shifts we performed (cnt).
2. When l == r, that common value represents the prefix.
3. Left-shift it back by cnt to restore its position.

Example:
    l = 12 (1100), r = 15 (1111)
    After shifting:
      1100 → 110 → 11 → 1
      1111 → 111 → 11 → 1
    Both become 1 after 3 shifts.
    Answer = 1 << 3 = 8 (1000)

Time Complexity:
----------------
O(log(max(l, r)))  
Each step right-shifts both numbers.

Space Complexity:
-----------------
O(1)  
Only constant extra variables used.

*/

class Solution {
public:
    int andInRange(int l, int r) {

        int cnt = 0;  // Count number of right shifts performed

        // Continue until l and r share the same prefix
        while (l != r) {
            l >>= 1;  // Remove rightmost bit of l
            r >>= 1;  // Remove rightmost bit of r
            cnt++;    // Track how many bits were removed
        }

        // Left-shift back to place the shared prefix in correct position
        return (l << cnt);
    }
};
