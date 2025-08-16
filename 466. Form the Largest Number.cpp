/*
Form the Largest Number
Difficulty: MediumAccuracy: 37.82%Submissions: 182K+Points: 4
Given an array of integers arr[] representing non-negative integers, arrange them so that after concatenating all of them in order, it results in the largest possible number. Since the result may be very large, return it as a string.

Examples:

Input: arr[] = [3, 30, 34, 5, 9]
Output: 9534330
Explanation: Given numbers are [3, 30, 34, 5, 9], the arrangement [9, 5, 34, 3, 30] gives the largest value.
Input: arr[] = [54, 546, 548, 60]
Output: 6054854654
Explanation: Given numbers are [54, 546, 548, 60], the arrangement [60, 548, 546, 54] gives the largest value.
Input: arr[] = [3, 4, 6, 5, 9]
Output: 96543
Explanation: Given numbers are [3, 4, 6, 5, 9], the arrangement [9, 6, 5, 4, 3] gives the largest value.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
*/

/*
Approach:
1. Convert all integers in the array into strings for easier concatenation-based comparison.
2. Sort the string array using a custom comparator:
   - For two strings a and b, compare (a+b) and (b+a). 
   - Place 'a' before 'b' if (a+b) is lexicographically larger than (b+a).
   - This ensures that the final concatenation produces the largest possible number.
3. Concatenate all sorted strings to form the final result.
4. Handle the edge case where the result might be "000..." (all zeros). In such case, return "0".

Intuition:
- The key observation is that to maximize the number, we need to decide the order of numbers
  based on their concatenation value rather than their individual value.
  Example: For "9" and "34":
    - "934" > "349" → So "9" should come before "34".
- Sorting using this rule guarantees the largest possible concatenated number.

Time Complexity:
- Let n = number of elements and k = max number of digits in the numbers.
- Sorting takes O(n log n * k) because comparisons involve concatenating strings of length up to k.
- Concatenation of results takes O(n * k).
- Overall complexity: O(n log n * k).

Space Complexity:
- O(n * k) for storing the string representation of all numbers.
*/

class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // Step 1: Convert all integers to strings
        vector<string> strArr;
        for (int &x : arr) {
            strArr.push_back(to_string(x));
        }
        
        // Step 2: Sort using custom comparator
        sort(strArr.begin(), strArr.end(), [](string &a, string &b) {
            return a + b > b + a;
        });
        
        // Step 3: Concatenate all strings
        string ans = "";
        for (string &x : strArr) {
            ans += x;
        }
        
        // Step 4: Handle case where result starts with '0' (all zeros)
        return ans[0] == '0' ? "0" : ans;
    }
};
