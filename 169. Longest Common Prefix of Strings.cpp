/*
Longest Common Prefix of Strings
Difficulty: EasyAccuracy: 29.52%Submissions: 269K+Points: 2
Given an array of strings arr. Return the longest common prefix among all strings present in the array. If there's no prefix common in all the strings, return "-1".

Examples :

Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
Output: gee
Explanation: "gee" is the longest common prefix in all the given strings.
Input: arr[] = ["hello", "world"]
Output: -1
Explanation: There's no common prefix in the given strings.
Expected Time Complexity: O(n*min(|arri|))
Expected Space Complexity: O(min(|arri|))

Constraints:
1 ≤ |arr| ≤ 103
1 ≤ |arr[i]| ≤ 103
*/

/*
Intuition:
The problem involves finding the longest common prefix among a set of strings. The solution iteratively compares characters at each position across all strings. If any mismatch is found, the prefix up to that point is returned. If no mismatch is found for the shortest string's length, the entire prefix is returned.

Time Complexity:
The time complexity is O(n * minLen), where n is the number of strings and minLen is the length of the shortest string. This is because we may need to compare each character up to the length of the shortest string for all strings.

Space Complexity:
The space complexity is O(1) for additional space since we're only storing a few variables and the result string.

*/

class Solution {
public:
    // Function to find the longest common prefix among an array of strings
    string longestCommonPrefix(vector<string>& arr) {
        if (arr.empty()) return "-1"; // Return "-1" if there are no strings
        
        string ans = ""; // To store the longest common prefix
        int n = arr.size();
        int minLen = INT_MAX;

        // Find the minimum length among all strings
        for (string& str : arr) {
            minLen = min(minLen, (int)str.size());
        }

        // Traverse each character index up to the length of the shortest string
        for (int i = 0; i < minLen; i++) {
            char current = arr[0][i]; // Character from the first string at position i
            for (int j = 1; j < n; j++) {
                // Check if the current character matches across all strings
                if (arr[j][i] != current) {
                    // If a mismatch is found, return the prefix up to this point
                    return ans.empty() ? "-1" : ans;
                }
            }
            ans += current; // Add the current character to the prefix if no mismatch
        }

        return ans.empty() ? "-1" : ans; // Return the longest common prefix found
    }
};
