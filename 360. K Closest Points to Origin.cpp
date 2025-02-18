/*
K Closest Points to Origin
Difficulty: MediumAccuracy: 62.4%Submissions: 13K+Points: 4
Given an array of points where each point is represented as points[i] = [xi, yi] on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance, defined as: 

sqrt( (x2 - x1)2 + (y2 - y1)2 )

Note: You can return the k closest points in any order, driver code will sort them before printing.

Examples:

Input: k = 2, points[] = [[1, 3], [-2, 2], [5, 8], [0, 1]]
Output: [[-2, 2], [0, 1]]
Explanation: The Euclidean distances from the origin are:
Point (1, 3) = sqrt(10)
Point (-2, 2) = sqrt(8)
Point (5, 8) = sqrt(89)
Point (0, 1) = sqrt(1)
The two closest points to the origin are [-2, 2] and [0, 1].
Input: k = 1, points = [[2, 4], [-1, -1], [0, 0]]
Output: [[0, 0]]
Explanation: The Euclidean distances from the origin are:
Point (2, 4) = sqrt(20)
Point (-1, -1) = sqrt(2)
Point (0, 0) = sqrt(0)
The closest point to origin is (0, 0).
Constraints:

1 <= k <= points.size() <= 105
-104 <= xi, yi <= 104
*/

class Solution {
public:
    /**
     * Approach:
     * - Use a **max heap (priority queue)** to keep track of the `k` closest points.
     * - Compute the **Euclidean distance squared** for each point (to avoid floating-point operations).
     * - Push each point into the max heap, and if the heap size exceeds `k`, remove the farthest point.
     * - Extract the top `k` elements from the heap and return them.
     *
     * Intuition:
     * - We maintain only the `k` closest points, avoiding unnecessary sorting of all points.
     * - The max heap ensures efficient removal of the farthest element whenever the size exceeds `k`.
     *
     * Time Complexity:
     * - **O(N log K)** (Each insertion/removal in heap takes `O(log K)`, iterating over `N` points)
     *
     * Space Complexity:
     * - **O(K)** (Heap stores at most `k` elements)
     */

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, pair<int, int>>> pq; // Max heap to store k closest points
        
        for (auto &point : points) {
            long long dist = 1LL * point[0] * point[0] + 1LL * point[1] * point[1]; // Compute squared distance
            pq.push({dist, {point[0], point[1]}});

            if (pq.size() > k) { // Remove farthest point if heap size exceeds k
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty()) {
            auto curr = pq.top().second;
            ans.push_back({curr.first, curr.second});
            pq.pop();
        }

        return ans;
    }
};