/*
Overlapping Intervals
Difficulty: MediumAccuracy: 57.41%Submissions: 70K+Points: 4
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

Examples:

Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]
Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].
Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ starti ≤ endi ≤ 105
*/

/*
Approach:
1. **Sorting**:
   - Sort the intervals by their start times to ensure they are in order.

2. **Iterative Merging**:
   - Traverse the sorted intervals.
   - If the current interval overlaps with the last interval in the result list (`ans`), merge them by updating the end of the last interval.
   - If no overlap, add the current interval to the result list.

3. **Return Result**:
   - The resulting vector contains merged intervals.

Time Complexity:
- **O(n log n)** due to sorting of intervals, where `n` is the number of intervals.
- Merging the intervals in a single pass takes **O(n)**.

Space Complexity:
- **O(n)** for the result vector storing merged intervals.

*/

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Step 1: Sort the intervals based on the starting times
        sort(arr.begin(), arr.end());
        
        // Step 2: Vector to store the merged intervals
        vector<vector<int>> ans; 
        
        // Step 3: Merge overlapping intervals
        for (vector<int> &interval : arr) {
            // Check for overlap with the last interval in `ans`
            if (!ans.empty() && interval[0] <= ans.back()[1]) {
                // Merge intervals by updating the end time
                ans.back()[1] = max(ans.back()[1], interval[1]);
            } else {
                // No overlap, add the current interval
                ans.push_back(interval);
            }
        }
        
        // Step 4: Return the merged intervals
        return ans;
    }
};
