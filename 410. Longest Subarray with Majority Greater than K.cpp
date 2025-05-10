/*
Longest Subarray with Majority Greater than K
Difficulty: MediumAccuracy: 58.54%Submissions: 5K+Points: 4
Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.

Examples:

Input: arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.
Input: arr[] = [6, 5, 3, 4], k = 2
Output: 4
Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2, so it is the longest subarray.
Constraints:
1 <= arr.size() <= 106
1 <= arr[i] <= 106
0 <= k <= 106
*/

/*
Approach:
- This problem is a variation of finding the longest subarray with more elements > k than ≤ k.
- Convert the array into a +1/-1 transformation:
  - Replace each element: +1 if arr[i] > k, else -1.
- Maintain a prefix sum while traversing the array.
  - If prefixSum > 0 at any index `i`, then the subarray [0...i] has more elements > k.
  - If prefixSum was seen before, and prefixSum - 1 is present at index `j`, then [j+1...i] also has more elements > k.
- Use an unordered_map to store the **first occurrence** of each prefix sum to maximize the subarray length.

Intuition:
- Transform the array to a +1/-1 pattern relative to `k`.
- A prefix sum > 0 means a valid subarray.
- Storing the first occurrence of each prefix sum helps us find the longest valid subarray ending at `i`.

Time Complexity: O(n)  
- Single pass over the array with constant-time hash map operations.

Space Complexity: O(n)  
- In worst-case, we store each prefix sum once in the map.

*/

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        int prefixSum = 0, maxLen = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;  // Handle case when prefixSum becomes positive from the beginning

        for (int i = 0; i < n; i++) {
            // Convert element to +1 if greater than k, else -1
            prefixSum += (arr[i] > k) ? 1 : -1;

            // If current prefix sum is positive, the subarray from 0 to i is valid
            if (prefixSum > 0) {
                maxLen = i + 1;
            }

            // If prefixSum - 1 is seen before, update maxLen
            if (mp.count(prefixSum - 1)) {
                maxLen = max(maxLen, i - mp[prefixSum - 1]);
            }

            // Store the first occurrence of current prefixSum
            if (!mp.count(prefixSum)) {
                mp[prefixSum] = i;
            }
        }

        return maxLen;
    }
};