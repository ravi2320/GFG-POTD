/*
Trapping Rain Water
Difficulty: HardAccuracy: 33.14%Submissions: 447K+Points: 8
Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 

Examples:

Input: arr[] = [3, 0, 1, 0, 4, 0 2]
Output: 10
Explanation: Total water trapped = 0 + 3 + 2 + 3 + 0 + 2 + 0 = 10 units.

Input: arr[] = [3, 0, 2, 0, 4]
Output: 7
Explanation: Total water trapped = 0 + 3 + 1 + 3 + 0 = 7 units.
Input: arr[] = [1, 2, 3, 4]
Output: 0
Explanation: We cannot trap water as there is no height bound on both sides.
Input: arr[] = [2, 1, 5, 3, 1, 0, 4]
Output: 9
Explanation: Total water trapped = 0 + 1 + 0 + 1 + 3 + 4 + 0 = 9 units.
Constraints:
1 < arr.size() < 105
0 < arr[i] < 103
*/

/*
Approach:
1. Precompute the maximum heights from the left (`prefixMax`) and the right (`suffixMax`) for each position in the array.
2. For each position `i` (excluding the first and last positions):
   - Calculate the water trapped as `min(prefixMax[i], suffixMax[i]) - arr[i]`.
   - Add this to the total trapped water.
3. Return the total trapped water.

Intuition:
- Water can only be trapped at position `i` if there are taller bars to both the left and the right.
- The height of the water at position `i` is determined by the shorter of the tallest bars to its left and right minus its height.

Time Complexity:
- \(O(n)\): One pass to compute `prefixMax`, one pass to compute `suffixMax`, and one pass to calculate the water trapped.
  
Space Complexity:
- \(O(n)\): For the `prefixMax` and `suffixMax` arrays.

Edge Cases:
1. If the array length is less than 3, no water can be trapped, return 0.
2. If all elements are the same, no water is trapped, return 0.
3. Arrays with increasing or decreasing heights trap no water.

*/

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int n = arr.size();
        
        // If there are less than 3 bars, water cannot be trapped
        if (n < 3) return 0;

        // Arrays to store the maximum heights from the left and right
        vector<int> prefixMax(n, 0), suffixMax(n, 0);

        // Compute prefix maximums
        prefixMax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i - 1], arr[i]);
        }

        // Compute suffix maximums
        suffixMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], arr[i]);
        }

        int ans = 0;  // Variable to store the total water trapped

        // Calculate the water trapped at each position
        for (int i = 1; i < n - 1; i++) {
            ans += min(prefixMax[i], suffixMax[i]) - arr[i];
        }

        return ans;
    }
};

/*
Approach:
1. Use two pointers (`i` and `j`) to traverse the array from both ends.
2. Maintain two variables (`leftMax` and `rightMax`) to store the maximum heights encountered so far from the left and right sides, respectively.
3. At each step:
   - If `leftMax` is less than or equal to `rightMax`:
     - Check if `arr[i]` can trap water. If `arr[i]` is less than `leftMax`, add the trapped water to the result.
     - Update `leftMax` if `arr[i]` exceeds it.
     - Move the left pointer (`i`) to the right.
   - Otherwise:
     - Check if `arr[j]` can trap water. If `arr[j]` is less than `rightMax`, add the trapped water to the result.
     - Update `rightMax` if `arr[j]` exceeds it.
     - Move the right pointer (`j`) to the left.
4. Continue until the two pointers meet.

Intuition:
- Water can only be trapped above a bar if there are taller bars on both sides.
- The amount of water trapped is limited by the shorter of the two taller bars (`leftMax` and `rightMax`).

Time Complexity:
- \(O(n)\): Each element is processed at most once as the two pointers converge.

Space Complexity:
- \(O(1)\): No additional space is used apart from a few variables.

Edge Cases:
1. If the array has fewer than 3 elements, return 0.
2. Uniform or monotonic arrays trap no water.
3. Arrays with large dips between taller bars capture significant water.

*/

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int n = arr.size();

        // If there are less than 3 bars, water cannot be trapped
        if (n < 3) return 0;

        int leftMax = 0, rightMax = 0;  // To store the maximum heights from left and right
        int i = 0, j = n - 1;          // Two pointers for traversal
        int ans = 0;                   // To store the total water trapped

        // Traverse the array using two pointers
        while (i <= j) {
            if (leftMax <= rightMax) {
                // Process the left side
                if (leftMax > arr[i]) {
                    ans += leftMax - arr[i];  // Water trapped above `arr[i]`
                } else {
                    leftMax = arr[i];         // Update the left maximum
                }
                i++;
            } else {
                // Process the right side
                if (rightMax > arr[j]) {
                    ans += rightMax - arr[j];  // Water trapped above `arr[j]`
                } else {
                    rightMax = arr[j];         // Update the right maximum
                }
                j--;
            }
        }

        return ans;  // Return the total water trapped
    }
};