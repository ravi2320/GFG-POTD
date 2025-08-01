/*
Balancing Consonants and Vowels Ratio
Difficulty: MediumAccuracy: 66.06%Submissions: 4K+Points: 4
You are given an array of strings arr[], where each arr[i] consists of lowercase english alphabets. You need to find the number of balanced strings in arr[] which can be formed by concatinating one or more contiguous strings of arr[].
A balanced string contains the equal number of vowels and consonants. 

Examples:

Input: arr[] = ["aeio", "aa", "bc", "ot", "cdbd"]
Output: 4
Explanation: arr[0..4], arr[1..2], arr[1..3], arr[3..3] are the balanced substrings with equal consonants and vowels.
Input: arr[] = ["ab", "be"]
Output: 3
Explanation: arr[0..0], arr[0..1], arr[1..1] are the balanced substrings with equal consonants and vowels.
Input: arr[] = ["tz", "gfg", "ae"]
Output: 0
Explanation: There is no such balanced substring present in arr[] with equal consonants and vowels.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i].size() ≤ 105
Total number of lowercase english characters in arr[] is lesser than 105.
*/

// ✅ Approach:
// 1. Use a prefix sum-style approach where we keep a running count `val`:
//    - Increment `val` by 1 for vowels, decrement by 1 for consonants.
// 2. Use a hash map `mp` to count how often each `val` has occurred so far.
//    - Initialize `mp[0] = 1` to count empty prefix as a balanced state.
// 3. For each string in the array:
//    - Traverse each character and update `val`.
//    - If the current `val` has been seen before, it means the subarray (between same values of `val`) is balanced.
//    - Add the count of that `val` to `ans` and update its frequency in map.
// 4. Finally, return the total number of balanced subarrays.

// ✅ Intuition:
// A subarray is balanced when the number of vowels equals the number of consonants.
// So, we can track the net count (`val`) where +1 means vowel and -1 means consonant.
// If the same `val` has appeared before, then the segment between them is balanced.

// ✅ Time Complexity: O(N * L)
// Where N = number of strings, L = average length of a string.
// ✅ Space Complexity: O(N)
// For storing `val` frequencies in the hash map.

class Solution {
public:
    int countBalanced(vector<string>& arr) {
        int val = 0;                     // Running vowel - consonant balance
        int ans = 0;                     // Final answer
        unordered_map<int, int> mp;      // Map to track how many times a `val` has occurred
        mp[0] = 1;                       // Initialize for balanced prefix

        for (string &str : arr) {
            for (char &x : str) {
                // Increase val for vowel, decrease for consonant
                if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                    val++;
                } else {
                    val--;
                }
            }

            // If same balance value was seen before, it contributes to balanced substrings
            if (mp.find(val) != mp.end()) {
                ans += mp[val];
            }

            // Update frequency of current balance value
            mp[val]++;
        }

        return ans; // Total balanced segments
    }
};
