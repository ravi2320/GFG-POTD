/*
Ways To Tile A Floor
Difficulty: MediumAccuracy: 32.31%Submissions: 57K+Points: 4
Given a floor of dimensions 2 x n and tiles of dimensions 2 x 1, the task is to find the number of ways the floor can be tiled. A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. 

Note: Two tiling arrangements are considered different if the placement of at least one tile differs.

Examples :

Input: n = 3
Output: 3
Explanation: We need 3 tiles to tile the board of size 2 x 3.
We can tile in following ways:
1) Place all 3 tiles vertically.
2) Place first tile vertically and remaining 2 tiles horizontally.
3) Place first 2 tiles horizontally and remaining tiles vertically.

Input: n = 4
Output: 5
Explanation: We need 4 tiles to tile the board of size 2 x 4.
We can tile in following ways:
1) All 4 vertical
2) All 4 horizontal
3) First 2 vertical, remaining 2 horizontal.
4) First 2 horizontal, remaining 2 vertical.
5) Corner 2 vertical, middle 2 horizontal.

Constraints:
1 ≤ n ≤ 45


*/

/*
Intuition:
The problem is essentially about counting the number of ways to tile a floor of length `n` using tiles of size 1x1 and 1x2. 
We can think of it recursively:
- If you start by placing a 1x1 tile at the end of the floor, you are left with tiling a floor of length `n-1`.
- If you start by placing a 1x2 tile at the end, you are left with tiling a floor of length `n-2`.
Thus, the number of ways to tile a floor of length `n` is the sum of the ways to tile floors of lengths `n-1` and `n-2`.

This recursive relation is similar to the Fibonacci sequence.

Approach:
1. If `n` is 1, there is only 1 way to tile the floor (with a 1x1 tile).
2. If `n` is 2, there are 2 ways to tile the floor: either two 1x1 tiles or one 1x2 tile.
3. For `n >= 3`, use dynamic programming to calculate the number of ways to tile the floor by iterating from `4` to `n` and applying the recursive relation: `ways(n) = ways(n-1) + ways(n-2)`.

Time Complexity:
- The solution runs in O(n) because we only loop from `4` to `n` to compute the result.

Space Complexity:
- O(1), since we are only using a constant amount of space (three variables to store previous results).

*/

class Solution {
  public:
    int numberOfWays(int n) {
        // Base cases:
        // If n is 1, there is only 1 way to tile (1x1 tile).
        // If n is 2, there are 2 ways to tile (two 1x1 tiles or one 1x2 tile).
        if (n <= 3)
            return n;  // This works because if n is 1 or 2, return 1 or 2 directly.
            
        int n1 = 2, n2 = 3;  // Initialize base cases: number of ways for lengths 2 and 3.
        int ans = 0;

        // Start from 4 and use the recursive relation to calculate number of ways for each length
        for (int i = 4; i <= n; i++) {
            ans = n1 + n2;  // The number of ways to tile a floor of length i is the sum of the number of ways for (i-1) and (i-2)
            n1 = n2;  // Update n1 to n2 (ways for length i-1)
            n2 = ans; // Update n2 to the new calculated answer (ways for length i)
        }
        
        return ans;  // Return the final answer for length n
    }
};
