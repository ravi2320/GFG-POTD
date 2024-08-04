/*
N meetings in one room
Difficulty: EasyAccuracy: 45.3%Submissions: 260K+Points: 2
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :

Input: n = 6, start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)
Input: n = 3, start[] = [10, 12, 20], end[] = [20, 25, 30]
Output: 1
Explanation: Only one meetings can be held with given start and end timings.
Expected Time Complexity: O(n*logn)
Expected Auxilliary Space: O(n)

Constraints:
1 ≤ n ≤ 105
0 ≤ start[i] < end[i] ≤ 106
*/

#include <bits/stdc++.h>
using namespace std;

// Intuition: To find the maximum number of non-overlapping meetings, we sort the meetings by their end times. 
// This allows us to always choose the earliest finishing meeting first, maximizing the number of meetings.

// Time Complexity: O(n log n) for sorting the meetings, and O(n) for iterating through the sorted meetings. 
// Overall, the time complexity is O(n log n).

// Space Complexity: O(n) for storing the meeting data.

class Data {
public:
    int start, end, pos;
    Data(int start, int end, int pos) {
        this->start = start;
        this->end = end;
        this->pos = pos;
    }
};

class Solution {
public:
    // Function to find the maximum number of meetings that can be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Vector to store meeting data
        vector<Data> arr;

        // Storing the start, end, and position of each meeting
        for (int i = 0; i < n; i++) {
            arr.push_back(Data(start[i], end[i], i));
        }

        // Sorting meetings based on their end times
        sort(arr.begin(), arr.end(), [](Data &a, Data &b) {
            return a.end < b.end;
        });

        int cnt = 1; // At least one meeting can be held
        int freeTime = arr[0].end; // The time when the first meeting ends

        // Iterate over the sorted meetings
        for (int i = 1; i < n; i++) {
            // If the next meeting starts after the current meeting ends
            if (arr[i].start > freeTime) {
                cnt++; // Increment the count of meetings
                freeTime = arr[i].end; // Update the time when the current meeting ends
            }
        }

        return cnt; // Return the maximum number of non-overlapping meetings
    }
};

int main() {
    Solution sol;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};

    cout << sol.maxMeetings(n, start, end) << endl; // Output: 4

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define P pair<int, int>

// Intuition: To find the maximum number of non-overlapping meetings, we use a priority queue to store the meetings
// sorted by their end times. By always selecting the meeting that ends earliest, we maximize the number of meetings 
// we can attend without overlap.

// Time Complexity: O(n log n) for inserting all meetings into the priority queue, and O(n log n) for extracting them. 
// Overall, the time complexity is O(n log n).

// Space Complexity: O(n) for storing the meeting times in the priority queue.

class Solution {
public:
    // Function to find the maximum number of meetings that can be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Priority queue to store meetings sorted by their end times.
        priority_queue<P, vector<P>, greater<P>> pq;

        // Insert all meetings into the priority queue with end time as the first element
        for (int i = 0; i < n; i++) {
            pq.push({end[i], start[i]});
        }

        int cnt = 1; // At least one meeting can be held
        int freeTime = pq.top().first; // The time when the first meeting ends
        pq.pop();

        // Iterate over the remaining meetings
        while (!pq.empty()) {
            // If the next meeting starts after the current meeting ends
            if (pq.top().second > freeTime) {
                cnt++; // Increment the count of meetings
                freeTime = pq.top().first; // Update the time when the current meeting ends
            }
            pq.pop();
        }

        return cnt; // Return the maximum number of non-overlapping meetings
    }
};

int main() {
    Solution sol;
    int n = 6;
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};

    cout << sol.maxMeetings(n, start, end) << endl; // Output: 4

    return 0;
}
