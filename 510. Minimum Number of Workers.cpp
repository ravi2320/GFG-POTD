/*
Minimum Number of Workers

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 64.13%Submissions: 8K+Points: 4
You are given an array arr[], where arr[i] denotes the range of working hours a person at position i can cover.

If arr[i] ≠ -1, the person at index i can work and cover the time interval [i - arr[i], i + arr[i]].
If arr[i] = -1, the person is unavailable and cannot cover any time.
The task is to find the minimum number of people required to cover the entire working day from 0 to n - 1. If it is not possible to fully cover the day, return -1.

Examples:

Input: arr[] = [1, 2, 1, 0]
Output: 1
Explanation: The person at index 1 can cover the interval [-1, 3]. After adjusting to valid bounds, this becomes [0, 3], which fully covers the entire working day 0 to n -1. Therefore, only 1 person is required to cover the whole day.
Input: arr[] = [2, 3, 4, -1, 2, 0, 0, -1, 0]
Output: -1
Explanation: Persons up to index 2 cover interval [0…6], but working hour 7 cannot be cover as arr[7] = -1, Since the 7th hour cannot be covered by any person, it is impossible to cover the full working day.
Input: arr[] = [0, 1, 0, -1]
Output: -1
Explanation: The last hour cannot be covered by any person, so it is impossible to cover the full working day.
Constraints:
1 ≤ arr.size() ≤105
-1 ≤ arr[i] ≤ arr.size()
*/

/*
Approach:
---------
1. Each person at index `i` can cover the range:
      [max(0, i - arr[i]), i + arr[i]]
2. Create a helper array `temp` where:
      temp[l] = maximum right boundary reachable starting at index l
3. This converts the problem into an interval covering problem.
4. Use a greedy strategy similar to Jump Game / minimum jumps:
   - Traverse from left to right.
   - Track the farthest reachable position (`maxi`) so far.
   - Whenever the current coverage ends, extend it using `maxi`
     and increment the count.
5. If at any index coverage cannot be extended, return -1.

Intuition:
----------
We want the minimum number of men whose coverage collectively
covers the entire array.
By transforming each man's influence into an interval and always
choosing the interval that extends coverage the farthest,
we ensure a minimum count using greedy selection.

Time Complexity:
----------------
O(N)
- Single pass to build intervals
- Single greedy traversal

Space Complexity:
-----------------
O(N)
- Auxiliary array to store maximum reach from each index
*/

class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();

        // temp[i] stores the farthest right index reachable
        // starting coverage at index i
        vector<int> temp(n, -1);

        // Build interval coverage
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int low = max(0, i - arr[i]);
                int high = i + arr[i];
                temp[low] = max(temp[low], high);
            }
        }

        int ans = 0;      // Number of men used
        int curr = -1;    // Current coverage end
        int maxi = -1;    // Farthest reachable index so far

        // Greedy coverage
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, temp[i]);

            // Need to extend coverage
            if (curr < i) {
                if (maxi < i)
                    return -1; // Coverage impossible
                curr = maxi;
                ans++;
            }
        }

        return ans;
    }
};
