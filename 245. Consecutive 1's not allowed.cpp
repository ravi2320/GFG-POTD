/*
Consecutive 1's not allowed
Difficulty: MediumAccuracy: 27.46%Submissions: 112K+Points: 4
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 109 + 7.

Example 1:

Input:
N = 3
Output: 5
Explanation:
5 strings are (000,
001, 010, 100, 101).
Example 2:

Input:
N = 2
Output: 3
Explanation: 
3 strings are (00,01,10).
Your Task:
You don't have to print answer or take inputs. Complete the function countStrings() which takes single integer n, as input parameters and returns an integer denoting the answer. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
*/

/*
Approach:
1. The problem is to count the number of binary strings of length `n` that do not contain consecutive 1s.
2. We maintain two variables:
   - `zeroEnd`: Tracks the count of binary strings ending with 0.
   - `oneEnd`: Tracks the count of binary strings ending with 1.
   - The total count of valid strings at any point is `sum = zeroEnd + oneEnd`.
3. At each step:
   - The count of strings ending with 1 (`oneEnd`) can only be extended from strings that end with 0.
   - The count of strings ending with 0 (`zeroEnd`) is the total of the previous valid strings (`sum`).
4. We iteratively calculate `oneEnd`, `zeroEnd`, and update `sum` until we reach the desired length `n`.
5. The result is the total valid strings for length `n`.

Time Complexity:
- **O(n)**, as we iterate through the loop `n-1` times.

Space Complexity:
- **O(1)**, since we are using a constant amount of extra space regardless of the input size.

*/

class Solution{
public:
    // Function to count binary strings of length `n` without consecutive 1s
    long long countStrings(int n) {
        // Base cases for binary strings of length 1
        int zeroEnd = 1;  // Strings ending with '0'
        int oneEnd = 1;   // Strings ending with '1'
        int sum = oneEnd + zeroEnd;  // Total valid strings for length 1
        int MOD = 1e9+7;  // Modulo to prevent overflow
        
        // If n = 1, directly return the sum (1 for '0', 1 for '1')
        if(n == 1) return sum;
        
        // Iteratively compute for length 2 to n
        int i = 2;
        while(i <= n){
            oneEnd = zeroEnd % MOD;  // Strings ending with '1' are extended from strings ending with '0'
            zeroEnd = sum % MOD;     // Strings ending with '0' can be extended from any valid string
            sum = (oneEnd + zeroEnd) % MOD;  // Total valid strings for the current length
            i++;  // Move to the next length
        }
        
        return sum;  // Return the total count of valid strings for length n
    }
};
