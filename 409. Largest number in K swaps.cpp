/*
Largest number in K swaps
Difficulty: MediumAccuracy: 18.84%Submissions: 106K+Points: 4Average Time: 30m
Given a number k and string s of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of s at most k times.

Examples :

Input: s = "1234567", k = 4
Output: 7654321
Explanation: Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5.
Input: s = "3435335", k = 3
Output: 5543333
Explanation: Three swaps can make the input 3435335 to 5543333, swapping 3 with 5, 4 with 5 and finally 3 with 4.
Input: s = "1034", k = 2
Output: 4301
Explanation: Two swaps can make the input 1034 to 4301, swapping 1 with 4 and finally 0 with 3. 
Constraints:
1 ≤ s.size() ≤ 15
1 ≤ k ≤ 7
*/

/*
Approach:
- We want to find the lexicographically largest number possible after at most `k` swaps of digits in the string.
- The strategy used here is a **greedy approach**, where:
  - For each position `i` from left to right, we try to place the maximum possible digit at that position.
  - We look for the largest digit from index `i+1` to `n-1` that is not equal to `s[i]`, and swap if it increases the number.
  - We reduce the swap count `k` for each successful swap.

Intuition:
- The most significant digits contribute the most to the number’s value.
- So we prioritize placing larger digits at the leftmost positions.

Time Complexity: O(n²)  
- For each position `i`, we may scan the entire remainder of the string (O(n) * O(n)).

Space Complexity: O(1)  
- No extra space is used beyond variables.

Limitation:
- This approach doesn't guarantee the absolute maximum if swaps must be spread over multiple levels (a backtracking approach is required in such cases).
- However, it's efficient and gives a good result for smaller values of `k`.

*/

class Solution {
  public:
    // Function to find the largest number after k swaps.
    string findMaximumNum(string& s, int k) {
        int n = s.length();

        for (int i = 0; i < n && k > 0; i++) {
            int maxIdx = i;

            // Find the largest digit from i+1 to end
            for (int j = i + 1; j < n; j++) {
                if (s[j] >= s[maxIdx] && s[i] != s[j]) {
                    maxIdx = j;
                }
            }

            // If a better digit is found, perform the swap
            if (maxIdx != i) {
                swap(s[i], s[maxIdx]);
                k--; // Decrement the swap count
            }
        }

        return s; // Return the modified string
    }
};