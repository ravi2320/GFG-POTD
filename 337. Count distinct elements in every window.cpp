/*
Count distinct elements in every window
Difficulty: EasyAccuracy: 41.83%Submissions: 143K+Points: 2
Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.

Examples:

Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
Output:  [3, 4, 4, 3]
Explanation: Window 1 of size k = 4 is 1 2 1 3. Number of distinct elements in this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number of distinct elements in this window are 3.
Input: arr[] = [4, 1, 1], k = 2
Output: [2, 1]
Explanation: Window 1 of size k = 2 is 4 1. Number of distinct elements in this window are 2. 
Window 2 of size k = 2 is 1 1. Number of distinct elements in this window is 1. 
Input: arr[] = [1, 1, 1, 1, 1], k = 3
Output: [1, 1, 1]
Constraints:
1 <= k <= arr.size() <= 105
1 <= arr[i] <= 105
*/	

/*
Approach:
1. Use a sliding window of size `k` to traverse the array.
2. Maintain a frequency map (`unordered_map`) to keep track of elements in the current window.
3. For each window:
   - Add the current element to the map and update its frequency.
   - If the window size exceeds `k`, remove the oldest element (at index `i`) from the map.
4. After processing each window, add the size of the frequency map (number of distinct elements) to the result.

Intuition:
To count the distinct elements in every window of size `k`, a sliding window approach is ideal. Using a frequency map allows us to efficiently update and track the count of distinct elements in the current window.

Time Complexity:
- Insertion, deletion, and lookup operations in the `unordered_map` are \(O(1)\) on average.
- Sliding through the array with a window of size `k` takes \(O(n)\), where \(n\) is the size of the array.
- Total time complexity: \(O(n)\).

Space Complexity:
- The space used by the `unordered_map` is \(O(k)\) for the sliding window.

Edge Cases:
1. If `k` is greater than the size of the array, handle it gracefully (e.g., return an empty result).
2. If the array is empty, return an empty result.

*/

class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int, int> mp; // Frequency map for elements in the current window
        int n = arr.size();         // Size of the input array
        vector<int> ans;            // Result vector to store distinct counts

        // Initialize the first window
        for (int j = 0; j < k; j++) {
            mp[arr[j]]++; // Add elements to the map
        }

        // Add the count of distinct elements in the first window
        ans.push_back(mp.size());

        // Slide the window across the array
        for (int j = k; j < n; j++) {
            mp[arr[j]]++; // Add the new element to the map

            // Remove the element that goes out of the window
            int i = j - k;
            mp[arr[i]]--;
            if (mp[arr[i]] == 0) {
                mp.erase(arr[i]); // Remove the element if its count becomes 0
            }

            // Add the count of distinct elements in the current window
            ans.push_back(mp.size());
        }

        return ans; // Return the result
    }
};
