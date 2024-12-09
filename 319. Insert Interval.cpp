/*
Insert Interval
Difficulty: MediumAccuracy: 50.61%Submissions: 14K+Points: 4
Geek has an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti. He wants to add a new interval newInterval= [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.

Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Examples:

Input: intervals = [[1,3], [4,5], [6,7], [8,10]], newInterval = [5,6]
Output: [[1,3], [4,7], [8,10]]
Explanation: The newInterval [5,6] overlaps with [4,5] and [6,7].
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,9]
Output: [[1,2], [3,10], [12,16]]
Explanation: The new interval [4,9] overlaps with [3,5],[6,7],[8,10].
Constraints:
1 ≤ intervals.size() ≤  105
0 ≤ start[i], end[i] ≤ 109
*/

/*
Approach:
1. **Traverse Intervals**:
   - Split the process into three phases:
     - Add all intervals that end before the new interval starts (no overlap).
     - Merge overlapping intervals with the new interval.
     - Add all intervals that start after the new interval ends.

2. **Key Steps**:
   - First phase: Push all intervals where `intervals[i][1] < newInterval[0]`.
   - Second phase: Merge intervals where `intervals[i][0] <= newInterval[1]`.
   - Third phase: Push all intervals where `intervals[i][0] > newInterval[1]`.

3. **Final Result**:
   - After processing the three phases, the result is stored in the `ans` vector.

Time Complexity:
- **O(n)**: Single pass through the intervals to handle insertion and merging.

Space Complexity:
- **O(n)**: Result vector to store the modified intervals.

*/

class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size();
        vector<vector<int>> ans;

        // Phase 1: Add all intervals ending before newInterval starts
        while (i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i++]);
        }

        // Phase 2: Merge overlapping intervals
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]); // Update start
            newInterval[1] = max(newInterval[1], intervals[i][1]); // Update end
            i++;
        }
        ans.push_back(newInterval); // Add the merged interval

        // Phase 3: Add remaining intervals
        while (i < n) {
            ans.push_back(intervals[i++]);
        }

        return ans;
    }
};
