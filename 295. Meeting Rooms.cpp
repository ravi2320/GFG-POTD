/*
Meeting Rooms
Difficulty: MediumAccuracy: 65.12%Submissions: 13K+Points: 4
Given an array arr[][] such that arr[i][0] is the starting time of ith meeting and arr[i][1] is the ending time of ith meeting, the task is to check if it is possible for a person to attend all the meetings such that he can attend only one meeting at a particular time.

Note: A person can attend a meeting if its starting time is greater than or equal to the previous meeting's ending time.

Examples:

Input: arr[][] = [[1, 4], [10, 15], [7, 10]]
Output: true
Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings.
Input: arr[][] = [[2, 4], [9, 12], [6, 10]]
Output: false
Explanation: It is not possible to attend the second and third meetings simultaneously.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 2*106
*/

/*
Approach:
1. Sort the `arr` vector by the start times of each interval.
2. After sorting, check if any meeting's end time overlaps with the next meeting's start time.
3. If an overlap is found (i.e., `arr[i-1][1] > arr[i][0]`), return false.
4. If no overlaps are detected, return true.

Functions:
- `canAttend`: Determines if a person can attend all meetings by checking for overlapping intervals after sorting by start time.

Time Complexity:
- Sorting the intervals takes O(n log n).
- Checking for overlaps takes O(n).
Overall: O(n log n), where `n` is the number of intervals.

Space Complexity: O(1), as we are not using extra space.

*/

class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        // Sort intervals by start time
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        // Check for any overlapping intervals
        for (int i = 1; i < n; i++) {
            if (arr[i-1][1] > arr[i][0]) // Overlap detected
                return false;
        }
        
        return true; // No overlaps, so can attend all meetings
    }
};
