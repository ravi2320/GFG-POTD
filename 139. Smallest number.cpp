/*
Smallest number
Difficulty: MediumAccuracy: 38.74%Submissions: 55K+Points: 4
Given two integers s and d. The task is to find the smallest number such that the sum of its digits is s and the number of digits in the number are d. Return a string that is the smallest possible number. If it is not possible then return -1.

Examples:

Input: s = 9, d = 2
Output: 18 
Explanation: 18 is the smallest number possible with the sum of digits = 9 and total digits = 2.
Input: s = 20, d = 3 
Output: 299 
Explanation: 299 is the smallest number possible with the sum of digits = 20 and total digits = 3.
Expected Time Complexity: O(d)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ s ≤ 100
1 ≤ d ≤ 6
*/

class Solution {
public:
    // Intuition:
    // - We need to construct the smallest number of length `d` with the sum of digits equal to `s`.
    // - If it's impossible to form such a number, return "-1".
    // - To form the smallest number, we should try to place the largest possible digits at the least significant positions.
    // - However, the first digit can't be zero, so we initially reduce `s` by 1 and add 1 back to the most significant digit in the end.

    // Time Complexity: O(d)
    // - We construct the number by iterating through the number of digits `d` once.
    // 
    // Space Complexity: O(d)
    // - We use a string to store the resulting number, which has a length of `d`.

    string smallestNumber(int s, int d) {
        // If it's impossible to form a number with sum `s` and length `d`
        if((d == 1 && s > 9) || (s > d * 9)) {
            return "-1";
        }

        // Decrease `s` by 1 to account for the first digit not being zero
        s -= 1;
        string ans = "";

        // Construct the number from the least significant digit to the most significant
        while(d > 0) {
            if(s >= 9) {
                // If remaining sum is greater than or equal to 9, place 9 at the current position
                ans = "9" + ans;
                s -= 9;
            } else if(s < 9 && d > 1) {
                // If remaining sum is less than 9 and more than one digit is left, place the remaining sum at the current position
                ans = to_string(s) + ans;
                s = 0;
            } else {
                // For the most significant digit, add back the 1 we initially subtracted
                ans = to_string(s + 1) + ans;
            }
            d--;
        }

        return ans;
    }
};
