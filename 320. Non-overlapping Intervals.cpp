/*
Non-overlapping Intervals
Difficulty: MediumAccuracy: 51.92%Submissions: 14K+Points: 4
Given a 2D array intervals[][] of representing intervals where intervals [i] = [starti, endi ]. Return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Examples:

Input: intervals[][] = [[1, 2], [2, 3], [3, 4], [1, 3]]
Output: 1
Explanation: [1, 3] can be removed and the rest of the intervals are non-overlapping.
Input: intervals[][] = [[1, 3], [1, 3], [1, 3]]
Output: 2
Explanation: You need to remove two [1, 3] to make the rest of the intervals non-overlapping.
Input: intervals[][] = [[1, 2], [5, 10], [18, 35], [40, 45]]
Output: 0
Explanation: All ranges are already non overlapping.
Constraints:
1 ≤ intervals.size() ≤  105
|intervalsi| == 2
0 ≤ starti < endi <=5*104
*/

/*
Approach:
1. **Sort Intervals by End Time**:
   - Sort the intervals based on the end time. If two intervals have the same end time, sort by start time.

2. **Iterate Through Intervals**:
   - Use a `last` pointer to keep track of the last non-overlapping interval.
   - If the current interval overlaps with the `last` interval, increment the count of intervals to be removed.
   - Otherwise, update the `last` pointer to the current interval.

3. **Count Overlapping Intervals**:
   - Overlap occurs when `intervals[i][0] < intervals[last][1]`.

Time Complexity:
- **O(n log n)**: Due to sorting the intervals.
- **O(n)**: For iterating through the intervals.

Space Complexity:
- **O(1)**: No extra space is used except for variables.

*/

class Solution {
public:
    // Comparator for sorting intervals based on their end time
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] < b[1]) return true;
        if (a[1] > b[1]) return false;
        return a[0] <= b[0];
    }

    int minRemoval(vector<vector<int>>& intervals) {
        int cnt = 0; // Count of intervals to remove
        int last = 0; // Pointer to the last non-overlapping interval
        int n = intervals.size();

        // Sort intervals by end time (and by start time if end times are equal)
        sort(intervals.begin(), intervals.end(), cmp);

        // Iterate through intervals
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < intervals[last][1]) {
                // Overlap detected, increment removal count
                cnt++;
            } else {
                // No overlap, update last pointer
                last = i;
            }
        }

        return cnt; // Return the number of intervals to remove
    }
};
