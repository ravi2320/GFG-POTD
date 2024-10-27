/*
Triplet Family
Difficulty: BasicAccuracy: 50.0%Submissions: 23K+Points: 1
Given an array arr of integers. Find whether three numbers are such that the sum of two elements equals the third element.

Example:

Input: arr[] = [1, 2, 3, 4, 5]
Output: true
Explanation: The pair (1, 2) sums to 3.
Input: arr[] = [5, 3, 4]
Output: false
Explanation: No triplets satisfy the condition.
Expected Time Complexity: O(n2)
Expected Auxilary Space: O(1)

Constraints:
1 <= arr.size() <= 103
0 <= arr[i] <= 105
*/

/*
Approach:
1. Sort the array in ascending order.
2. Traverse the array from the end to check each element as a potential triplet sum.
   - For each element `arr[i]` (starting from the largest element), use two-pointer technique:
     - Set two pointers, `j` at the beginning and `k` at `i-1` (end of the remaining elements).
     - Calculate the sum of `arr[j]` and `arr[k]`.
       - If `sum == arr[i]`, a triplet is found where `arr[i]` is the sum of two previous elements; return `true`.
       - If `sum < arr[i]`, increment `j` to increase the sum.
       - If `sum > arr[i]`, decrement `k` to decrease the sum.
3. Return `false` if no such triplet is found after checking all elements.

Time Complexity: O(n^2), where `n` is the number of elements in `arr`.
Space Complexity: O(1), as sorting is done in-place.

*/

class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());  // Sort the array to apply two-pointer technique

        // Check each element as a potential triplet sum
        for (int i = n - 1; i >= 2; i--) {
            int j = 0, k = i - 1;
            while (j < k) {
                int sum = arr[j] + arr[k];

                if (sum == arr[i])
                    return true;  // Triplet found
                else if (sum < arr[i])
                    j++;  // Increment to increase the sum
                else
                    k--;  // Decrement to decrease the sum
            }
        }

        return false;  // No triplet found
    }
};
