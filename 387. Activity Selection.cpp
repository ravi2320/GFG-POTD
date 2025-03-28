/*
Activity Selection
Difficulty: MediumAccuracy: 36.21%Submissions: 146K+Points: 4Average Time: 20m
You are given a set of activities, each with a start time and a finish time, represented by the arrays start[] and finish[], respectively. A single person can perform only one activity at a time, meaning no two activities can overlap. Your task is to determine the maximum number of activities that a person can complete in a day.

Examples:

Input: start[] = [1, 3, 0, 5, 8, 5], finish[] = [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: A person can perform at most four activities. The maximum set of activities that can be executed is {0, 1, 3, 4}
Input: start[] = [10, 12, 20], finish[] = [20, 25, 30]
Output: 1
Explanation: A person can perform at most one activity.
Input: start[] = [1, 3, 2, 5], finish[] = [2, 4, 3, 6]
Output: 3
Explanation: A person can perform activities 0, 1 and 3.
Constraints:
1 ≤ start.size() = finish.size() ≤ 2*105
1 ≤ start[i] ≤ finish[i] ≤ 109
*/

/*
    🔹 Approach:
    - Store activities as **(finish time, start time)** pairs.
    - **Sort** the activities based on their finish time.
    - Use **Greedy Selection**:
      - Always pick the activity that finishes earliest and does not overlap.
      - If the current activity starts after the last selected one ends, select it.

    🔹 Intuition:
    - Sorting by finish time ensures we **maximize** the number of activities by always choosing the **earliest finishing** valid activity.
    - This is a classic **greedy algorithm**.

    🔹 Time Complexity:
    - **O(N log N)** due to sorting.

    🔹 Space Complexity:
    - **O(1)** as we use only a few extra variables.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the maximum number of activities that can be performed
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<pair<int, int>> activities;
        
        // Store activities as (finish time, start time) pairs
        for (int i = 0; i < n; i++) {
            activities.push_back({finish[i], start[i]});
        }
        
        // Sort by finish time (greedy strategy)
        sort(activities.begin(), activities.end());

        int count = 1;  // At least one activity can always be selected
        int lastEndTime = activities[0].first;

        // Iterate through activities and select non-overlapping ones
        for (int i = 1; i < n; i++) {
            if (activities[i].second > lastEndTime) { // If it starts after the last selected activity
                count++;
                lastEndTime = activities[i].first; // Update end time
            }
        }
        
        return count;
    }
};

// Driver Code
int main() {
    vector<int> start = {1, 3, 2, 5};
    vector<int> finish = {2, 4, 3, 6};
    Solution obj;
    cout << "Maximum Activities Selected: " << obj.activitySelection(start, finish) << endl;
    return 0;
}