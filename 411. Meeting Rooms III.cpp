/*
Meeting Rooms III
Difficulty: HardAccuracy: 64.3%Submissions: 9K+Points: 8
You are given an integer n representing the number of rooms numbered from 0 to n - 1. Additionally, you are given a 2D integer array meetings[][] where meetings[i] = [starti, endi] indicates that a meeting is scheduled during the half-closed time interval [starti, endi). All starti values are unique.

Meeting Allocation Rules:

When a meeting starts, assign it to the available room with the smallest number.
If no rooms are free, delay the meeting until the earliest room becomes available. The delayed meeting retains its original duration.
When a room becomes free, assign it to the delayed meeting with the earliest original start time.
Determine the room number that hosts the most meetings. If multiple rooms have the same highest number of meetings, return the smallest room number among them.

Examples:

Input: n = 2, meetings[][] = [[0, 6], [2, 3], [3, 7], [4, 8], [6, 8]]
Output: 1
Explanation: Time 0: Both rooms available. [0,6] starts in room 0.
Time 2: Room 0 busy until 6. Room 1 available. [2,3] starts in room 1.
Time 3: Room 1 frees up. [3,7] starts in room 1.
Time 4: Both rooms busy. [4,8] is delayed.
Time 6: Room 0 frees up. Delayed [4,8] starts in room 0 [6,10).
Time 6: [6,8] arrives but both rooms busy. It’s delayed.
Time 7: Room 1 frees up. Delayed [6,8] starts in room 1 [7,9).
Meeting counts: [2, 3]
Input: n = 4, meetings[][] = [[0, 8], [1, 4], [3, 4], [2, 3]
Output: 2
Explanation: Time 0: All rooms available. [0,8] starts in room 0.
Time 1: Room 0 busy until 8. Rooms 1, 2, 3 available. [1,4] starts in room 1.
Time 2: Rooms 0 and 1 busy. Rooms 2, 3 available. [2,3] starts in room 2.
Time 3: Room 2 frees up. [3,4] starts in room 2.
Meeting counts: [1, 1, 2, 0]
Constraints:

1 ≤ n ≤ 104
1 ≤ meetings.size() ≤ 104
meetings[i].size() == 2
0 ≤ starti < endi ≤ 104
*/

/*
Approach:
- We simulate room booking using two min-heaps:
  1. `usedRooms` stores {endTime, roomIndex} pairs (min-heap by endTime).
  2. `availableRooms` stores available room indices (min-heap to prefer smallest-index room).
- Meetings are sorted by start time.
- For each meeting:
  - Free up rooms whose meetings have already ended (i.e., endTime ≤ current start time).
  - If a room is available, assign it and record usage.
  - If not, delay the meeting to the earliest available room's endTime + duration.

Intuition:
- Simulate meeting allocation while always choosing the smallest indexed available room.
- Track room usage to determine which room was used the most.

Time Complexity: O(m log n)
- Sorting meetings: O(m log m)
- For each of m meetings, pushing/popping from heaps: O(log n)

Space Complexity: O(n)
- Room usage vector and two heaps of size up to n

*/

class Solution {
    typedef pair<int, int> P; // {endTime, roomIndex}
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<int> usedRoomsCnt(n, 0);  // Count usage for each room
        priority_queue<P, vector<P>, greater<P>> usedRooms; // Min-heap for in-use rooms
        priority_queue<int, vector<int>, greater<int>> availableRooms; // Min-heap for available rooms
        
        // Initially, all rooms are available
        for(int i = 0; i < n; i++) {
            availableRooms.push(i);
        }

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        for(int i = 0; i < m; i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            int duration = end - start;

            // Free up any rooms whose meetings have ended by current start time
            while(!usedRooms.empty() && usedRooms.top().first <= start) {
                availableRooms.push(usedRooms.top().second);
                usedRooms.pop();
            }

            if(!availableRooms.empty()) {
                // Assign to available room with smallest index
                int roomIdx = availableRooms.top();
                availableRooms.pop();
                
                usedRooms.push({end, roomIdx});
                usedRoomsCnt[roomIdx]++;
            } else {
                // No room free; wait for earliest one and delay the meeting
                auto [earliestEndTime, roomIdx] = usedRooms.top();
                usedRooms.pop();

                usedRooms.push({earliestEndTime + duration, roomIdx});
                usedRoomsCnt[roomIdx]++;
            }
        }

        // Find the room with the highest usage count
        int res = 0;
        for(int i = 1; i < n; i++) {
            if(usedRoomsCnt[i] > usedRoomsCnt[res])
                res = i;
        }

        return res;
    }
};
