/*
Largest subarray with 0 sum
Difficulty: MediumAccuracy: 41.84%Submissions: 291K+Points: 4
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
-1000 <= A[i] <= 1000, for each valid i
*/

/*
Intuition:
- The problem requires finding the length of the longest subarray with a sum equal to 0.
- We use a hash map to store the cumulative sum and its corresponding index as we iterate through the array.
- If a cumulative sum repeats, it means the subarray between the previous occurrence and the current index has a sum of 0.
- By maintaining the maximum length of such subarrays, we can find the required result.

Approach:
1. Initialize a hash map to store cumulative sums and their indices.
2. Iterate through the array, calculating the cumulative sum at each step.
3. If the cumulative sum is found in the hash map, update the maximum length of subarray.
4. If the cumulative sum is not found, store it in the hash map with the current index.
5. Continue this process until the end of the array and return the maximum length found.

Time Complexity:
- O(n): We traverse the array once, and each hash map operation (insert and find) takes O(1) on average.

Space Complexity:
- O(n): In the worst case, we may store all the elements in the hash map.

*/

class Solution {
public:
    int maxLen(vector<int>& A, int n) {   
        int len = 0;  // To store the maximum length of subarray
        unordered_map<int, int> mp;  // Hash map to store cumulative sum and its index
        mp[0] = -1;  // Initialize the hash map with sum 0 at index -1
        int sum = 0;  // To store the cumulative sum
        
        for (int i = 0; i < n; i++) {
            sum += A[i];  // Update the cumulative sum
            
            // If cumulative sum is found in the hash map
            if (mp.find(sum) != mp.end()) {
                len = max(len, i - mp[sum]);  // Update the maximum length
            } else {
                mp[sum] = i;  // Store the cumulative sum with its index
            }
        }
        
        return len;  // Return the maximum length of subarray with sum 0
    }
};
