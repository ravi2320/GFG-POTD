/*
Max Score from Subarray Mins
Difficulty: MediumAccuracy: 43.26%Submissions: 123K+Points: 4
You are given an array arr[] of integers. Your task is to find the maximum sum of the smallest and second smallest elements across all subarrays (of size >= 2) of the given array.

Examples :

Input: arr[] = [4, 3, 5, 1]
Output: 8
Explanation: All subarrays with at least 2 elements and find the two smallest numbers in each:
[4, 3] → 3 + 4 = 7
[4, 3, 5] → 3 + 4 = 7
[4, 3, 5, 1] → 1 + 3 = 4
[3, 5] → 3 + 5 = 8
[3, 5, 1] → 1 + 3 = 4
[5, 1] → 1 + 5 = 6
Maximum Score is 8.
Input: arr[] = [1, 2, 3]
Output: 5
Explanation: All subarray with at least 2 elements and find the two smallest numbers in each:
[1, 2] → 1 + 2 = 3
[1, 2, 3] → 1 + 2 = 3
[2, 3] → 2 + 3 = 5
Maximum Score is 5
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
*/

/*
Approach:
- We iterate through all pairs of elements in the array to find valid pairs (a, b) where a < b.
- For each subarray starting from index i, we keep track of the smallest and second smallest elements.
- We compute the sum of these two elements and track the maximum such sum.

Intuition:
- The goal is to find two elements in the array such that one is smaller than the other,
  and their sum is maximized. 
- For every starting element, we try to find a second distinct element greater than the first 
  but less than the current second minimum to optimize the sum.

Time Complexity: O(n^2) — for each element, we scan the rest of the array.
Space Complexity: O(1) — constant space used.
*/

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;

        // Iterate over all possible starting indices
        for(int i = 0; i < n - 1; i++) {
            int mini = arr[i];              // minimum element so far
            int secMini = INT_MAX;          // second minimum initialized to max

            // Scan elements ahead of i
            for(int j = i + 1; j < n; j++) {
                // Update min and second min
                if(arr[j] < mini) {
                    secMini = mini;
                    mini = arr[j];
                }
                else if(arr[j] > mini && arr[j] < secMini) {
                    secMini = arr[j];
                }

                // Update answer if both min and second min are valid
                if(secMini != INT_MAX)
                    ans = max(ans, mini + secMini);
            }
        }

        return ans;
    }
};

/*
Approach:
- Traverse the array from index 1 to n-1.
- For each adjacent pair (arr[i-1], arr[i]), compute their sum.
- Track the maximum such sum.

Intuition:
- Since the task is to find the maximum sum of any two adjacent elements,
  we only need to consider pairs (arr[i-1], arr[i]).
- This avoids unnecessary comparisons and reduces the time complexity significantly.

Time Complexity: O(n) — Only one pass through the array.
Space Complexity: O(1) — No extra space is used.
*/

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int n = arr.size();
        int ans = 0;

        // Iterate through all adjacent pairs and track maximum sum
        for(int i = 1; i < n; i++) {
            ans = max(ans, arr[i] + arr[i - 1]);
        }

        return ans;
    }
};