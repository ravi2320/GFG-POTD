/*
Find XOR of numbers from L to R.
Difficulty: EasyAccuracy: 50.0%Submissions: 39K+Points: 2
You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:

Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
Your Task:

Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

Expected Time Complexity: O(1).

Expected Auxiliary Space: O(1).

Constraints:

1<=l<=r<=109
*/

/*
Approach:
1. The function `findXOR(l, r)` calculates the XOR of all integers between `l` and `r`, inclusive.
2. We use the property that XOR from 0 to `n` follows a pattern based on `n % 4`:
   - If `n % 4 == 0`, XOR(0 to n) is `n`.
   - If `n % 4 == 1`, XOR(0 to n) is `1`.
   - If `n % 4 == 2`, XOR(0 to n) is `n + 1`.
   - If `n % 4 == 3`, XOR(0 to n) is `0`.
3. To get the XOR from `l` to `r`, we calculate `f(r) ^ f(l-1)`, where `f(n)` returns the XOR from 0 to `n`.

Time Complexity: O(1), as the computation is done in constant time.
Space Complexity: O(1), as only a few variables are used.
*/

class Solution {
  public:
    // Function to find XOR from l to r
    int findXOR(int l, int r) {
        return f(l - 1) ^ f(r);
    }
    
    // Helper function to find XOR from 0 to n
    int f(int n) {
        if (n % 4 == 1) 
            return 1;
        else if (n % 4 == 2)
            return n + 1;
        else if (n % 4 == 3)
            return 0;
        else
            return n;
    }
};
