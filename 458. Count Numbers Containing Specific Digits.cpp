/*
Count Numbers Containing Specific Digits
Difficulty: MediumAccuracy: 70.29%Submissions: 6K+Points: 4Average Time: 25m
You are given an integer n representing the number of digits in a number, and an array arr[] containing digits from 0 to 9. Your have to count how many n-digit positive integers can be formed such that at least one digit from the array arr[] appears in the number.

Examples:

Input: n = 1, arr[] = [1, 2, 3]
Output: 3
Explanation: Only the single-digit numbers [1, 2, 3] satisfy the condition.
Input: n = 2, arr[] = [3, 5]
Output: 34
Explanation: There are a total of 34  two digit numbers which contain atleast  one out of  [3, 5].
Constraints:
  1 ≤ n ≤ 9
  1 ≤ arr.size() ≤ 10
  0 ≤ arr[i] ≤ 9
*/

// ✅ Approach:
// 1. Mark which digits are allowed (or "good") using a boolean array.
// 2. Count how many digits are *not* allowed (`cnt`), and how many of those are also non-zero (`nonZero`).
// 3. Compute the total number of n-digit numbers (with first digit ≠ 0): 9 × 10^(n-1).
// 4. Subtract the count of invalid numbers (those made up only from not-allowed digits).
//    - For n = 1, invalids = nonZero (excluding 0).
//    - For n > 1, invalids = nonZero × (cnt)^(n-1), as the first digit cannot be 0.

// ✅ Intuition:
// We're generating all n-digit numbers, then subtracting those that are made up only of *invalid* digits.
// This avoids generating each number explicitly and improves performance.

// ✅ Time Complexity: O(10 + log p) = O(1), since only 10 digits and exponentiation runs in log p time.
// ✅ Space Complexity: O(1), as we use fixed-size arrays and variables.

class Solution {
  public:
    // Fast exponentiation function to calculate b^p
    int power(int b, int p){
        int res = 1;
        while(p > 0){
            if(p % 2 == 1){
                res *= b;
            }
            b *= b;
            p = p / 2;
        }
        return res;
    }

    int countValid(int n, vector<int>& arr) {
        // Mark digits that are good
        vector<bool> good(10, false);
        for(int &d : arr){
            good[d] = true;
        }

        int cnt = 0;       // count of not allowed digits (bad digits)
        int nonZero = 0;   // count of not allowed digits that are non-zero

        // Count digits that are not allowed
        for(int d = 0; d < 10; d++){
            if(!good[d]){
                cnt++;
                if(d != 0) nonZero++;  // don't count 0 in the leading digit
            }
        }

        // Total possible n-digit numbers (first digit from 1 to 9)
        int total = 9 * power(10, n - 1);

        // Count of invalid n-digit numbers made only from bad digits
        int notAllowed = (n == 1) ? nonZero : nonZero * power(cnt, n - 1);

        // Subtract invalid numbers from total to get valid count
        return total - notAllowed;
    }
};
