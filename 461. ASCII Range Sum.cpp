/*
ASCII Range Sum
Difficulty: MediumAccuracy: 66.36%Submissions: 4K+Points: 4
Given a string s consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.
Return all such non-zero sums (order does not matter).

Examples:

Input: s = "abacab"
Output: [293, 294]
Explanation: characters 'a' and 'b' appear more than once:
'a' : between positions 1 and 5 → characters are b, a, c and ascii sum is 98 + 97 + 99 = 294.
'b' : between positions 2 and 6 → characters are a, c, a and ascii sum is 97 + 99 + 97 = 293.
Input: s = "acdac"
Output: [197, 199]
Explanation: characters 'a' and 'c' appear more than once:
'a' : between positions 1 and 4 → characters are c, d and ascii sum is 99 + 100 = 199.
'c' : between positions 2 and 5 → characters are d, a and ascii sum is 100 + 97 = 197.
Constraints:
1 ≤ s.size() ≤ 105
*/

// ✅ Approach:
// 1. Traverse the string and compute a prefix sum of ASCII values for quick range calculations.
// 2. Simultaneously, use a hashmap to track the first and last occurrence of each character.
// 3. For each character that appears more than once (i.e., j - i > 1),
//    calculate the sum of ASCII values between its first and last position (exclusive) using prefix sum.
// 4. Add this value to the result vector.

// ✅ Intuition:
// We are interested in finding the sum of ASCII values between the **first and last occurrence** 
// of each character (excluding both) — but only if the character appears **at least twice with 
// at least one character in between**.
// To do this efficiently, we use a prefix sum to get constant-time range queries.

// ✅ Time Complexity: O(N), where N is the length of the string.
// ✅ Space Complexity: O(N), for the prefix sum array and hash map.

class Solution {
public:
    vector<int> asciirange(string& s) {
        int n = s.length();

        // Prefix sum of ASCII values of characters
        vector<int> prefixSum(n, 0);

        // Map to store first and last indices of each character
        unordered_map<char, pair<int, int>> mp;

        for (int i = 0; i < n; i++) {
            // Step 1: Build prefix sum array
            if (i == 0)
                prefixSum[i] = s[i];
            else
                prefixSum[i] = prefixSum[i - 1] + s[i];

            // Step 2: Track first and last occurrence of each character
            if (mp.find(s[i]) == mp.end())
                mp[s[i]] = {i, i};             // First time seen
            else
                mp[s[i]].second = i;           // Update last occurrence
        }

        vector<int> ans;

        // Step 3: For each character that appears more than once,
        // calculate ASCII sum between first and last index (excluding both)
        for (auto& itr : mp) {
            int i = itr.second.first;
            int j = itr.second.second;

            // Only valid if at least one character exists between i and j
            if (j - i > 1)
                ans.push_back(prefixSum[j - 1] - prefixSum[i]);
        }

        return ans;
    }
};
