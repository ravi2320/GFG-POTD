/*
Minimum days to make M bouquets

Difficulty: MediumAccuracy: 46.85%Submissions: 25K+Points: 4Average Time: 30m
You have a row of flowers, where each flower blooms after a specific day. The array arr[] represents the blooming schedule: arr[i] is the day the flower at position i will bloom. To create a bouquet, you need to collect k adjacent bloomed flowers. Each flower can only be used in one bouquet.

Your goal is to find the minimum number of days required to make exactly m bouquets. If it is not possible to make m bouquets with the given arrangement, return -1.

Examples:
Input: m = 3, k = 2, arr[] = [3, 4, 2, 7, 13, 8, 5]
Output: 8
Explanation: We need 3 bouquets and each bouquet should have 2 flowers. After day 8: [x, x, x, x, _, x, x], we can make first bouquet from the first 2 flowers, second bouquet from the next 2 flowers and the third bouquet from the last 2 flowers.
Input: m = 2, k = 3, arr[] = [5, 5, 5, 5, 10, 5, 5]
Output: 10
Explanation: We need 2 bouquets and each bouquet should have 3 flowers, After day 5: [x, x, x, x, _, x, x], we can make one bouquet of the first three flowers that bloomed, but cannot make another bouquet. After day 10: [x, x, x, x, x, x, x], Now we can make two bouquets, taking 3 adjacent flowers in one bouquet.
Input: m = 3, k = 2, arr[] = [1, 10, 3, 10, 2]
Output: -1
Explanation: As 3 bouquets each having 2 flowers are needed, that means we need 6 flowers. But there are only 5 flowers so it is impossible to get the needed bouquets therefore -1 will be returned.
Constraints:
1 ≤ k ≤ arr.size() ≤ 105
1 ≤ m ≤ 105
1 ≤ arr[i] ≤ 109
*/

/*
Approach:
1. We are given `arr` (bloom days of flowers), and we need to form `m` bouquets, each of size `k`, with flowers blooming on or before a certain day.
2. Use **binary search on days**:
   - The answer must lie between `min(arr)` and `max(arr)`.
   - For a candidate day `mid`, check feasibility using `isPossible`.
3. `isPossible` function:
   - Traverse the array and count consecutive flowers that bloom on or before `mid`.
   - Once `k` consecutive flowers are found, we form one bouquet and reset the counter.
   - If we can form at least `m` bouquets, return true.
4. If feasible, shrink the search space (move left to find smaller possible day).
   Otherwise, increase the lower bound.

Intuition:
- The problem can be reduced to:  
  "What is the smallest day by which at least `m` bouquets of size `k` can be formed?"
- Binary search works because feasibility is **monotonic**:
  - If it's possible on day `d`, then it’s also possible on all days > `d`.
  - If it's not possible on day `d`, then it’s also not possible on all days < `d`.

Time Complexity:
- `isPossible`: O(n) per check.
- Binary Search Range: O(log(max(arr) - min(arr))).
- Total: **O(n log(max(arr) - min(arr)))**
- Space: O(1) (only variables used, no extra arrays).
*/

class Solution {
  public:
    // Helper function to check if bouquets can be formed by given bloomDay
    bool isPossible(vector<int> &arr, int k, int m, int bloomDay) {
        int cnt = 0;   // count consecutive flowers
        int res = 0;   // number of bouquets formed
        
        for (int &x : arr) {
            if (x <= bloomDay) {
                cnt++;  // flower bloomed, count it
            } else {
                cnt = 0;  // reset if not bloomed
            }
            
            // If enough flowers collected for a bouquet
            if (cnt == k) {
                res++;
                cnt = 0;  // reset after forming bouquet
            }
            
            // Early stopping if already enough bouquets formed
            if (res >= m) {
                return true;
            }
        }
        return res >= m;
    }

    int minDaysBloom(vector<int>& arr, int k, int m) {
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        int ans = -1;  // if not possible, return -1
        
        // Binary Search for minimum feasible day
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(arr, k, m, mid)) {
                ans = mid;
                high = mid - 1;  // try smaller day
            } else {
                low = mid + 1;   // need larger day
            }
        }
        return ans;
    }
};