/*
Missing And Repeating
Difficulty: MediumAccuracy: 24.83%Submissions: 482K+Points: 4
Given an unsorted array arr of of positive integers. One number 'A' from set {1, 2,....,n} is missing and one number 'B' occurs twice in array. Find numbers A and B.

Examples

Input: arr[] = [2, 2]
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ n
*/

/*
 * Approach:
 * 1. The problem is to find two elements from the array: one missing element and one repeating element.
 * 2. We calculate two sums:
 *    - The sum of the elements in the array and compare it with the expected sum of the first `n` natural numbers.
 *    - The sum of squares of the elements and compare it with the expected sum of squares of the first `n` natural numbers.
 * 3. Using these sums, we derive two equations:
 *    - Let `mis` be the missing number and `rep` be the repeating number.
 *    - From the sum difference, we calculate `mis - rep`.
 *    - From the square sum difference, we calculate `mis + rep`.
 * 4. Solving these equations gives the values of `mis` (missing number) and `rep` (repeating number).
 *
 * Time Complexity: O(n), where `n` is the size of the array.
 * Space Complexity: O(1), only a few variables are used.
 */

class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        // Step 1: Initialize variables
        long long n = arr.size();  // Size of the array
        long long S = 0, Sn = 0;   // S = sum of array, Sn = sum of first n natural numbers
        long long S2 = 0, S2n = 0; // S2 = sum of squares of array elements, S2n = sum of squares of first n natural numbers

        // Step 2: Calculate expected sums
        Sn = (n * (n + 1)) / 2;  // Sum of first n natural numbers
        S2n = (n * (n + 1) * (2 * n + 1)) / 6;  // Sum of squares of first n natural numbers

        // Step 3: Calculate actual sums from the array
        for(int &x : arr){
            S += x;  // Sum of elements in the array
            S2 += ((long long)x * (long long)x);  // Sum of squares of elements in the array
        }

        // Step 4: Calculate differences
        long long val1 = S - Sn;       // Difference between the sum of elements (mis - rep)
        long long val2 = S2 - S2n;     // Difference between the sum of squares (mis^2 - rep^2)

        // Step 5: Solve equations
        val2 = val2 / val1;            // Calculate (mis + rep)
        long long rep = (val2 + val1) / 2;  // Calculate the repeating element
        long long mis = rep - val1;    // Calculate the missing element

        // Step 6: Return the result
        return {rep, mis};
    }
};
