/*
Equilibrium Point
Difficulty: EasyAccuracy: 28.13%Submissions: 567K+Points: 2
Given an array arr of non-negative numbers. The task is to find the first equilibrium point in an array. The equilibrium point in an array is an index (or position) such that the sum of all elements before that index is the same as the sum of elements after it.

Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

Examples:

Input: arr[] = [1, 3, 5, 2, 2]
Output: 3 
Explanation: The equilibrium point is at position 3 as the sum of elements before it (1+3) = sum of elements after it (2+2). 
Input: arr[] = [1]
Output: 1
Explanation: Since there's only one element hence it's only the equilibrium point.
Input: n = 3, arr[] = [1, 2, 3]
Output: -1
Explanation: There is no equilibrium point in the given array.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size <= 105
0 <= arr[i] <= 109


*/

/**
 * Intuition:
 * - The equilibrium point in an array is a position where the sum of elements on its left is equal to the sum of elements on its right.
 * - Instead of using extra space for prefix sums, we can use a single pass to calculate the total sum and then another pass to find the equilibrium point.
 * - While iterating, we maintain the sum of elements to the left of the current index and use the total sum to find the sum of elements to the right.
 * 
 * Time Complexity:
 * - O(n) for calculating the total sum and another O(n) for finding the equilibrium point. Overall: O(n).
 * 
 * Space Complexity:
 * - O(1) since we are using only a few extra variables.
 */

class Solution {
public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &arr) {
        int n = arr.size();
        if (n == 1) return 1; // Edge case: Single element is always an equilibrium point

        // Calculate the total sum of the array
        long long totalSum = accumulate(arr.begin(), arr.end(), 0LL);
        
        long long leftSum = 0; // Initialize left sum to 0
        
        // Iterate through the array to find the equilibrium point
        for (int i = 0; i < n; i++) {
            // Check if the left sum equals the right sum
            if (leftSum == (totalSum - leftSum - arr[i])) {
                return i + 1; // Return the 1-based index
            }
            // Update the left sum by adding the current element
            leftSum += arr[i];
        }

        return -1; // No equilibrium index found
    }
};


/**
 * Intuition:
 * - The equilibrium point in an array is a position where the sum of elements on its left is equal to the sum of elements on its right.
 * - To find this point, we can precompute the prefix sums from both left and right.
 * - If at any position the left sum equals the right sum, we have found our equilibrium point.
 * 
 * Time Complexity:
 * - O(n) for computing prefix sums and O(n) for checking the equilibrium point. Overall: O(n).
 * 
 * Space Complexity:
 * - O(n) for storing prefix sums from both sides.
 */

class Solution {
  public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &arr) {
        int n = arr.size();
        if(n == 1)
            return 1; // Single element is always an equilibrium point
            
        vector<long long> leftSum(n), rightSum(n);
        
        // Initialize the first element of leftSum and last element of rightSum
        leftSum[0] = arr[0];
        rightSum[n-1] = arr[n-1];
        
        // Compute prefix sums from the left
        for(int i=1; i<n; i++){
            leftSum[i] = leftSum[i - 1] + arr[i];
            rightSum[n - i - 1] = arr[n - i - 1] + rightSum[n - i];
        }
        
        // Check for the equilibrium point
        for(int i=0; i<n; i++){
            if(leftSum[i] == rightSum[i])
                return i+1; // Return the 1-based index
        }
        
        return -1; // If no equilibrium point is found
    }
};
