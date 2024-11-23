/*
Minimize the Heights I
Difficulty: MediumAccuracy: 26.16%Submissions: 100K+Points: 4
Given a positive integer k and an array arr[] denoting heights of towers, you have to modify the height of each tower either by increasing or decreasing them by k only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

Note: A slight modification of the problem can be found here. 

Examples:

Input: k = 2, arr[] = [1, 5, 8, 10]
Output: 5
Explanation: The array can be modified as [3, 3, 6, 8]. The difference between the largest and the smallest is 8 - 3 = 5.
Input: k = 3, arr[] = [3, 9, 12, 16, 20]
Output: 11
Explanation: The array can be modified as [6, 12, 9, 13, 17]. The difference between the largest and the smallest is 17 - 6 = 11. 
Constraints
1 ≤ k ≤ 104
1 ≤ number of towers ≤ 105
0 ≤ arr[i] ≤ 105
*/

/*
Approach:
1. The problem aims to minimize the maximum difference between the highest and lowest values in the array after modifying each element.
2. Each element in the array can be either increased or decreased by `k`.
3. The strategy involves:
   - Sorting the array to easily handle minimum and maximum values.
   - Adjusting the smallest (`arr[0]`) and largest (`arr[n-1]`) elements of the sorted array to minimize the difference.
   - Iterating through the sorted array and checking the potential minimum and maximum values after modification.
   - Calculating the difference between the modified maximum and minimum for each iteration and keeping track of the minimum difference.
   
Steps:
1. Sort the array.
2. Initialize the answer as the initial difference between the maximum and minimum values in the sorted array.
3. Iterate from the start to the second-last element, adjusting the minimum and maximum values after adding/subtracting `k`.
4. Update the answer with the minimum difference found.

Time Complexity:
- O(n log n) — due to sorting the array.

Space Complexity:
- O(1) — no additional space is used apart from input and a few variables.

*/

class Solution {
public:
    // Function to get the minimum difference between max and min values after modification
    int getMinDiff(int k, vector<int> &arr) {
        int n = arr.size();

        // If there's only one element, no modification is possible
        if (n == 1) return 0;

        // Sort the array to handle the elements in ascending order
        sort(arr.begin(), arr.end());

        // Initial difference between max and min in the sorted array
        int ans = arr[n - 1] - arr[0];

        // Iterate through the array to adjust the min and max values
        for (int i = 0; i < n - 1; i++) {
            // Compute new potential minimum and maximum values
            int mn = min(arr[i + 1] - k, arr[0] + k);  // Minimum value after modification
            int mx = max(arr[n - 1] - k, arr[i] + k);  // Maximum value after modification

            // Update the answer with the minimum difference found
            ans = min(ans, abs(mx - mn));
        }

        return ans;  // Return the minimized difference
    }
};
