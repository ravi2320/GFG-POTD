/*
Divisible by 13
Difficulty: MediumAccuracy: 56.61%Submissions: 7K+Points: 4
Given a number represented as a string s (which may be very large), check whether it is divisible by 13 or not.

Examples:

Input : s = "2911285"
Output : true
Explanation: 2911285 / 13 = 223945, which is a whole number with no remainder.
Input : s = "27"
Output : false
Explanation: 27 / 13 ≈ 2.0769..., which is not a whole number (there is a remainder).
Constraints:
1 ≤  s.size()  ≤ 105
*/

/*
Approach:
- This uses a divisibility rule for 13 based on splitting the number into chunks of 3 digits
  from right to left, alternating subtraction and addition:
    e.g., For 1234567 → chunks = [567, 234, 1] → 567 - 234 + 1

- Push each chunk into a stack and alternate between subtraction and addition
  starting from the rightmost chunk.

Intuition:
- Using digit patterns and modular arithmetic to determine divisibility without full division.

Time Complexity: O(n), where n is the length of the string (since each digit is processed once).
Space Complexity: O(n/3) => O(n), for the stack to hold chunks of digits.
*/

class Solution {
  public:
    bool divby13(string &s) {
        int n = s.length();
        int i = n - 1;  // Start from the rightmost digit

        stack<long long> st;

        // Break the number into chunks of 3 digits from right to left
        while (i >= 0) {
            int cnt = 0;
            string part = "";

            // Take at most 3 digits to form a chunk
            while (i >= 0 && cnt < 3) {
                part = s[i] + part;  // Prepend digit to form correct order
                cnt++;
                i--;
            }

            // Push the numeric value of the chunk to the stack
            st.push(stoll(part));  // Use stoll to handle large 3-digit numbers
        }

        // Begin the alternating subtraction and addition process
        long long num = st.top();  // Start with the last chunk
        st.pop();

        bool flag = true;  // Toggle between subtract and add
        while (!st.empty()) {
            long long curr = st.top();
            st.pop();

            if (flag) {
                num -= curr;
            } else {
                num += curr;
            }

            flag = !flag;
        }

        // If the final result is divisible by 13, return true
        return abs(num) % 13 == 0;
    }
};
