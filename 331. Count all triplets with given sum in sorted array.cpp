/*
Count all triplets with given sum in sorted array
Difficulty: MediumAccuracy: 48.57%Submissions: 22K+Points: 4
Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.

Examples:

Input: arr[] = [-3, -1, -1, 0, 1, 2], target = -2
Output: 4
Explanation: Two triplets that add up to -2 are:
arr[0] + arr[3] + arr[4] = (-3) + 0 + (1) = -2
arr[0] + arr[1] + arr[5] = (-3) + (-1) + (2) = -2
arr[0] + arr[2] + arr[5] = (-3) + (-1) + (2) = -2
arr[1] + arr[2] + arr[3] = (-1) + (-1) + (0) = -2
Input: arr[] = [-2, 0, 1, 1, 5], target = 1
Output: 0
Explanation: There is no triplet whose sum is equal to 1. 
Constraints:
3 ≤ arr.size() ≤ 104
-105 ≤ arr[i], target ≤ 105
*/

/*
Approach:
1. Use a three-pointer approach:
   - Fix the first element (`arr[i]`).
   - Use two pointers (`j` and `k`) for the remaining array to find combinations that sum up to the target.
2. If the sum of the triplet is equal to the target:
   - Count it as a valid triplet and handle duplicates by moving the second pointer (`j`) forward.
   - Decrement the third pointer (`k`) for the next check.
3. If the sum is greater than the target, decrement the third pointer (`k`) to reduce the sum.
4. If the sum is less than the target, increment the second pointer (`j`) to increase the sum.

Intuition:
The two-pointer technique is efficient in finding pairs within a sorted array that sum to a specific value. By fixing one element and applying this approach, we efficiently count triplets.

Time Complexity:
- Outer loop runs \(O(N)\), where \(N\) is the size of the array.
- The inner two-pointer loop runs \(O(N)\) in total for each fixed element.
Overall: \(O(N^2)\).

Space Complexity:
- The algorithm uses \(O(1)\) additional space.

*/

class Solution {
public:
    int countTriplets(vector<int> &arr, int target) {
        int ans = 0;          // Initialize the count of triplets
        int n = arr.size();   // Size of the array

        for (int i = 0; i < n - 2; i++) { // Fix the first element
            int j = i + 1, k = n - 1;     // Two pointers for the remaining elements

            while (j < k) { // Loop while the two pointers do not overlap
                long long sum = arr[i] + arr[j] + arr[k]; // Calculate the sum of the triplet

                if (sum == target) { // Check if the sum matches the target
                    ans++;           // Count the current triplet
                    int temp = j + 1;

                    // Handle duplicates for the second pointer
                    while (temp < k && arr[temp] == arr[temp - 1]) {
                        temp++;
                        ans++;       // Count duplicate triplets
                    }

                    k--; // Move the third pointer to explore other combinations
                } else if (sum > target) {
                    k--; // Decrement the third pointer to reduce the sum
                } else {
                    j++; // Increment the second pointer to increase the sum
                }
            }
        }

        return ans; // Return the total count of triplets
    }
};
