/*
Minimum Platforms
Difficulty: MediumAccuracy: 26.84%Submissions: 524K+Points: 4
You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.

Examples:

Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
Output: 3
Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.
Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
Output: 1
Explanation: All train times are mutually exclusive. So we need only one platform
Input: arr[] = [1000, 935, 1100], dep[] = [1200, 1240, 1130]
Output: 3
Explanation: All 3 trains have to be there from 11:00 to 11:30
Constraints:
1≤ number of trains ≤ 50000
0000 ≤ arr[i] ≤ dep[i] ≤ 2359
Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0).
*/

/*
    🔹 Approach:
    - **Sort the trains by their arrival times** to process them in chronological order.
    - **Use a Min Heap (Priority Queue)** to keep track of the departure times of currently occupied platforms.
    - For each arriving train:
      - Remove all trains from the heap that have already departed.
      - Push the current train’s departure time into the heap.
      - Update the maximum platforms needed.

    🔹 Intuition:
    - The key idea is to keep track of active trains at any given time.
    - The priority queue stores departure times in ascending order, allowing us to efficiently remove trains that have already left.

    🔹 Time Complexity:
    - **O(N log N)** due to sorting and heap operations (each insertion/removal is O(log N)).
    
    🔹 Space Complexity:
    - **O(N)** due to the storage of train schedules and the priority queue.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of platforms required at the railway station
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int platform = 0;
        
        // Min heap to store departure times
        priority_queue<int, vector<int>, greater<int>> pq;

        // Store arrival and departure as pairs and sort by arrival time
        vector<vector<int>> trains;
        for (int i = 0; i < n; i++) {
            trains.push_back({arr[i], dep[i]});
        }
        sort(trains.begin(), trains.end());

        // Process each train
        for (int i = 0; i < n; i++) {
            // Remove all trains that have already departed before this train arrives
            while (!pq.empty() && pq.top() < trains[i][0]) {
                pq.pop();
            }

            // Push the current train's departure time
            pq.push(trains[i][1]);

            // Update the maximum platforms needed
            platform = max(platform, (int)pq.size());
        }

        return platform;
    }
};

// Driver Code
int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    Solution obj;
    cout << "Minimum Platforms Required: " << obj.findPlatform(arr, dep) << endl;
    return 0;
}

/*
    🔹 Approach:
    - Sort both **arrival** and **departure** times.
    - Use a **two-pointer technique**:
      - If a train arrives before or exactly when the current train departs, increase the platform count.
      - If a train departs before the next train arrives, decrease the platform count.
      - Keep track of the maximum platforms required at any moment.

    🔹 Intuition:
    - By sorting the times separately, we process events in chronological order.
    - Instead of maintaining a heap, we can just track the number of active trains using a counter.

    🔹 Time Complexity:
    - **O(N log N)** due to sorting.
    
    🔹 Space Complexity:
    - **O(1)** since we use only a few extra variables.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of platforms required at the railway station
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        
        // Sort arrival and departure times
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0; // Pointers for arrivals and departures
        int cnt = 0, res = 0;

        while (i < n) {
            // If a train arrives before or at the departure time of another train, increment count
            if (arr[i] <= dep[j]) {
                cnt++;
                i++;
            }
            // If a train departs, decrement count
            else {
                cnt--;
                j++;
            }

            // Track maximum platforms needed
            res = max(res, cnt);
        }
        
        return res;
    }
};

// Driver Code
int main() {
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    Solution obj;
    cout << "Minimum Platforms Required: " << obj.findPlatform(arr, dep) << endl;
    return 0;
}
