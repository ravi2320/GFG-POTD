/*
Pairs with difference k
Difficulty: EasyAccuracy: 22.41%Submissions: 30K+Points: 2
Given an array arr[] of positive integers. Find the number of pairs of integers whose difference equals a given number k.
Note: (a, b) and (b, a) are considered the same. Also, the same numbers at different indices are considered different.

Examples:

Input: arr[] = [1, 5, 3, 4, 2], k = 3
Output: 2
Explanation: There are 2 pairs with difference 3,the pairs are {1, 4} and {5, 2} 
Input: arr[] = [8, 12, 16, 4, 0, 20], k = 4
Output: 5
Explanation: There are 5 pairs with difference 4, the pairs are {0, 4}, {4, 8}, {8, 12}, {12, 16} and {16, 20}.
Constraints:
1 <= arr.size() <= 106
1 <= k <= 106
1 <= arri <= 106
*/

/*
Approach:
1. We use an unordered map `mp` to store the frequency of each element in the array.
2. For each element `x` in the array:
   - Check if `x + k` exists in the map.
   - If it does, increment the count by `mp[x + k]`, which represents the number of pairs `(x, x + k)`.
3. This approach ensures we only check each pair once using the map, leading to an efficient solution.

Time Complexity: O(n), where n is the size of the array, as we traverse the array twice (once for populating the map and once for counting).
Space Complexity: O(n), for storing elements in the map.

*/

class Solution {
public:
    // Returns count of pairs with difference k
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        // Populate the map with frequencies of elements
        for (int &x : arr) {
            mp[x]++;
        }

        int ans = 0;

        // For each element, check if `x + k` exists
        for (int &x : arr) {
            if (mp.find(x + k) != mp.end()) {
                ans += mp[x + k]; // Increment count by the frequency of `x + k`
            }
        }

        return ans; // Return the total count of pairs
    }
};