/*
Count Subarray with k odds
Difficulty: MediumAccuracy: 51.12%Submissions: 17K+Points: 4Average Time: 20m
You are given an array arr[] of positive integers and an integer k. You have to count the number of subarrays that contain exactly k odd numbers.

Examples:

Input: arr[] = [2, 5, 6, 9], k = 2
Output: 2
Explanation: There are 2 subarrays with 2 odds: [2, 5, 6, 9] and [5, 6, 9].
Input: arr[] = [2, 2, 5, 6, 9, 2, 11], k = 2
Output: 8
Explanation: There are 8 subarrays with 2 odds: [2, 2, 5, 6, 9], [2, 5, 6, 9], [5, 6, 9], [2, 2, 5, 6, 9, 2], [2, 5, 6, 9, 2], [5, 6, 9, 2], [6, 9, 2, 11] and [9, 2, 11].
Constraint:
1 ≤ k ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 109
*/

/*
Approach:
---------
We are given an array `arr` and an integer `k`.
We need to count the number of subarrays that contain
**exactly k odd numbers**.

Key Idea:
---------
Number of subarrays with exactly k odd numbers =
    (subarrays with at most k odd numbers)
  - (subarrays with at most (k - 1) odd numbers)

To achieve this efficiently, we use the sliding window technique.

Steps:
------
1. Define a helper function that counts subarrays
   with at most K odd numbers.
2. Use two pointers:
   - Expand right pointer `j`
   - Maintain count of odd numbers in the window
3. Shrink left pointer `i` if odd count exceeds K
4. For each valid window ending at j, add (j - i + 1) to answer
5. Compute:
      exactK = atMostK(k) - atMostK(k - 1)

Intuition:
----------
Counting exactly k directly is tricky.
However, counting "at most k" is easy with sliding windows.
The difference removes all cases with fewer odds.

Time Complexity:
----------------
O(n)
- Each element is processed at most twice.

Space Complexity:
-----------------
O(1)
- Constant extra space.

*/

class Solution {
  public:

    // Counts subarrays with at most k odd numbers
    int countSubarrayAtleastKOdd(vector<int> &arr, int k) {
        int n = arr.size();
        int cnt = 0;  // Number of odd elements in current window
        int i = 0;
        int ans = 0;
        
        for (int j = 0; j < n; j++) {

            // Include current element
            cnt += arr[j] % 2;
            
            // Shrink window if odd count exceeds k
            while (cnt > k) {
                cnt -= arr[i] % 2;
                i++;
            }
            
            // All subarrays ending at j and starting from i to j are valid
            ans += (j - i + 1);
        }
        
        return ans;
    }

    int countSubarrays(vector<int>& arr, int k) {
        // Exactly k odd numbers
        return countSubarrayAtleastKOdd(arr, k)
             - countSubarrayAtleastKOdd(arr, k - 1);
    }
};
