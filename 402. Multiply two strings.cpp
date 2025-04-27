/*
Multiply two strings
Difficulty: MediumAccuracy: 20.06%Submissions: 226K+Points: 4Average Time: 20m
Given two numbers as strings s1 and s2. Calculate their Product.
Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.

Examples:

Input: s1 = "0033", s2 = "2"
Output: "66"
Explanation: 33 * 2 = 66
Input: s1 = "11", s2 = "23"
Output: "253"
Explanation: 11 * 23  = 253
Input: s1 = "123", s2 = "0"
Output: "0"
Explanation: Anything multiplied by 0 is equal to 0.
Constraints:
1 ≤ s1.size() ≤ 103
1 ≤ s2.size() ≤ 103
*/

/*
Intuition:
We are multiplying two numbers given as strings. 
We cannot directly convert them to integers because the numbers could be very large.
Thus, we simulate the elementary school multiplication method (digit by digit).

Approach:
1. Handle the negative sign first: keep track if the result should be negative.
2. Reverse both strings to simplify multiplication from least significant digits.
3. Use a result vector where res[i+j] represents the digit at position i+j.
4. Multiply each digit of the first number with each digit of the second number.
5. Handle carryover immediately after every multiplication.
6. Finally, build the resulting string by skipping leading zeros.
7. Attach a negative sign if necessary.

Time Complexity: O(N * M)
- Where N and M are the lengths of the two input strings.

Space Complexity: O(N + M)
- For the result vector storing intermediate multiplication results.
*/

class Solution {
public:
    string multiplyStrings(string& s1, string& s2) {
        bool negative = false;

        // Step 1: Handle negatives
        if (s1[0] == '-') {
            negative = !negative;
            s1 = s1.substr(1);
        }
        if (s2[0] == '-') {
            negative = !negative;
            s2 = s2.substr(1);
        }

        int l1 = s1.size();
        int l2 = s2.size();

        // Step 2: Reverse the strings
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        // Step 3: Result vector
        vector<int> res(l1 + l2, 0);

        // Step 4: Multiply each digit
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                res[i + j] += (s1[i] - '0') * (s2[j] - '0');
                res[i + j + 1] += res[i + j] / 10; // carry forward
                res[i + j] %= 10; // store single digit
            }
        }

        // Step 5: Build answer string
        string ans = "";
        bool leadingZero = true;
        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] != 0) {
                leadingZero = false;
            }
            if (!leadingZero) {
                ans.push_back(res[i] + '0');
            }
        }

        // Step 6: If empty (meaning zero result)
        if (ans.empty()) return "0";

        // Step 7: Attach negative if needed
        if (negative) ans = "-" + ans;

        return ans;
    }
};