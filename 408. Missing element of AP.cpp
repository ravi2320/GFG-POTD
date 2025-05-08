/*
Missing element of AP
Difficulty: MediumAccuracy: 34.32%Submissions: 54K+Points: 4
Given a sorted array arr[] that represents an Arithmetic Progression (AP) with exactly one missing element, find the missing number.

Note: An element will always exist that, upon inserting into a sequence forms Arithmetic progression. If the given sequence already forms a valid complete AP, return the (n+1)-th element that would come next in the sequence.

Examples:

Input: arr[] = [2, 4, 8, 10, 12, 14]
Output: 6
Explanation: Actual AP should be 2, 4, 6, 8, 10, 12, 14.
Input: arr[] = [1, 6, 11, 16, 21, 31]
Output: 26
Explanation: Actual AP should be 1, 6, 11, 16, 21, 26, 31.
Input: arr[] = [4, 7, 10, 13, 16]
Output: 19
Explanation: Since the sequence already forms a valid AP, the next element after 16 in the sequence would be 19. Therefore, the output is 19.
Constraints:
2 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 2*107
*/

/*
Approach:
- The array is an Arithmetic Progression (AP) with one missing element.
- First, determine the correct common difference `diff` using the given elements:
  - Normally `diff = (last - first) / n`, but we also check adjacent pairs to avoid miscalculation due to the missing value.
- Then, compute the sum `S` of a full AP with `n+1` elements using the formula:
  S = (2 * first + diff * n) * (n + 1) / 2
- Subtract the actual sum of the given array to find the missing value.

Intuition:
- The AP is missing exactly one number, so the difference between the expected sum and the actual sum gives the missing number.
- Ensuring the correct `diff` is important as one value may skew the estimate.

Time Complexity: O(n)  
- We scan the array once to compute the actual sum.

Space Complexity: O(1)  
- No extra space used beyond variables.

*/

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();

        // Determine the correct common difference in the AP
        int diff = arr[1] - arr[0] == arr[n - 1] - arr[n - 2]
                   ? arr[1] - arr[0]
                   : (arr[1] - arr[0] == (arr[n - 1] - arr[0]) / n
                      ? arr[1] - arr[0]
                      : arr[n - 1] - arr[n - 2]);

        // Calculate the expected sum of the full AP using the formula for sum of n+1 terms
        long long S = (2LL * arr[0] + diff * n) * (n + 1) / 2;

        // Subtract the actual sum of the array from the expected sum to find the missing number
        for (int &x : arr) {
            S -= x;
        }

        return S; // The remaining value is the missing element
    }
};
