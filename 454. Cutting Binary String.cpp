/*
Cutting Binary String
Difficulty: MediumAccuracy: 49.71%Submissions: 31K+Points: 4
You are given a binary string s consisting only of characters '0' and '1'. Your task is to split this string into the minimum number of non-empty substrings such that:

Each substring represents a power of 5 in decimal (e.g., 1, 5, 25, 125, ...).
No substring should have leading zeros.
Return the minimum number of such pieces the string can be divided into.
Note: If it is not possible to split the string in this way, return -1.

Examples:

Input: s = "101101101"
Output: 3
Explanation: The string can be split into three substrings: "101", "101", and "101", each of which is a power of 5 with no leading zeros.
Input: s = "1111101"
Output: 1
Explanation: The string can be split into one binary string "1111101" which is 125 in decimal and a power of 5 with no leading zeros.
Input: s = "00000"
Output: -1
Explanation: There is no substring that can be split into power of 5.
Constraints:
1 ≤ s.size() ≤ 30
*/

/*
Approach:
- The task is to split the binary string `s` into the minimum number of substrings such that
  each substring represents a **power of 5** in decimal and does not start with a '0'.
- Use **recursive backtracking with memoization** (optional) or dynamic programming.
- Try all possible prefixes starting at index `i` and check if they are a valid power of 5.
- Recursively solve the suffix and choose the minimum cut count.

Intuition:
- The main idea is to parse every possible substring and check if it's a power of 5.
- Only binary strings starting with '1' and converting to a power of 5 are valid.
- Memoization or pruning prevents recomputation.

Time Complexity: O(n² * log(limit)), where limit is the maximum binary number formed (up to 10⁹)
Space Complexity: O(n + |powers_of_5|) = O(n), for recursion + set
*/

class Solution {
    int n;
public:
    int solve(int i, string &s, unordered_set<int> &st) {
        if (i == n)
            return 0; // No more cuts needed after end of string

        int num = 0;
        int ans = n + 1; // Set to max initially (acts like infinity)

        for (int j = i; j < n; j++) {
            num = num * 2 + (s[j] - '0'); // Convert binary to decimal step by step

            // If substring starts with '1' and is a power of 5
            if (s[i] != '0' && st.count(num)) {
                ans = min(ans, 1 + solve(j + 1, s, st)); // 1 cut + solve remaining part
            }
        }

        return ans;
    }

    int cuts(string s) {
        // If it starts with 0, no valid power-of-5 string can be formed
        if (s[0] == '0')
            return -1;

        n = s.length();

        // Precompute all powers of 5 up to 10^9 and store in set
        unordered_set<int> st;
        for (int i = 1; i <= 1e9; i *= 5) {
            st.insert(i);
        }

        int ans = solve(0, s, st);
        
        return ans == n + 1 ? -1 : ans;
    }
};