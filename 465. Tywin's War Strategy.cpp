/*
Tywin's War Strategy

You are given an array arr[] of size n, where arr[i] represents the number of soldiers in the i-th troop. You are also given an integer k. A troop is considered "lucky" if its number of soldiers is a multiple of k. Find the minimum total number of soldiers to add across all troops so that at least ⌈n / 2⌉ troops become lucky.

Examples:

Input: arr = [5, 6, 3, 2, 1], k = 2
Output: 1
Explanation: By adding 1 soldier for the troop with 1 soldier, we get [5, 6, 3, 2, 2]. Now 3 out of 5 troops (6, 2, and 2) are multiples of 2 that satisfy the requirement.
Input: arr = [3, 5, 6, 7, 9, 10], k = 4
Output: 4
Explanation: We need at least 3 lucky troops since ⌈6 / 2⌉ = 3. Currently, no troop is divisible by 4.
Add 1 soldier for troop 3 → 4,
Add 2 for troop 6 → 8,
Add 1 for troop 7 → 8.
New array: [4, 5, 8, 8, 9, 10] with 3 lucky troops (4, 8, 8).
Total soldiers added = 4.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ k ≤ 105
1 ≤ arr[i] ≤ 105
*/

/*
Approach:
1. For each element in the array, calculate how many soldiers are needed to make it divisible by `k`.
2. Store these differences in a separate array.
3. Sort this array so that the smallest required differences come first.
4. Since we need at least half of the elements (rounded up) to be divisible by `k`, sum up the smallest `req` differences.
5. Return the total soldiers required.

Intuition:
We want at least half of the array elements to be divisible by `k`.  
Instead of trying to directly modify the array, we calculate the *minimum cost* (extra soldiers) required for each element to become divisible by `k`.  
Then, by picking the smallest costs for the required number of elements, we ensure the minimum total soldiers are needed.

Time Complexity:
- Calculating differences: O(n)
- Sorting differences: O(n log n)
- Summing smallest `req` values: O(req) ≈ O(n)
Overall: O(n log n)

Space Complexity:
- O(n) for storing differences array.
*/

class Solution {
  public:
    // Helper function to calculate soldiers needed to make 'x' divisible by 'k'
    int takeDiff(int x, int k) {
        if (x % k == 0) {
            return 0; // Already divisible, no soldiers needed
        }
        return k - (x % k); // Extra soldiers needed to reach next multiple of k
    }
    
    // Main function to find minimum soldiers needed
    int minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int req = (n + 1) / 2; // Minimum number of elements to be divisible by k
        vector<int> diffs;
    
        // Step 1: Calculate soldiers needed for each element
        for (int i = 0; i < n; i++) {
            diffs.push_back(takeDiff(arr[i], k));
        }
    
        // Step 2: Sort differences to pick smallest costs first
        sort(diffs.begin(), diffs.end());
    
        // Step 3: Sum up smallest 'req' differences
        int sum = 0;
        for (int i = 0; i < req; i++) {
            sum += diffs[i];
        }
    
        return sum; // Minimum soldiers needed
    }
};
