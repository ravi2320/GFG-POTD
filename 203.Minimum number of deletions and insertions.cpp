/*
Minimum number of deletions and insertions
Difficulty: MediumAccuracy: 65.29%Submissions: 56K+Points: 4
Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Examples :

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion.
p and h deleted from heap. Then, p is inserted at the beginning.
One thing to note, though p was required yet it was removed/deleted first from its position and then it is inserted to some other position. Thus, p contributes one to the deletion_count and one to the insertion_count.
Input : str1 = "geeksforgeeks", str2 = "geeks"
Output: 8
Explanation: 8 deletions, i.e. remove all characters of the string "forgeeks".
Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ |str1|, |str2| ≤ 1000
All the characters are lowercase English alphabets
*/

/*
**Problem Statement:**
- Given two strings `str1` and `str2`, the task is to find the minimum number of operations required to convert `str1` into `str2`. The allowed operations are:
  1. Insert a character.
  2. Delete a character.
  3. Replace a character.

**Approach:**
1. **Dynamic Programming:** 
   - We use a 2D DP table `dp[i][j]` where `dp[i][j]` represents the length of the longest common subsequence (LCS) of the substrings `str1[0...i-1]` and `str2[0...j-1]`.
   - If the characters `str1[i-1]` and `str2[j-1]` match, then `dp[i][j] = dp[i-1][j-1] + 1`.
   - If they don't match, then we take the maximum value between `dp[i-1][j]` and `dp[i][j-1]`.

2. **Calculating Minimum Operations:**
   - The minimum number of operations needed to convert `str1` to `str2` is calculated as `(n + m) - 2 * LCS(str1, str2)`, where `n` and `m` are the lengths of `str1` and `str2` respectively.
   - This formula works because it accounts for the characters that are part of the LCS (no need to delete or insert these characters), and the remaining characters in `str1` need to be deleted, and the remaining characters in `str2` need to be inserted.

**Time Complexity:**
- The time complexity is `O(n * m)` where `n` is the length of `str1` and `m` is the length of `str2`.

**Space Complexity:**
- The space complexity is `O(n * m)` due to the DP table used to store intermediate results.

**Example Usage:**
- Given `str1 = "sea"` and `str2 = "eat"`, the function will return `2` as the minimum number of operations required.

*/

class Solution{
public:
	int minOperations(string str1, string str2) { 
	    int n = str1.size(), m = str2.size();
	    
	    // DP table to store the length of LCS
	    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	    
	    // Fill the DP table
	    for(int i=1; i<=n; i++){
	        for(int j=1; j<=m; j++){
	            // If characters match, take the diagonal value + 1
	            if(str1[i-1] == str2[j-1]){
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            // If not, take the maximum of the left or top value
	            else{
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	            }
	        }
	    }
	    
	    // Minimum operations = (n+m) - 2 * LCS length
	    return (n + m) - (2 * dp[n][m]);
	} 
};

// Example usage:
int main() {
    Solution sol;
    string str1 = "sea";
    string str2 = "eat";
    int result = sol.minOperations(str1, str2);
    cout << "Minimum operations required: " << result << endl;  // Output: 2
    return 0;
}
