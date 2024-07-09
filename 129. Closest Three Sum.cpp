/*
Closest Three Sum
Difficulty: MediumAccuracy: 17.65%Submissions: 58K+Points: 4
Given an array, arr of integers, and another number target, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

Note: If there are multiple solutions, return the maximum one.

Examples :

Input: arr[] = [-7, 9, 8, 3, 1, 1], target = 2
Output: 2
Explanation: There is only one triplet present in the array where elements are -7,8,1 whose sum is 2.
Input: arr[] = [5, 2, 7, 5], target = 13
Output: 14
Explanation: There is one triplet with sum 12 and other with sum 14 in the array. Triplet elements are 5, 2, 5 and 2, 7, 5 respectively. Since abs(13-12) ==abs(13-14) maximum triplet sum will be preferred i.e 14.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
3 ≤ arr.size() ≤ 103
-105 ≤ arr[i] ≤ 105
1 ≤ target ≤ 105
*/

/*
 * Intuition:
 * The goal is to find the triplet in the array whose sum is closest to the target value.
 * We can achieve this by first sorting the array, and then using a two-pointer technique for each element.
 * This allows us to efficiently narrow down the closest sum.
 *
 * Time Complexity: O(n^2), where n is the number of elements in the array. We iterate through each element and use the two-pointer approach, which is O(n) for each iteration.
 * Space Complexity: O(1), as we use only a few extra variables for calculations.
 */

class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); // Sort the array to use two-pointer technique
        int diff = INT_MAX; // Initialize the minimum difference to a large value
        int ans = 0; // Variable to store the closest sum
        int n = arr.size(); // Size of the array
        
        // Iterate through each element in the array
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1; // Initialize the second pointer
            int k = n - 1; // Initialize the third pointer
            
            // Use the two-pointer approach to find the closest sum for the current element
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k]; // Calculate the sum of the triplet
                int d = abs(target - sum); // Calculate the difference from the target
                
                // Update the closest sum and minimum difference if a closer sum is found
                if (d < diff) {
                    diff = d;
                    ans = sum;
                } else if (d == diff) {
                    ans = max(ans, sum); // Ensure we get the maximum sum if two sums have the same difference
                }
                
                // Adjust the pointers based on the comparison of the sum and target
                if (sum == target)
                    return sum; // Return immediately if the sum equals the target
                else if (sum < target)
                    j++; // Move the second pointer to the right to increase the sum
                else
                    k--; // Move the third pointer to the left to decrease the sum
            }
        }
        
        return ans; // Return the closest sum
    }
};
