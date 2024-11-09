/*
Minimum sum
Difficulty: MediumAccuracy: 17.14%Submissions: 128K+Points: 4
Given an array arr[] such that each element is in the range [0 - 9], find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers. Return a string without leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: 604
Explanation: The minimum sum is formed by numbers 358 and 246.
Input: arr[] = [5, 3, 0, 7, 4]
Output: 82
Explanation: The minimum sum is formed by numbers 35 and 047.
Input: arr[] = [9, 4]
Output: 13
Explanation: The minimum sum is formed by numbers 9 and 4.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 9
*/

/*
Approach:
1. Count the occurrence of each digit in the input array `arr` using a frequency array `digits`.
2. Construct two strings `num1` and `num2` by alternating digits to ensure the numbers are balanced in length.
3. Alternate appending digits to `num1` and `num2` based on their frequency count to minimize their sum.
4. Use the helper function `addNumbers` to add `num1` and `num2` as if they were large numbers, as they may exceed typical integer limits.

Time Complexity: O(d + max(n, m)), where d is the number of digits (10 in our case), and `n` and `m` are the lengths of `num1` and `num2`.
Space Complexity: O(n + m), where `n` and `m` are the lengths of `num1` and `num2`.

*/

class Solution {
public:
    // Function to add two large numbers represented as strings
    string addNumbers(string num1, string num2) {
        int n = num1.length() - 1, m = num2.length() - 1;
        string result = "";
        int carry = 0;

        // Process both numbers from the end towards the start
        while (n >= 0 || m >= 0 || carry) {
            int n1 = (n >= 0) ? (num1[n--] - '0') : 0;
            int n2 = (m >= 0) ? (num2[m--] - '0') : 0;

            int sum = n1 + n2 + carry;
            result += (sum % 10) + '0';
            carry = sum / 10;
        }

        // Since we added digits from the least significant side, reverse the result
        reverse(result.begin(), result.end());
        return result;
    }

    // Function to split digits into two numbers and return their minimum sum
    string minSum(vector<int> &arr) {
        vector<int> digits(10, 0);
        
        // Count each digit's occurrence
        for (int &x : arr) {
            digits[x]++;
        }

        // Form two numbers by distributing digits to get the smallest sum
        string num1 = "", num2 = "";
        bool flag = true; // Use flag to alternate adding digits to num1 and num2

        for (int i = 1; i <= 9; i++) {
            while (digits[i] > 0) {
                if (flag) {
                    num1 += to_string(i);
                } else {
                    num2 += to_string(i);
                }
                flag = !flag;
                digits[i]--;
            }
        }

        // Return the sum of the two strings
        return addNumbers(num1, num2);
    }
};
