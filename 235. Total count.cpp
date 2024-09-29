/*
Total count
Difficulty: EasyAccuracy: 48.74%Submissions: 35K+Points: 2
You are given an array arr[] of positive integers and a threshold value k. For each element in the array, divide it into the minimum number of small integers such that each divided integer is less than or equal to k. Compute the total number of these integer across all elements of the array.

Examples:

Input: k = 3, arr[] = [5, 8, 10, 13]
Output: 14
Explanation: Each number can be expressed as sum of different numbers less than or equal to k as 5 (3 + 2), 8 (3 + 3 + 2), 10 (3 + 3 + 3 + 1), 13 (3 + 3 + 3 + 3 + 1). So, the sum of count of each element is (2+3+4+5)=14.
Input: k = 4, arr[] = [10, 2, 3, 4, 7]
Output: 8
Explanation: Each number can be expressed as sum of different numbers less than or equal to k as 10 (4 + 4 + 2), 2 (2), 3 (3), 4 (4) and 7 (4 + 3).So, the sum of count of each element is (3 + 1 + 1 + 1 + 2) = 8.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
1 ≤ k ≤ 105
*/

/*
 * Approach:
 * - The goal is to calculate the total number of groups of size `k` that can be formed
 *   from the elements in the array.
 * - For each element `x` in the array, we determine how many complete groups of size `k`
 *   can be formed using integer division (`x / k`).
 * - If there is a remainder when dividing `x` by `k` (`x % k`), it means that an additional
 *   group can be formed with the leftover elements.
 * - We sum up the groups formed from each element to get the total count.
 * 
 * Time Complexity:
 * - O(n): We iterate through each element of the array once.
 * 
 * Space Complexity:
 * - O(1): We use a constant amount of space for the variables.
 */

class Solution {
public:
    int totalCount(int k, vector<int>& arr) {
        // Initialize the answer to 0
        int ans = 0;

        // Iterate through each element in the array
        for(int &x : arr) {
            // Add the number of complete groups formed by this element
            ans += x / k;
            // If there is a remainder, add an additional group
            if(x % k) ans++;
        }
        
        // Return the total count of groups
        return ans;
    }
};
