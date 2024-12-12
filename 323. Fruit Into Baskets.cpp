/*
Fruit Into Baskets
Difficulty: MediumAccuracy: 47.98%Submissions: 73K+Points: 4
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array of arr[], where arr[i]  is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array of fruits, return the maximum number of fruits you can pick.

Examples:

Input: arr[]= [2, 1, 2]
Output: 3
Explanation: We can pick one fruit from all three trees. Please note that the type of fruits is same in the 1st and 3rd baskets.
Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: It's optimal to pick from the last 5 trees. Please note that we do not pick the first basket as we would have to stop at thrid tree which would result in only 2 fruits collected.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] <=n
*/

/*
Approach:
1. Use the sliding window (two-pointer) technique to maintain a subarray with at most two distinct fruit types.
2. Expand the window by moving the `j` pointer to include elements.
3. If the number of distinct fruit types in the current window exceeds two, shrink the window by moving the `i` pointer until the condition is satisfied.
4. Track the maximum length of the valid subarray.

Steps:
- Initialize pointers `i` and `j` for the sliding window and a hash map `mp` to count the occurrences of each fruit type in the window.
- Traverse the array with the `j` pointer:
  - Add the current fruit to the hash map and increment its count.
  - If the size of the hash map exceeds 2, increment `i` and adjust the count of the fruit at index `i`. Remove it from the map if its count becomes zero.
  - Update `maxLen` with the current window size (`j - i + 1`) if the window is valid.

Time Complexity:
- O(n): Each element is processed at most twice (once by `j` and once by `i`).

Space Complexity:
- O(1): At most, the hash map contains two keys.

Edge Cases:
- All elements are of the same type.
- There are no fruits (empty array).
- Array size is less than or equal to 2.

*/

class Solution {
public:
    int totalFruits(vector<int> &arr) {
        unordered_map<int, int> mp; // Map to store the count of each fruit type
        int maxLen = 0;             // Maximum length of valid subarray
        int i = 0, j = 0;           // Sliding window pointers
        int n = arr.size();         // Size of the array

        // Traverse the array
        while (j < n) {
            // Include arr[j] in the window
            mp[arr[j]]++;

            // If there are more than two types of fruits, shrink the window
            while (mp.size() > 2) {
                mp[arr[i]]--; // Decrease the count of the fruit at index i
                if (mp[arr[i]] == 0) {
                    mp.erase(arr[i]); // Remove the fruit type from the map if count becomes 0
                }
                i++; // Move the left pointer
            }

            // Update the maximum length of the valid window
            maxLen = max(maxLen, j - i + 1);

            // Expand the window
            j++;
        }

        return maxLen;
    }
};
