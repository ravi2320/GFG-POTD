/*
Minimum sum
Difficulty: MediumAccuracy: 17.14%Submissions: 160K+Points: 4
Given an array arr[ ] consisting of digits, your task is to form two numbers using all the digits such that their sum is minimized. Return the minimum possible sum as a string with no leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: "604"
Explanation: The minimum sum is formed by numbers 358 and 246.
Input: arr[] = [5, 3, 0, 7, 4]
Output: "82"
Explanation: The minimum sum is formed by numbers 35 and 047.
Input: arr[] = [9, 4]
Output: "13"
Explanation: The minimum sum is formed by numbers 9 and 4.
Constraints:
2 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 9
*/

/*
Approach:
The problem asks to rearrange the given digits to form two numbers such that their sum is minimized.
This is a classic **Greedy Strategy** where we sort the digits and distribute them alternately between two numbers.

Steps:
1. Sort the array in ascending order.
2. Distribute digits alternately to two numbers: even index to `num1`, odd index to `num2`.
3. Add the two numbers represented as strings using manual digit-wise addition with carry.

Helper Function:
- `addNums(num1, num2)`: Performs addition of two large numbers represented as strings.

Intuition:
By putting smaller digits at higher positions (leftmost) in both numbers, we ensure a minimal sum.

Time Complexity:
- O(n log n): Sorting the array.
- O(n): Creating strings and adding them.

Space Complexity:
- O(n): For string storage and result.
*/

class Solution {
public:
    // Function to add two numeric strings
    string addNums(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";

        // Add digits from right to left with carry
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = 0;

            if (i >= 0) sum += (num1[i--] - '0');
            if (j >= 0) sum += (num2[j--] - '0');
            sum += carry;

            int rem = sum % 10;
            carry = sum / 10;

            res += to_string(rem); // Append current digit to result
        }

        // Remove trailing zeros (reverse case)
        while (!res.empty() && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(), res.end());  // Reverse to get correct result
        return res.empty() ? "0" : res;   // Ensure "0" is returned for sum = 0
    }

    // Main function to compute the minimal sum
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());  // Step 1: Sort digits

        string num1 = "", num2 = "";
        int n = arr.size();

        // Step 2: Distribute digits alternately to form two numbers
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                num1 += to_string(arr[i]);
            else
                num2 += to_string(arr[i]);
        }

        // Step 3: Add the two numbers and return result
        return addNums(num1, num2);
    }
};


/*
Approach:
The problem requires forming two numbers from an array of digits such that their **sum is minimized**.

Improvement:
Instead of sorting the array, we use a **frequency array of digits (0-9)**, and distribute digits alternately between two numbers `num1` and `num2`.

Steps:
1. Build a frequency array for digits 0 through 9.
2. Traverse from smallest digit to largest (0 to 9), and distribute digits alternately to `num1` and `num2` using a toggle `Turn`.
3. Finally, use string-based addition to compute the sum of these two numbers.

Helper Function:
- `addNums(num1, num2)`: Adds two large numbers represented as strings.

Intuition:
Assigning smaller digits earlier ensures they occupy more significant places, thus minimizing the total sum.

Time Complexity:
- O(n + 10) => O(n): Building frequency and distributing digits.
- O(max(len(num1), len(num2))) for string addition.

Space Complexity:
- O(n): For storing `num1`, `num2`, and result string.
*/

class Solution {
public:
    // Function to add two numeric strings
    string addNums(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";

        // Digit-wise addition from the end
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = 0;

            if (i >= 0) sum += (num1[i--] - '0');
            if (j >= 0) sum += (num2[j--] - '0');
            sum += carry;

            int rem = sum % 10;
            carry = sum / 10;

            res += to_string(rem);  // Append current digit
        }

        // Remove trailing zeros (they're leading in actual result after reverse)
        while (!res.empty() && res.back() == '0') {
            res.pop_back();
        }

        reverse(res.begin(), res.end());  // Reverse to get the actual result
        return res.empty() ? "0" : res;
    }

    // Main function to form minimal sum
    string minSum(vector<int> &arr) {
        vector<int> freq(10, 0);

        // Count frequency of each digit
        for (int &x : arr) {
            freq[x]++;
        }

        string num1 = "", num2 = "";
        bool Turn = true;  // Toggle to distribute digits alternately

        // Distribute digits based on frequency
        for (int i = 0; i < 10; i++) {
            while (freq[i]--) {
                if (Turn)
                    num1 += to_string(i);
                else
                    num2 += to_string(i);
                Turn = !Turn;
            }
        }

        // Return their sum as a string
        return addNums(num1, num2);
    }
};