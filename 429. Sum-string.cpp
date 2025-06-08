/*
Sum-string
Difficulty: HardAccuracy: 50.56%Submissions: 37K+Points: 8
Given a string s consisting of digits, determine whether it can be classified as a sum-string.

A sum-string is a string that can be split into more than two non-empty substrings such that:


The rightmost substring is equal to the sum of the two substrings immediately before it (interpreted as integers).

This condition must apply recursively to the substrings before it.

The rightmost substring (and any number in the sum) must not contain leading zeroes, unless the number is exactly '0'.

Examples:

Input: s = "12243660"
Output: true
Explanation: The string can be split as {"12", "24", "36", "60"} where each number is the sum of the two before it:
36 = 12 + 24, and 60 = 24 + 36. Hence, it is a sum-string.
Input: s = "1111112223"
Output: true
Explanation: Split the string as {"1", "111", "112", "223"}, where:
112 = 1 + 111 and 223 = 111 + 112. Hence, it follows the sum-string rule.
Input: s = "123456"
Output: false
Explanation: There is no valid split of the string such that each part satisfies the sum-string property recursively.
Constraints:
1 ≤ s.size() ≤ 100
String consists of characters from '0' to '9'.
*/

/*
Approach:
- A string is a "sum string" if it can be split into parts where each third part is the sum of the previous two.
- Try every possible pair of initial segments of length `len1` and `len2`.
- Compute their string-based sum using manual string addition to avoid integer overflow.
- Check recursively if the string can be broken into such segments repeatedly until the end.

Intuition:
- We attempt all possible first and second segment lengths.
- If their sum matches the following segment and this pattern continues till the end, it's a valid sum string.
- Manual string addition is needed because the input may represent very large numbers.

Time Complexity: O(N³)
- There are O(N²) ways to choose the first two segments.
- Each recursive check can take up to O(N) in worst-case due to string addition and comparisons.

Space Complexity: O(N)
- Used for temporary string manipulations and recursion stack.

*/

class Solution {
  public:
  
    // Helper function to perform string-based addition
    string str_sum(string &s1, string &s2){
        if(s1.length() > s2.length()){
            swap(s1, s2);  // Ensure s1 is shorter
        }

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        int n = s1.length(), m = s2.length();
        string ans = "";
        int carry = 0;

        // Add digits of both strings one-by-one
        for(int i=0; i<n; i++){
            int num = (s1[i] - '0') + (s2[i] - '0') + carry;
            int digit = num % 10;
            ans += (digit + '0');
            carry = num / 10;
        }

        // Add remaining digits of s2
        for(int i=n; i<m; i++){
            int num = (s2[i] - '0') + carry;
            int digit = num % 10;
            ans += (digit + '0');
            carry = num / 10;
        }

        // If there's a remaining carry
        if(carry){
            ans += (carry + '0');
        }

        reverse(ans.begin(), ans.end());  // Reverse to get final answer
        return ans;
    }

    // Recursive utility to validate sum string from given starting index and lengths
    bool checkIsSumStrUtil(string &s, int beg, int len1, int len2){
        string s1 = s.substr(beg, len1);
        string s2 = s.substr(beg + len1, len2);
        string s3 = str_sum(s1, s2);  // Calculate sum as string

        int s3_len = s3.length();

        // If the next segment goes out of bounds
        if(beg + len1 + len2 + s3_len > s.length()){
            return false;
        }

        // If s3 matches the next part in string
        if(s3 == s.substr(beg + len1 + len2, s3_len)){
            // If we have reached the end
            if(beg + len1 + len2 + s3_len == s.length()){
                return true;
            }

            // Recursively check next segments
            return checkIsSumStrUtil(s, beg + len1, len2, s3_len);
        }

        return false;
    }

    // Main function to check if the string is a sum string
    bool isSumString(string &s) {
        int n = s.length();

        // Try every possible split for first and second numbers
        for(int i=1; i<n; i++){
            for(int j=1; i+j < n; j++){
                if(checkIsSumStrUtil(s, 0, i, j)){
                    return true;
                }
            }
        }

        return false;
    }
};
