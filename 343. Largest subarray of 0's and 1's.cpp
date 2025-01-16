/*
Largest subarray of 0's and 1's
Difficulty: EasyAccuracy: 32.96%Submissions: 97K+Points: 2
Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

Examples:

Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
Output: 6
Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.
Input: arr[] = [0, 0, 1, 1, 0]
Output: 4
Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.
Input: arr[] = [0]
Output: 0
Explnation: There is no subarray with an equal number of 0s and 1s.
Constraints:
1 <= arr.size() <= 105
0 <= arr[i] <= 1
*/

/*
Approach:
1. Use a **balance variable** to track the difference between the number of 1s and 0s in the array.
   - Increment the balance by 1 for every `1` in the array.
   - Decrement the balance by 1 for every `0` in the array.
2. Use a hash map to store the first occurrence of each balance value.
   - If the same balance value is encountered again, it indicates that the subarray between the two occurrences has equal numbers of 0s and 1s.
3. Update the maximum length of such a subarray whenever a previously seen balance is encountered.

Intuition:
- The balance concept ensures that whenever a balance repeats, the subarray between the two indices contains an equal number of 1s and 0s.
- Using a hash map helps efficiently track the first occurrence of each balance.

Time Complexity:
- \(O(n)\): The array is traversed once, and hash map operations (insert/find) are \(O(1)\) on average.

Space Complexity:
- \(O(n)\): The hash map stores at most \(n+1\) unique balance values.

Edge Cases:
1. Array with no 0s or 1s.
2. Entire array has equal numbers of 0s and 1s.
3. Empty array.

*/

class Solution {
public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> mp; // Hash map to store the first occurrence of each balance
        int balance = 0;           // Tracks the difference between 1s and 0s
        int res = 0;               // Stores the maximum length of a subarray with equal 0s and 1s

        mp[balance] = -1;          // Initialize for the case where the subarray starts at index 0

        for (int i = 0; i < n; i++) {
            // Update balance: +1 for 1, -1 for 0
            balance += (arr[i] == 1) ? 1 : -1;

            // If the balance is already seen, calculate the length of the subarray
            if (mp.find(balance) != mp.end()) {
                res = max(res, i - mp[balance]);
            } else {
                // Store the first occurrence of the balance
                mp[balance] = i;
            }
        }

        return res; // Return the maximum length
    }
};
