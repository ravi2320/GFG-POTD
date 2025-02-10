/*
K Sum Paths
Difficulty: MediumAccuracy: 44.73%Submissions: 108K+Points: 4
Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).

Examples:

Input: k = 7   

Output: 3
Explanation: The following paths sum to k 
 
Input: k = 3
   1
  /  \
2     3
Output: 2
Explanation:
Path 1 : 1 -> 2 (Sum = 3)
Path 2 : 3 (Sum = 3)
Constraints:

1 ≤ number of nodes ≤ 104
-100 ≤ node value ≤ 100
-109 ≤ k ≤ 109
*/

/*
Approach:
1. Use a **recursive DFS** approach to traverse the tree.
2. Maintain a **running sum** (`currSum`) from the root to the current node.
3. Use an **unordered_map (`mp`)** to store the prefix sum frequencies.
4. If `currSum == k`, increment the count (`cnt`).
5. If `(currSum - k)` exists in the map, it means there is a subpath that sums to `k`, so add its frequency to `cnt`.
6. Recur for left and right subtrees.
7. After returning from recursion, decrement the prefix sum frequency to maintain correctness.

Intuition:
- We need to find **subpaths** (not necessarily starting from the root) with sum `k`.
- Instead of recomputing sums for every possible path (which is **O(N²)**), we use a **prefix sum hashmap** to check in **O(1)** whether a subpath with sum `k` exists.

Time Complexity: **O(N)**
- Each node is visited **once**.
- Hashmap operations (`insert`, `lookup`, `erase`) take **O(1) on average**.

Space Complexity: **O(N)**
- The recursion stack may take **O(N) in the worst case** (skewed tree).
- The hashmap can store up to **N unique prefix sums** in the worst case.
*/

class Solution {
  public:
    // Helper function to count paths with sum k
    void solve(Node* root, int k, int &cnt, unordered_map<int, int> &mp, int currSum) {
        if (!root) return;
        
        // Update current sum
        currSum += root->data;
        
        // If current sum equals k, increment count
        if (currSum == k) {
            cnt++;
        }
        
        // If (currSum - k) exists in the map, it means there is a subpath sum equal to k
        if (mp.find(currSum - k) != mp.end()) {
            cnt += mp[currSum - k];
        }
        
        // Store the current prefix sum count
        mp[currSum]++;
        
        // Recur for left and right subtrees
        solve(root->left, k, cnt, mp, currSum);
        solve(root->right, k, cnt, mp, currSum);
        
        // Backtrack: remove current sum from the map (to ensure path independence)
        mp[currSum]--;
    }

    int sumK(Node *root, int k) {
        int cnt = 0;
        unordered_map<int, int> mp; // Map to store prefix sum frequencies
        solve(root, k, cnt, mp, 0);
        return cnt;
    }
};