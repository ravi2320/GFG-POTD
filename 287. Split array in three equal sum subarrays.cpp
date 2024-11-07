/*
Split array in three equal sum subarrays
Difficulty: MediumAccuracy: 52.9%Submissions: 14K+Points: 4
Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each part is equal. If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j]) = sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.

Note: Since multiple answers are possible, return any of them. The driver code will print true if it is correct otherwise, it will print false.

Examples :

Input:  arr[] = [1, 3, 4, 0, 4]
Output: true
Explanation: [1, 2] is valid pair as sum of subarray arr[0..1] is equal to sum of subarray arr[2..3] and also to sum of subarray arr[4..4]. The sum is 4, so driver code prints true.
Input: arr[] = [2, 3, 4]
Output: false
Explanation: No three subarrays exist which have equal sum.
Input: arr[] = [0, 1, 1]
Output: false
Constraints:
3 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
*/

/*
Approach:
1. Calculate the total sum of the array. If it is not divisible by 3, return {0, 2} since it cannot be split into three equal-sum parts.
2. Set the `targetSum` as `totalSum / 3`.
3. Traverse the array while keeping a running `currentSum` to identify parts with the target sum.
4. Whenever `currentSum` reaches `targetSum`, reset `currentSum` and increment a `count`.
5. Store the index of the first and second partitions (`idx1` and `idx2`) when `count` is 1 and 2, respectively.
6. If we find two such indices, return `{idx1, idx2}`; otherwise, return `{0, 2}`.

Time Complexity: O(n), where n is the size of `arr`, as we only make a single pass to calculate sums and find indices.
Space Complexity: O(1), since we only use a few extra variables.

*/

class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        long totalSum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();
        
        // If total sum is not divisible by 3, we can't split it into 3 equal parts
        if (totalSum % 3 != 0) return {0, 2};
        
        long targetSum = totalSum / 3;
        long currentSum = 0;
        int idx1 = 0, idx2 = n-1, count = 0;
        
        // Traverse array and count parts that sum to targetSum
        for (int i = 0; i < n; ++i) {
            currentSum += arr[i];
            
            // If we reach the targetSum, reset the sum and increment count
            if (currentSum == targetSum) {
                currentSum = 0;
                count++;
                if (count == 1) idx1 = i;
                else if (count == 2) idx2 = i;
            }
        }
        
        // We need at least 3 parts with the target sum to split into three equal sums
        return {idx1, idx2};
    }
};
