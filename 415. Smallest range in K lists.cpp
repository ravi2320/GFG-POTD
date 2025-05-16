/*
Smallest range in K lists
Difficulty: HardAccuracy: 43.21%Submissions: 35K+Points: 8Average Time: 40m
Given a 2d integer array arr[][] of size k*n, where each row is sorted in ascending order. Your task is to find the smallest range [l, r] that includes at least one element from each of the k lists. If more than one such ranges are found, return the first one.

Examples:

Input: n = 5, k = 3, arr[][] = [[4, 7, 9, 12, 15], [0, 8, 10, 14, 20], [6, 12, 16, 30, 50]]
Output: [6, 8]
Explanation: Smallest range is formed by  number 7 from the first list, 8 from second list and 6 from the third list.
Input: n = 5, k = 3, arr[][] = [[1, 3, 5, 7, 9], [0, 2, 4, 6, 8], [2, 3, 5, 7, 11]]
Output: [1, 2]
Explanation: Smallest range is formed by number 1 present in first list and 2 is present in both 2nd and 3rd list.
Input: n = 2, k = 3, arr[][] = [[2, 4], [1, 7], [20, 40]]
Output: [4, 20]
Explanation: Smallest range is formed by number 4 from the first list, 7 from second list and 20 from the third list.
Constraints:
1 <= k, n <= 500
0 <= arr[ i ] <= 105
*/

/*
Approach:
- Given k sorted lists, we want to find the smallest range [L, R] that includes at least one number from each list.
- Use a min-heap (priority queue) to keep track of the current minimum among the current elements from each list.
- Track the current maximum separately.
- Continuously update the smallest range found so far while ensuring all k lists contribute.

Intuition:
- At every step, we include the current min and max from the heap and current elements.
- We remove the current min and add the next element from the same list to maintain representation from all lists.
- Stop when any list runs out of elements.

Time Complexity:
- O(N log k), where N is the total number of elements and k is the number of lists.

Space Complexity:
- O(k) for the heap.

*/

class Solution {
public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        int k = arr.size();

        // Min-heap: {value, list index, element index within the list}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<int> range = {-1000000, 1000000}; // Initial large range
        int maxEle = INT_MIN;

        // Push the first element of each list and track the initial maximum
        for (int i = 0; i < k; i++) {
            pq.push({arr[i][0], i, 0});
            maxEle = max(maxEle, arr[i][0]);
        }

        // While all lists are represented in the heap
        while (!pq.empty()) {
            int minEle = pq.top()[0];         // Current minimum element
            int minListIdx = pq.top()[1];     // From which list
            int minEleIdx = pq.top()[2];      // Index within that list
            pq.pop();

            // Update range if smaller
            if (maxEle - minEle < range[1] - range[0]) {
                range[0] = minEle;
                range[1] = maxEle;
            }

            // Move to next element in the list where minEle was taken from
            if (minEleIdx + 1 < arr[minListIdx].size()) {
                int nextEle = arr[minListIdx][minEleIdx + 1];
                pq.push({nextEle, minListIdx, minEleIdx + 1});
                maxEle = max(maxEle, nextEle); // Update current max
            } else {
                // If we reach the end of one list, we cannot continue
                break;
            }
        }

        return range;
    }
};