/*
Longest Span in two Binary Arrays
Difficulty: MediumAccuracy: 48.22%Submissions: 14K+Points: 4
Given two binary arrays, a1[] and a2[]. Find the length of longest common span (i, j) where j>= i such that a1[i] + a1[i+1] + .... + a1[j] =  a2[i] + a2[i+1] + ... + a2[j].

Examples:

Input: a1[] = [0, 1, 0, 0, 0, 0], a2[] = [1, 0, 1, 0, 0, 1]
Output: 4
Explanation: The longest span with same sum is from index 1 to 4 following zero based indexing.
Input: a1[] = [0, 1, 0, 1, 1, 1, 1], a2[] = [1, 1, 1, 1, 1, 0, 1]
Output: 6
Explanation: The longest span with same sum is from index 1 to 6 following zero based indexing.
Constraints:
1 <= a1.size() = a2.size() <= 106
0 <= a1[i], a2[i] <= 1
*/

/*
Approach:
- Transform the problem into finding the longest subarray with equal sum in both arrays.
- Maintain prefix sums of both arrays while iterating.
- Use a hash map to store the earliest index of each (sum1 - sum2) difference.
- If the same difference is found again, it means the subarray between these two indices has equal sum in both arrays.

Intuition:
- If two prefix sums have the same difference (sum1 - sum2), the subarray between them has equal sum.
- Use a hash map to remember the first index at which a particular difference occurred.
- This allows constant-time lookup and updates to track the longest subarray with equal sum.

Time Complexity: O(N)
- Only a single traversal through both arrays is required.

Space Complexity: O(N)
- Space used by the hash map to store differences and their first occurrence.
*/

class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        int sum1 = 0, sum2 = 0;           // To store prefix sums
        int res = 0;                      // To store the maximum length
        unordered_map<int, int> mp;       // Map to store (sum1 - sum2) to index
        mp[0] = -1;                       // Base case: difference 0 at index -1

        for(int i = 0; i < n; i++) {
            sum1 += a1[i];                // Update prefix sum of array 1
            sum2 += a2[i];                // Update prefix sum of array 2
            int diff = sum1 - sum2;       // Difference between prefix sums

            if(mp.count(diff)) {
                // If this difference was seen before, update max length
                res = max(res, i - mp[diff]);
            } else {
                // Store the first occurrence of this difference
                mp[diff] = i;
            }
        }

        return res;
    }
};
