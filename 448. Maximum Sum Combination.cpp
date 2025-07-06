/*
Maximum Sum Combination
Difficulty: MediumAccuracy: 49.69%Submissions: 85K+Points: 4Average Time: 30m
You are given two integer arrays a[] and b[] of equal size. A sum combination is formed by adding one element from a[] and one from b[], using each index pair (i, j) at most once. Return the top k maximum sum combinations, sorted in non-increasing order.

Examples:

Input: a[] = [3, 2], b[] = [1, 4], k = 2
Output: [7, 6]
Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums are 7 and 6.
Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
Output: [10, 9, 9]
Explanation: The top 3 maximum possible sums are : 4 + 6 = 10, 3 + 6 = 9, and 4 + 5 = 9
Constraints:
1 ≤ a.size() = b.size() ≤ 105
1 ≤ k ≤ a.size()
1 ≤ a[i], b[i] ≤ 104
*/

/*
Approach:
- Given two arrays a and b, we want to find the top `k` maximum sums of pairs (a[i] + b[j]).
- To efficiently get the top k largest pair sums, we:
  1. Sort both arrays in descending order.
  2. Use a max heap (priority_queue) to always access the largest unprocessed pair sum.
  3. Push the initial largest pair (a[0] + b[0]) into the heap.
  4. For each extracted max pair, we push the next two possible pairs:
     (i+1, j) and (i, j+1) if they haven't been visited before.
- Use a set `visited` to avoid recomputing the same index pairs.

Intuition:
- Similar to K-way merge or merging sorted matrix diagonals,
  this strategy avoids computing all possible pair sums (which is O(n²)).

Time Complexity:
- O(k * log k): At most k elements are pushed and popped from the heap.
- O(k * log k) for priority queue operations, assuming set insertion is O(log k).
- Sorting takes O(n log n), where n = size of input arrays.

Space Complexity:
- O(k) for heap + O(k) for visited set + O(k) for output vector = O(k) overall.
*/

class Solution {
public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.rbegin(), a.rend());  // Sort descending
        sort(b.rbegin(), b.rend());

        int n = a.size();
        vector<int> ans;

        // Max heap: (sum, (i, j)) -> i and j are indices in arrays a and b
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> visited;

        // Start with the largest possible sum
        pq.push({a[0] + b[0], {0, 0}});
        visited.insert({0, 0});

        while (k-- && !pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int sum = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            ans.push_back(sum);

            // Try next pair with a[i+1] and b[j]
            if (i + 1 < n && !visited.count({i + 1, j})) {
                pq.push({a[i + 1] + b[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            // Try next pair with a[i] and b[j+1]
            if (j + 1 < n && !visited.count({i, j + 1})) {
                pq.push({a[i] + b[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return ans;
    }
};
