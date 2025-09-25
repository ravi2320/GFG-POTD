/*
Generate Binary Numbers
Difficulty: EasyAccuracy: 67.48%Submissions: 59K+Points: 2
Given a number n. The task is to generate all binary numbers with decimal values from 1 to n.

Examples:

Input: n = 4
Output: ["1", "10", "11", "100"]
Explanation: Binary numbers from 1 to 4 are 1, 10, 11 and 100.
Input: n = 6
Output: ["1", "10", "11", "100", "101", "110"]
Explanation: Binary numbers from 1 to 6 are 1, 10, 11, 100, 101 and 110.
Constraints:
1 ≤ n ≤ 106
*/

/*
Approach:
1. Use a queue to simulate level-order (BFS) generation of binary numbers.
2. Start with "1" in the queue.
3. Repeatedly pop the front element, add it to the answer list.
4. Push the current element + "0" and current element + "1" back into the queue.
5. Repeat this process `n` times to generate the first `n` binary numbers.

Intuition:
- This is similar to generating numbers in binary using a binary tree structure:
       "1"
      /   \
    "10"  "11"
   /  \   /  \
 "100" "101" ...
- By BFS traversal, we get binary numbers in increasing order.

Time Complexity:
- O(n * k), where `k` is the average length of binary strings (≈ log n).
- Each string operation (concatenation, push, pop) costs O(k).
Space Complexity:
- O(n * k) for storing the result and queue.

*/

class Solution {
  public:
    vector<string> generateBinary(int n) {
        vector<string> ans;       // To store result
        queue<string> q;          // BFS queue
        q.push("1");              // Start with first binary number "1"
        
        for (int i = 0; i < n; i++) {
            string curr = q.front();
            q.pop();
            
            ans.push_back(curr);   // Add current binary number to result
            
            // Generate next two binary numbers
            q.push(curr + "0");
            q.push(curr + "1");
        }
        
        return ans;
    }
};


