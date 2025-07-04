/*
Subarrays With At Most K Distinct Integers
Difficulty: MediumAccuracy: 77.82%Submissions: 5K+Points: 4
You are given an array arr[] of positive integers and an integer k, find the number of subarrays in arr[] where the count of distinct integers is at most k.

Note: A subarray is a contiguous part of an array.

Examples:

Input: arr[] = [1, 2, 2, 3], k = 2
Output: 9
Explanation: Subarrays with at most 2 distinct elements are: [1], [2], [2], [3], [1, 2], [2, 2], [2, 3], [1, 2, 2] and [2, 2, 3].
Input: arr[] = [1, 1, 1], k = 1
Output: 6
Explanation: Subarrays with at most 1 distinct element are: [1], [1], [1], [1, 1], [1, 1] and [1, 1, 1].
Input: arr[] = [1, 2, 1, 1, 3, 3, 4, 2, 1], k = 2
Output: 24
Explanation: There are 24 subarrays with at most 2 distinct elements.
Constraints:
1 ≤ arr.size() ≤ 2*104
1 ≤ k ≤ 2*104
1 ≤ arr[i] ≤ 109


*/

/*
Approach:
We use the sliding window technique with two pointers (i and j) to maintain a window 
that contains **at most `k` distinct elements**. For each valid window, we count the number 
of subarrays ending at position `j` (i.e., `j - i + 1`). We use a frequency map to track 
distinct elements in the current window and shrink the window from the left when the number 
of distinct elements exceeds `k`.

Intuition:
To count subarrays with **at most k distinct elements**, we take each window where the number 
of distinct elements is ≤ k and count all subarrays ending at that point. For a more complex 
problem like "exactly k distinct elements," we can compute:
    countExactlyK = countAtMostK(k) - countAtMostK(k - 1)

Time Complexity: O(n) — Each element is added and removed from the map at most once.
Space Complexity: O(k) — Frequency map stores up to `k` distinct elements.
*/

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        int ans = 0;
        int i = 0, j = 0;
        unordered_map<int, int> freq;

        while (j < n) {
            // Include current element in frequency map
            freq[arr[j]]++;

            // Shrink window from the left if distinct elements exceed k
            while (i < j && freq.size() > k) {
                freq[arr[i]]--;
                if (freq[arr[i]] == 0)
                    freq.erase(arr[i]);
                i++;
            }

            // Count all valid subarrays ending at j
            ans += (j - i + 1);
            j++;
        }

        return ans;
    }
};
