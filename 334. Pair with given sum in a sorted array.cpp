/*
Pair with given sum in a sorted array
Difficulty: EasyAccuracy: 26.04%Submissions: 59K+Points: 2
You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
Note: pairs should have elements of distinct indexes. 

Examples :

Input: arr[] = [-1, 1, 5, 5, 7], target = 6
Output: 3
Explanation: There are 2 pairs which sum up to 6 : {1, 5}, {1, 5} and {-1, 7}.
Input: arr[] = [1, 1, 1, 1], target = 2
Output: 6
Explanation: There are 6 pairs which sum up to 2 : {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1} and {1, 1}.
Input: arr[] = [-1, 10, 10, 12, 15], target = 125
Output: 0
Explanation: There is no such pair which sums up to 4.
Constraints:
-105 <= target <=105
 2 <= arr.size() <= 105
-105 <= arr[i] <= 105
*/

/*
Approach:
1. Use the two-pointer technique to find pairs in a sorted array whose sum equals the target.
2. Initialize two pointers:
   - `start` at the beginning of the array.
   - `end` at the end of the array.
3. Check the sum of the elements at `start` and `end`:
   - If the sum equals the target, increment the count (`ans`) and adjust the pointers.
   - If the sum is greater than the target, move the `end` pointer to the left.
   - If the sum is less than the target, move the `start` pointer to the right.

Intuition:
The two-pointer technique optimizes the search for pair sums in a sorted array. By narrowing the search space with each comparison, the solution avoids unnecessary computations.

Time Complexity:
- Sorting the array: \(O(N \log N)\), where \(N\) is the size of the array.
- Two-pointer traversal: \(O(N)\).
Overall: \(O(N \log N)\).

Space Complexity:
- Sorting may require \(O(\log N)\) additional space depending on the sorting algorithm.
- Otherwise, \(O(1)\) extra space is used.
Overall: \(O(\log N)\) or \(O(1)\).

*/

class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        // Initialize pointers and count
        int start = 0, end = arr.size() - 1;
        int ans = 0;

        // Use the two-pointer approach
        while (start < end) {
            int sum = arr[start] + arr[end]; // Calculate the current pair sum

            if (sum == target) { // If the pair sum equals the target
                ans++;           // Increment the count
                int temp = start + 1;

                // Check for duplicates and count them
                while (temp < end && arr[temp] == arr[temp - 1]) {
                    ans++;
                    temp++;
                }

                end--; // Move the `end` pointer to the left
            }
            else if (sum > target) { // If the sum is greater than the target
                end--; // Move the `end` pointer to the left
            }
            else { // If the sum is less than the target
                start++; // Move the `start` pointer to the right
            }
        }

        return ans; // Return the total count of pairs
    }
};
