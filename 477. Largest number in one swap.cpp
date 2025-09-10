/*
Largest number in one swap
Difficulty: EasyAccuracy: 48.67%Submissions: 13K+Points: 2
Given a string s, return the lexicographically largest string that can be obtained by swapping at most one pair of characters in s.

Examples:

Input: s = "768"
Output: "867"
Explanation: Swapping the 1st and 3rd characters(7 and 8 respectively), gives the lexicographically largest string.
Input: s = "333"
Output: "333"
Explanation: Performing any swaps gives the same result i.e "333".
Constraints:
1 ≤ |s| ≤ 105
'0' ≤ s[i] ≤ '9'
*/

/*
Approach:
1. Precompute the last occurrence of every digit (0–9) in the string.
   - Store it in an array `last[digit]` so we can quickly check where a digit appears last.
2. Iterate through the string from left to right:
   - For the current digit s[i], check if there exists a larger digit (9 → current+1) 
     that occurs later in the string.
   - If found, swap s[i] with the last occurrence of that larger digit.
   - Return the string immediately after the first swap (since only one swap is allowed).
3. If no swap improves the number, return the original string.

Intuition:
- To maximize the number, the best strategy is:
  - From left to right, try to place the largest possible digit at each position.
  - Use the *last occurrence* of a larger digit so that we don’t waste a potential bigger number later.
- This greedy approach guarantees the lexicographically largest number after one swap.

Time Complexity: O(n * 10) ≈ O(n)  
- For each character (n), at most 10 digits are checked.

Space Complexity: O(10) = O(1)  
- Array `last` to store last occurrence of each digit.
*/

class Solution {
  public:
    string largestSwap(string &s) {
        int n = s.length();

        // Step 1: Store last occurrence of each digit
        vector<int> last(10, -1);
        for(int i = 0; i < n; i++) {
            last[s[i] - '0'] = i;
        }
        
        // Step 2: Iterate through digits to find the first beneficial swap
        for(int i = 0; i < n; i++) {
            // Check if a larger digit exists later in the string
            for(int d = 9; d > s[i] - '0'; d--) {
                if(last[d] > i) { 
                    // Swap current digit with the last occurrence of that larger digit
                    swap(s[i], s[last[d]]);
                    return s;  // return immediately after the swap
                }
            }
        }
        
        // Step 3: If no swap improves the number, return original
        return s;
    }
};
