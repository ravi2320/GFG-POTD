/*
Nearest multiple of 10
Difficulty: EasyAccuracy: 19.32%Submissions: 77K+Points: 2
A string str is given to represent a positive number. The task is to round str to the nearest multiple of 10.  If you have two multiples equally apart from str, choose the smallest element among them.

Examples:

Input: str = 29 
Output: 30
Explanation: Close multiples are 20 and 30, and 30 is the nearest to 29. 
Input: str = 15
Output: 10
Explanation: 10 and 20 are equally distant multiples from 20. The smallest of the two is 10.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= str.size()<= 105
*/

/*
Approach:
- The goal is to round the given number (as a string) to the nearest integer. If the last digit is greater than or equal to 5, we round up, otherwise, we round down.
- The steps are:
  1. Check the last digit of the string. If it's less than or equal to '5', round down by replacing the last digit with '0'.
  2. If the last digit is greater than '5', round up. This involves replacing the last digit with '0', and incrementing the previous digit.
  3. If incrementing the previous digit causes it to become '10' (i.e., the digit was '9'), propagate the carry to the left.
  4. If we propagate the carry to the most significant digit and it becomes '0', we add '1' to the beginning of the string to account for the overflow (e.g., rounding 999 to 1000).
  
Time Complexity:
- O(n), where `n` is the length of the string. We may need to iterate over all digits in the worst case (when propagating the carry).

Space Complexity:
- O(1), ignoring the space required for the input and output strings.

*/

class Solution {
public:
    // Function to round the number represented as a string to the nearest integer
    string roundToNearest(string str) {
        int n = str.length() - 1;  // Get the index of the last digit
        
        // Case 1: If the last digit is less than or equal to '5', round down
        if (str[n] <= '5') {
            str[n] = '0';  // Replace the last digit with '0'
            return str;     // Return the rounded string
        }
        
        // Case 2: If the last digit is greater than '5', round up
        str[n] = '0';  // Replace the last digit with '0'
        n--;           // Move to the previous digit
        
        // Propagate the carry for digits that are '9'
        while (n >= 0 && str[n] == '9') {
            str[n--] = '0';  // Replace '9' with '0' and move left
        }
        
        // If carry propagates to the most significant digit
        if (n == -1) {
            return "1" + str;  // Add '1' at the beginning (e.g., rounding 999 to 1000)
        }
        
        // Increment the digit that caused the carry
        str[n]++;
        return str;  // Return the rounded string
    }
};
