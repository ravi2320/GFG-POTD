/*
Count number of substrings
Difficulty: MediumAccuracy: 20.46%Submissions: 117K+Points: 4
Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

Example 1:

Input: S = "aba", K = 2
Output:3
Explanation:The substrings are: "ab", "ba" and "aba".
Input: S = "abaaca", K = 1
Output: 7
Explanation: The substrings are: "a", "b", "a", "aa", "a", "c", "a". 
Your Task:
You don't need to read input or print anything. Your task is to complete the function substrCount() which takes the string S and an integer K as inputs and returns the number of substrings having exactly K distinct characters.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ |S| ≤ 106
1 ≤ K ≤ 26
*/

/*
Approach:
1. We need to find the number of substrings with exactly `k` distinct characters.
2. This problem can be solved by first calculating the number of substrings with **at most** `k` distinct characters and subtracting from it the number of substrings with **at most** `k-1` distinct characters.
3. The difference will give the number of substrings with exactly `k` distinct characters.

To find the number of substrings with at most `k` distinct characters:
1. Use a sliding window approach.
2. Expand the window by moving the right pointer (`j`) and track the frequency of each character.
3. If the number of distinct characters exceeds `k`, shrink the window from the left (`i`) until the number of distinct characters is at most `k`.
4. At each step, the number of valid substrings is the size of the current window (`j - i + 1`), because any substring ending at `j` that starts from any index between `i` and `j` is valid.

Time Complexity:
- O(n): We iterate through the string with two pointers, adjusting the window boundaries.

Space Complexity:
- O(1): We use a fixed-sized array of size 26 (for lowercase English letters) to track character frequencies.

*/

class Solution {
  public:
    // Helper function to count substrings with at most K distinct characters
    long long int substrCountWithAtMostKdistinctChar(string s, int k) {
        vector<int> mp(26, 0);  // Frequency map to count occurrences of characters
        int distinctChar = 0;   // Counter for distinct characters
        int i = 0, j = 0, n = s.length();  // Sliding window pointers
        long long cnt = 0;  // To store the number of valid substrings

        // Slide the window across the string
        while (j < n) {
            mp[s[j] - 'a']++;  // Add the current character to the window

            // If it's a new distinct character, increment distinct character count
            if (mp[s[j] - 'a'] == 1) {
                distinctChar++;
            }

            // If there are more than `k` distinct characters, shrink the window
            while (distinctChar > k) {
                mp[s[i] - 'a']--;  // Remove the leftmost character

                // If the character count becomes zero, reduce the distinct count
                if (mp[s[i] - 'a'] == 0) {
                    distinctChar--;
                }

                i++;  // Move the left pointer to shrink the window
            }

            // Every substring ending at `j` and starting from any index between `i` and `j` is valid
            cnt += (j - i + 1);

            j++;  // Move the right pointer to expand the window
        }

        return cnt;
    }

    // Function to return the number of substrings with exactly K distinct characters
    long long int substrCount(string s, int k) {
        // Calculate the difference between substrings with at most K distinct chars and at most K-1 distinct chars
        return substrCountWithAtMostKdistinctChar(s, k) - substrCountWithAtMostKdistinctChar(s, k - 1);
    }
};
