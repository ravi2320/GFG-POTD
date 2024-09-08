/*
Minimum Jumps
Difficulty: MediumAccuracy: 11.91%Submissions: 864K+Points: 4
Given an array arr[] of non-negative integers. Each array element represents the maximum length of the jumps that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
Find the minimum number of jumps to reach the end of the array starting from the first element. If an element is 0, then you cannot move through that element.
Note:  Return -1 if you can't reach the end of the array.

Examples : 

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 
Explanation:First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last. 
Input: arr = {1, 4, 3, 2, 6, 7}
Output: 2 
Explanation: First we jump from the 1st to 2nd element and then jump to the last element.
Input: arr = {0, 10, 20}
Output: -1
Explanation: We cannot go anywhere from the 1st element.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
0 ≤ arr[i] ≤ 105
2 ≤ arr.size() ≤ 106
*/

Approach:

Base Case: If the first element is 0, it's impossible to reach the end, so return -1.
Initialization: Set the initial jump count to 1, the current jump distance to the value of the first element, and the maximum reachable index to 0.
Iterate through the array:
Decrement the current jump distance.
Update the maximum reachable index.
If the current jump distance becomes 0 and we haven't reached the end of the array:
Check if the maximum reachable index is 0. If so, it's impossible to reach the end, return -1.
Otherwise, update the current jump distance to the maximum reachable index and increment the jump count.
Return the jump count: Return the final jump count.
Time Complexity: O(n)
Space Complexity: O(1)

Code with Comments:

C++
class Solution {
public:
    int minJumps(vector<int>& arr) {
        // Base case: If the first element is 0, it's impossible to reach the end
        if (!arr[0]) return -1;

        // Initialize variables
        int ans = 1, jump = arr[0], mx = 0;
        int n = arr.size();

        // Iterate through the array
        for (int i = 1; i < n; i++) {
            // Decrement the current jump distance
            jump--;

            // Update the maximum reachable index
            mx = max(mx, arr[i]);

            // If the current jump distance becomes 0 and we haven't reached the end
            if (!jump && i != n - 1) {
                // Check if it's impossible to reach the end
                if (mx <= 0) return -1;

                // Update the current jump distance and increment the jump count
                jump = mx;
                mx = 0;
                ans++;
            }
        }

        return ans;
    }
};