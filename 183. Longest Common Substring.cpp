/*
Longest Common Substring
Difficulty: MediumAccuracy: 42.69%Submissions: 232K+Points: 4
You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: str1 = "ABCDGH", str2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.
Input: str1 = "ABC", str2 = "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1.
Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<= str1.size(), str2.size()<=1000
Both strings may contain upper and lower case alphabets.
*/

/*
Intuition:
- The problem is to find the length of the longest common substring between two given strings.
- A dynamic programming (DP) approach can be used to solve this efficiently by maintaining a 2D DP table where dp[i][j] represents the length of the longest common suffix of the substrings ending at str1[i-1] and str2[j-1].
- If the characters match, we extend the common substring by 1, otherwise, we reset the length to 0.

Time Complexity:
- The time complexity is O(n * m), where n and m are the lengths of the two strings. This is due to filling the DP table of size (n+1) x (m+1).

Space Complexity:
- The space complexity is O(n * m) as we are using a 2D DP table to store intermediate results.

Approach:
- Initialize a DP table of size (n+1) x (m+1) with all values set to 0.
- Iterate through both strings and fill the DP table based on the matching condition.
- Track the maximum length of any common substring found.

*/

class Solution {
public:
    // Function to find the length of the longest common substring between two strings
    int longestCommonSubstr(string str1, string str2) {
        int n  = str1.size(), m = str2.size();
        
        // DP table where dp[i][j] will store the length of the longest common suffix
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Variable to store the maximum length of common substring found
        int ans = 0;
        
        // Fill the DP table
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                
                // If characters match, extend the common substring length
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    
                    // Update the maximum length found so far
                    ans = max(ans, dp[i][j]);            
                }
                // If characters don't match, dp[i][j] remains 0, implicitly handled by initialization
            }
        }
        
        // Return the length of the longest common substring found
        return ans;
    }
};
