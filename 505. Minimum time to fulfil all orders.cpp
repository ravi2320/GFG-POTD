/*
Minimum time to fulfil all orders

avatar
Discuss Approach
arrow-up
Difficulty: HardAccuracy: 63.04%Submissions: 14K+Points: 8
Geek is organizing a party at his house. For the party, he needs exactly n donuts for the guests. Geek decides to order the donuts from a nearby restaurant, which has m chefs and each chef has a rank r.
A chef with rank r can make 1 donut in the first r minutes, 1 more donut in the next 2r minutes, 1 more donut in the next 3r minutes, and so on.
For example, a chef with rank 2, can make one donut in 2 minutes, one more donut in the next 4 minutes, and one more in the next 6 minutes. So, it take 2 + 4 + 6 = 12 minutes to make 3 donuts. A chef can move on to making the next donut only after completing the previous one. All the chefs can work simultaneously.
Since, it's time for the party, Geek wants to know the minimum time required in completing n donuts. Return an integer denoting the minimum time.

Examples:

Input: n = 10, rank[] = [1, 2, 3, 4]
Output: 12
Explanation: 
Chef with rank 1, can make 4 donuts in time 1 + 2 + 3 + 4 = 10 mins
Chef with rank 2, can make 3 donuts in time 2 + 4 + 6 = 12 mins
Chef with rank 3, can make 2 donuts in time 3 + 6 = 9 mins
Chef with rank 4, can make 1 donuts in time = 4 minutes
Total donuts = 4 + 3 + 2 + 1 = 10 and total time = 12 minutes.
Input: n = 8, rank[] = [1, 1, 1, 1, 1, 1, 1, 1]
Output: 1
Explanation: As all chefs are ranked 1, so each chef can make 1 donuts in 1 min.
Total donuts = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 8 and total time = 1 minute.
Constraints:
1 ≤ n ≤ 103
1 ≤ m ≤ 104
1 ≤ rank[i] ≤ 100
*/

/*
Approach:
---------
We are given:
- ranks[i] → rank of the i-th chef
- n        → total number of donuts to be prepared

Each chef with rank r takes:
    r * 1 + r * 2 + ... + r * x = r * x * (x + 1) / 2 time
to prepare x donuts.

Goal:
-----
Find the minimum time required to prepare at least n donuts using all chefs.

Key Idea:
---------
Binary search on the answer (time).

For a given time `mid`, we check whether it is possible to make
at least `n` donuts within `mid` time.

Steps:
------
1. Set search space:
   - low  = 0
   - high = time taken by the fastest chef to make all donuts alone
2. For a candidate time `mid`:
   - For each chef, compute how many donuts they can make within `mid`
   - Sum up donuts from all chefs
   - If total ≥ n, `mid` is feasible
3. Minimize `mid` using binary search.

Intuition:
----------
As time increases, the number of donuts that can be prepared
monotonically increases. This makes the problem suitable
for binary search.

Time Complexity:
----------------
Let m = number of chefs

Binary Search:  O(log T)
Feasibility:    O(m)

Total:          O(m log T)

Space Complexity:
-----------------
O(1) — Constant extra space.

*/

class Solution {
  public:

    // Checks if at least n donuts can be made within 'mid' time
    bool isPossible(int mid, int n, vector<int>& ranks) {
        int donuts = 0;
        
        for (int &rank : ranks) {

            // Solve quadratic:
            // rank * x * (x + 1) / 2 <= mid
            // x^2 + x - (2 * mid / rank) <= 0
            int x = (-1 + sqrt(1 + (8.0 * mid) / rank)) / 2;
            
            donuts += x;
            
            // Early stopping if enough donuts are made
            if (donuts >= n)
                return true;
        }
        
        return false;
    }

    int minTime(vector<int>& ranks, int n) {
        
        // Fastest chef
        int mini = *min_element(ranks.begin(), ranks.end());

        // Binary search range
        int low = 0;
        int high = mini * (n * (n + 1)) / 2;
        int ans = high;

        // Binary search for minimum feasible time
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(mid, n, ranks)) {
                ans = mid;
                high = mid - 1;  // Try smaller time
            } else {
                low = mid + 1;   // Need more time
            }
        }

        return ans;
    }
};