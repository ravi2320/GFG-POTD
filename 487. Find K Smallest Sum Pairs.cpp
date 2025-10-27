/*
Find K Smallest Sum Pairs

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 57.75%Submissions: 2K+Points: 4
Given two integer arrays arr1[] and arr2[] sorted in ascending order and an integer k, your task is to find k pairs with the smallest sums, such that one element of each pair belongs to arr1[] and the other belongs to arr2[].

Return the list of these k pairs, where each pair is represented as [arr1[i], arr2[j]].

Note: You can return any possible k pairs with the smallest sums, the driver code will print true if it is correct else it will print false.

Examples:

Input: arr1[] = [1, 7, 11], arr2[] = [2, 4, 6], k = 3
Output: true
Explanation: All possible combinations of elements from the two arrays are:
[1, 2], [1, 4], [1, 6], [7, 2], [7, 4], [7, 6], [11, 2], [11, 4], [11, 6]. 
Among these, the three pairs with the minimum sums are [1, 2], [1, 4], [1, 6].
Input: arr1[] = [1, 3], arr2[] = [2, 4] k = 2
Output: true
Explanation: All possible combinations are [1, 2], [1, 4], [3, 2], [3, 4]. 
Among these, the two pairs with the minimum sums are [1, 2], [3, 2].
Constraints:
1 ≤ arr1.size(), arr2.size() ≤ 5*104
1 ≤ arr1[i], arr2[j] ≤ 109
1 ≤ k ≤ 103
*/

// Intuition:
// The problem is to find the k smallest pairs from two sorted arrays. The smallest pair will be the pair with the smallest sum. 
// We can use a min-heap (priority queue) to maintain the smallest possible sums and pop the smallest sums iteratively.
// The priority queue will store each pair in the form (sum, pair(first element, second element)).

// Time Complexity:
// - Pushing each pair into the priority queue takes O(log k), where k is the size of the priority queue.
// - For each pair in the arrays, we are pushing it to the priority queue. The number of pairs we push is at most min(n, k) * min(m, k), where n is the size of arr1 and m is the size of arr2.
//   Hence, the time complexity is O(k * log k) for each pair (assuming k is small).
// - The final while loop takes O(k) to pop the k smallest pairs from the priority queue.

 // Space Complexity:
 // - We are storing at most k elements in the priority queue, so the space complexity is O(k).
 // - The output array stores k pairs, so the space complexity for that is also O(k).

class Solution {
    typedef pair<int, pair<int, int>> P; // Define a type for the priority queue element: (sum, (first element, second element))
  public:
    vector<vector<int>> kSmallestPair(vector<int> &arr1, vector<int> &arr2, int k) {
        // Create a min-heap priority queue to store pairs of elements with their sums
        priority_queue<P, vector<P>, greater<P>> minQ;

        // Add the first k pairs from arr1 and arr2 to the priority queue.
        // We will push pairs (arr1[i] + arr2[j], (arr1[i], arr2[j])) into the queue.
        for(int i = 0; i < min((int)arr1.size(), k); i++) {
            for(int j = 0; j < min((int)arr2.size(), k); j++) {
                // Push sum of pair and the pair itself
                minQ.push({arr1[i] + arr2[j], {arr1[i], arr2[j]}});
            }
        }

        vector<vector<int>> ans; // To store the resulting k smallest pairs
        int cnt = 0; // Counter to track how many pairs we have added to the result

        // Extract the smallest k pairs from the min heap and add them to the answer
        while(!minQ.empty() && cnt < k) {
            auto curr = minQ.top(); // Get the smallest pair (based on sum)
            minQ.pop(); // Remove the smallest element from the queue

            // Push the pair into the result (output vector)
            ans.push_back({curr.second.first, curr.second.second});
            cnt++; // Increment the counter
        }

        return ans; // Return the final result containing k smallest pairs
    }
};
