/*
Longest Subarray with Sum K
Difficulty: MediumAccuracy: 24.64%Submissions: 544K+Points: 4
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Only subarray with sum = 15 is [-5, 8, -14, 2, 4] of length 5.
Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
-109 ≤ k ≤ 109
*/

/*
Approach:
1. Use a prefix sum technique to calculate the cumulative sum of elements while iterating through the array.
2. Maintain a hash map (`mp`) that stores the first occurrence of a prefix sum and its index.
3. For each element:
   - Calculate the cumulative sum (`sum`).
   - Check if there exists a prefix sum (`req = sum - k`) in the map. If it exists, the subarray between the stored index and the current index has a sum equal to `k`. Update the maximum length (`maxLen`) accordingly.
   - Store the current prefix sum in the map only if it hasn't been added before to ensure the longest subarray is considered.

Intuition:
- The prefix sum up to index `i` gives the sum of elements from the start to `i`. If removing a prefix sum (`sum - k`) results in `k`, it means there is a subarray with the desired sum ending at `i`.

Time Complexity:
- \(O(n)\): Single pass through the array, and hash map operations (insert and lookup) are \(O(1)\) on average.

Space Complexity:
- \(O(n)\): Hash map stores prefix sums, which can be up to the size of the array in the worst case.

Edge Cases:
1. The array contains all positive or all negative numbers.
2. `k` is greater than the sum of the array.
3. `k` is 0, meaning the subarray must sum to 0.

*/

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(); // Size of the array
        int sum = 0;        // Cumulative sum
        int maxLen = 0;     // Maximum length of subarray with sum equal to k
        unordered_map<int, int> mp; // Hash map to store the first occurrence of a prefix sum
        
        mp[0] = -1; // Handle cases where the subarray starts from index 0
        
        // Traverse the array
        for (int i = 0; i < n; i++) {
            sum += arr[i]; // Update cumulative sum
            
            // Check if there's a prefix sum that results in the target sum
            int req = sum - k;
            if (mp.find(req) != mp.end()) {
                maxLen = max(maxLen, i - mp[req]); // Update the maximum length
            }
            
            // Store the prefix sum in the map if it's not already present
            if (mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }
        
        return maxLen; // Return the maximum length of the subarray
    }
};