/*
Rotate Deque By K
Difficulty: EasyAccuracy: 77.0%Submissions: 14K+Points: 2
You are given a deque dq[] (double-ended queue) containing non-negative integers, along with two positive integer type and k. The task is to rotate the deque circularly by k positions.
There are two types of rotation operations:


Right Rotation (Clockwise): If type = 1, rotate the deque to the right. This means moving the last element to the front, and repeating the process k times.

Left Rotation (Anti-Clockwise): If type = 2, rotate the deque to the left. This means moving the first element to the back, and repeating the process k times.

Examples:

Input: dq = [1, 2, 3, 4, 5, 6], type = 1, k = 2
Output: [5, 6, 1, 2, 3, 4] 
Explanation: The type is 1 and k is 2. So, we need to right rotate dequeue by 2 times.
In first right rotation we get [6, 1, 2, 3, 4, 5].
In second right rotation we get [5, 6, 1, 2, 3, 4].
Input: dq = [10, 20, 30, 40, 50], type = 2, k = 3 
Output: [40, 50, 10, 20, 30] 
Explanation: The type is 2 and k is 3. So, we need to left rotate dequeue by 3 times.
In first left rotation we get [20, 30, 40, 50, 10]. 
In second left rotation we get [30, 40, 50, 10, 20].
In third left rotation we get [40, 50, 10, 20, 30].
Constraints:
1 ≤ dq.size() ≤ 105 
1 ≤ k ≤ 105 
1 ≤ type ≤ 2
*/

/*
Approach:
1. We are asked to rotate a deque `dq` either left or right by `k` positions.
   - type = 1 → Left rotation
   - type = 2 → Right rotation
2. Standard trick for array/deque rotation → use the **reversal algorithm**:
   - For left rotation by k:
        reverse first k elements, reverse remaining (n-k) elements, then reverse entire array.
   - For right rotation by k:
        reverse last k elements, reverse first (n-k) elements, then reverse entire array.
3. In this implementation:
   - We first reverse the entire deque.
   - Then apply reversal on subparts depending on type (1 = left, else right).

Intuition:
- Rotation can be converted to reversing segments in a specific order.
- Using `reverse` is efficient and avoids shifting elements one by one.

Time Complexity:
- O(n), since each reverse call is O(n) and we do it at most 3 times.
Space Complexity:
- O(1), done in-place using iterators.

*/

class Solution {
public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        int n = dq.size();
        if (n == 0) return;  // edge case: empty deque

        k = k % n;  // handle cases where k >= n

        // Step 1: Reverse the entire deque
        reverse(dq.begin(), dq.end());

        if (type == 1) {  
            // Left rotation
            reverse(dq.begin(), dq.begin() + k);   // reverse first k elements
            reverse(dq.begin() + k, dq.end());     // reverse rest
        } 
        else {  
            // Right rotation
            reverse(dq.rbegin(), dq.rbegin() + k); // reverse last k elements
            reverse(dq.rbegin() + k, dq.rend());   // reverse rest
        }
    }
};
