/*
Roof Top
Difficulty: EasyAccuracy: 40.48%Submissions: 68K+Points: 2
You are given the heights of consecutive buildings. You can move from the roof of a building to the roof of the next adjacent building. You need to find the maximum number of consecutive steps you can put forward such that you gain an increase in altitude with each step.

Examples:

Input: arr[] = [1, 2, 2, 3, 2]
Output: 1
Explanation: 1, 2, or 2, 3 are the only consecutive buildings with increasing heights thus maximum number of consecutive steps with an increase in gain in altitude would be 1 in both cases.
Input: arr[] = [1, 2, 3, 4]
Output: 3
Explanation: 1 to 2 to 3 to 4 is the jump of length 3 to have a maximum number of buildings with increasing heights, so maximum steps with increasing altitude becomes 3.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 106
1 <= arr[i] <= 105
*/

/*
 * Approach:
 * 1. Iterate through the array, comparing each element with the previous one to check if the altitude increases.
 * 2. Maintain a counter (`cnt`) to track the current number of consecutive increasing steps.
 * 3. If the current element is not greater than the previous one, update the result (`res`) with the maximum value of `cnt` and reset `cnt`.
 * 4. Continue this process and update `res` with the final value of `cnt` if it was not reset.
 * 
 * Time Complexity: O(N), where N is the size of the array, as we iterate through the array once.
 * Space Complexity: O(1), as only a few variables are used.
 */

class Solution {
public:
    // Function to find the maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        int res = 0;  // Variable to store the maximum number of consecutive steps
        int cnt = 0;  // Counter for current consecutive increasing steps
        int n = arr.size();  // Size of the array
        
        // Loop through the array starting from the second element
        for (int i = 1; i < n; i++) {
            // If the current element is greater than the previous, increment the count
            if (arr[i] > arr[i - 1]) {
                cnt++;
            } else {
                // If not, update the result with the maximum count and reset the count
                res = max(res, cnt);
                cnt = 0;
            }
        }
        
        // Final check to ensure the last sequence of steps is counted
        res = max(res, cnt);
        
        return res;  // Return the maximum number of consecutive steps found
    }
};
