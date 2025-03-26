/*
Word Break
Difficulty: MediumAccuracy: 40.86%Submissions: 135K+Points: 4
You are given a string s and a list dictionary[] of words. Your task is to determine whether the string s can be formed by concatenating one or more words from the dictionary[].

Note: From dictionary[], any word can be taken any number of times and in any order.

Examples :

Input: s = "ilike", dictionary[] = ["i", "like", "gfg"]
Output: true
Explanation: s can be breakdown as "i like".
Input: s = "ilikegfg", dictionary = ["i", "like", "man", "india", "gfg"]
Output: true
Explanation: s can be breakdown as "i like gfg".
Input: s = "ilikemangoes", dictionary = ["i", "like", "man", "india", "gfg"]
Output: false
Explanation: s cannot be formed using dictionary[] words.
Constraints:
1 ≤ s.size() ≤ 3000
1 ≤ dictionary.size() ≤ 1000
1 ≤ dictionary[i].size() ≤ 100
*/

/*
    🔹 Approach:
    - **Recursive + Memoization (Top-Down DP)** approach.
    - We use a recursive function `f(idx)` to check if `s[idx:n]` can be broken into valid words.
    - We maintain a **dp array** where `dp[idx]` stores whether `s[idx:n]` can be segmented.
    - The recursion explores all possible partitions and stops early when a valid segmentation is found.

    🔹 Intuition:
    - Try to form words from `s[idx]` onwards.
    - If a valid word is found in the dictionary, recursively check the rest of the string.
    - Memoization (`dp[idx]`) helps to **avoid recomputation** and speeds up the solution.

    🔹 Time Complexity:
    - **O(N²)** → `N` recursive calls, each checking substrings of length up to `N`.
    
    🔹 Space Complexity:
    - **O(N + D)** → `dp` array of size `O(N)`, dictionary `unordered_set` of size `O(D)`, and recursion stack `O(N)`.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to check if s[idx:n] can be segmented
    bool f(int idx, int n, string &s, unordered_set<string> &st, vector<int>& dp) {
        // Base Case: If we reach the end of the string, it means valid segmentation
        if (idx == n) {
            return true;
        }

        // If already computed, return the stored result
        if (dp[idx] != -1) {
            return dp[idx] == 1;
        }

        string temp = "";
        for (int j = idx; j < n; j++) {
            temp += s[j];  // Build the substring s[idx..j]
            
            // If substring exists in dictionary and the rest of the string is valid
            if (st.count(temp) && f(j + 1, n, s, st, dp)) {
                return dp[idx] = 1;  // Mark as valid segmentation
            }
        }

        return dp[idx] = 0;  // Mark as invalid segmentation
    }

    bool wordBreak(string &s, vector<string> &dict) {
        int n = s.length();
        unordered_set<string> st(dict.begin(), dict.end()); // Convert dictionary to set
        vector<int> dp(n + 1, -1); // Initialize DP array (-1 for uncomputed values)
        
        return f(0, n, s, st, dp); // Start recursion from index 0
    }
};

// Driver Code
int main() {
    string s = "applepenapple";
    vector<string> dict = {"apple", "pen"};
    Solution obj;
    cout << (obj.wordBreak(s, dict) ? "True" : "False") << endl; // Output: True
    return 0;
}


/*
    🔹 Approach:
    - We use a **Bottom-Up Dynamic Programming** approach.
    - Define a **dp array**, where `dp[i]` represents whether `s[i:n]` can be segmented using dictionary words.
    - Start from the **end** of the string (`dp[n] = 1` for an empty string).
    - Try to break the string into **substrings**, check if they exist in the dictionary, and update `dp[idx]` accordingly.
    
    🔹 Intuition:
    - If a valid word exists at position `idx`, we check if `dp[j+1]` (remaining part) is also true.
    - If yes, we mark `dp[idx] = 1` and break out of the loop to optimize.

    🔹 Time Complexity:
    - **O(N²)** → Outer loop runs `N` times, inner loop runs up to `N` times.
    
    🔹 Space Complexity:
    - **O(N + D)** → `dp` array takes `O(N)`, dictionary `unordered_set` takes `O(D)`.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool wordBreak(string &s, vector<string> &dict) {
        int n = s.length();

        // DP array to check if substring s[idx:n] can be segmented
        vector<int> dp(n + 1, 0);

        // Convert dictionary to unordered_set for O(1) lookups
        unordered_set<string> st(dict.begin(), dict.end());

        // Base Case: Empty string can always be segmented
        dp[n] = 1;

        // Iterate from right to left
        for (int idx = n - 1; idx >= 0; idx--) {
            // Try different substrings starting from index `idx`
            for (int j = idx; j < n; j++) {
                string temp = s.substr(idx, j - idx + 1); // Extract substring
                
                // Check if substring exists in dictionary & remaining part can be segmented
                if (st.count(temp) && dp[j + 1]) {
                    dp[idx] = 1;  // Mark this index as valid
                    break;        // No need to check further partitions
                }
            }
        }

        // Return whether the full string can be segmented
        return dp[0];
    }
};

// Driver Code
int main() {
    string s = "leetcode";
    vector<string> dict = {"leet", "code"};
    Solution obj;
    cout << (obj.wordBreak(s, dict) ? "True" : "False") << endl; // Output: True
    return 0;
}