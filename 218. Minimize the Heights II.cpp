/*
Minimize the Heights II
Difficulty: MediumAccuracy: 15.06%Submissions: 604K+Points: 4
Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

Examples :

Input: k = 2, arr[] = {1, 5, 8, 10}
Output: 5
Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}.The difference between the largest and the smallest is 8-3 = 5.
Input: k = 3, arr[] = {3, 9, 12, 16, 20}
Output: 11
Explanation: The array can be modified as {3+k, 9+k, 12-k, 16-k, 20-k} -> {6, 12, 9, 13, 17}.The difference between the largest and the smallest is 17-6 = 11. 
Expected Time Complexity: O(n*logn)
Expected Auxiliary Space: O(n)

Constraints
1 ≤ k ≤ 107
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 107
*/

/*
Approach:
1. First, we sort the array, which helps in determining the possible minimum and maximum heights after the modification.
2. After sorting, the difference between the largest and smallest element is `arr[n-1] - arr[0]` (initial result).
3. For each element, we attempt to minimize the maximum difference by modifying the height:
   - Increase the smallest element `arr[0]` by `k`.
   - Decrease the largest element `arr[n-1]` by `k`.
   - For each element `i` in the array, we calculate the possible minimum (`mn`) and maximum (`mx`) heights by adjusting `arr[i]` and update the answer accordingly.
4. If reducing an element by `k` makes it negative, we skip that iteration.

Time Complexity:
- O(n log n): The array is sorted in O(n log n) and then we iterate through the array in O(n) to calculate the minimum difference.

Space Complexity:
- O(1): We are using constant extra space.

*/

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if(n == 1) return 0;  // If there's only one element, no difference

        // Sort the array to determine min and max heights
        sort(arr.begin(), arr.end());

        // Initialize the answer as the initial difference between max and min
        int ans = arr[n-1] - arr[0];

        int mx, mn;

        // Iterate through the array and calculate the minimum possible difference
        for(int i = 1; i < n; i++) {
            // Skip if reducing arr[i] by k makes it negative
            if(arr[i] - k < 0) continue;
            
            // Calculate the new minimum and maximum
            mn = min(arr[0] + k, arr[i] - k);   // Either increase the smallest or decrease the current element
            mx = max(arr[n-1] - k, arr[i-1] + k); // Either decrease the largest or increase the previous element
            
            // Update the answer with the smallest difference
            ans = min(ans, mx - mn);
        }

        return ans;
    }
};
