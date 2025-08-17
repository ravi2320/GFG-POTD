/*
Sort by Absolute Difference

Difficulty: MediumAccuracy: 27.77%Submissions: 49K+Points: 4Average Time: 5m
You are given a number x and array arr[]. Your task is to rearrange the elements of the array according to the absolute difference with x, i.e., an element having minimum difference comes first, and so on.
Note: If two or more elements are at equal distances arrange them in the same sequence as in the given array.

Examples:

Input: x = 7, arr[] = [10, 5, 3, 9, 2]
Output: [5, 9, 10, 3, 2]
Explanation: Sorting the numbers according to the absolute difference with 7, we have array elements as 5, 9, 10, 3, 2.
Input: x = 6, arr[] = [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
Explanation: Sorting the numbers according to the absolute difference with 6, we have array elements as 5, 4, 3, 2, 1.
Constraints:
1 ≤ x ≤ 105
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/

/*
Approach:
1. For each element in the array, compute its absolute difference from `x`.
2. Store pairs of {difference, originalIndex} in a temporary vector.
3. Sort this temporary vector by difference (and index if needed).
4. Rebuild the array using the sorted order of indices.

Intuition:
- The task is to rearrange the array elements so that those closest to `x` come first.
- By sorting based on the absolute difference, we naturally bring nearer elements first.

Time Complexity: O(n log n)  
    - O(n) to build the difference array.  
    - O(n log n) for sorting.  
    - O(n) to reconstruct the array.  
Space Complexity: O(n)  
    - For storing the difference array and the result.
*/

class Solution {
public:
    void rearrange(vector<int> &arr, int x) {
        int n = arr.size();
        vector<vector<int>> diffArr;

        // Create a difference array with absolute difference and original index
        for (int i = 0; i < n; i++) {
            diffArr.push_back({abs(x - arr[i]), i});
        }

        // Sort based on difference (and index implicitly)
        sort(diffArr.begin(), diffArr.end());

        // Rebuild the array in sorted order
        vector<int> ans;
        for (auto itr : diffArr) {
            ans.push_back(arr[itr[1]]);
        }

        arr = ans; // Update the original array
    }
};
