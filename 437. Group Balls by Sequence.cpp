/*
Group Balls by Sequence
Difficulty: MediumAccuracy: 41.62%Submissions: 9K+Points: 4
You are given an array arr[] of positive integers, where each element arr[i] represents the number written on the i-th ball, and a positive integer k.
Your task is to determine whether it is possible to rearrange all the balls into groups such that:


Each group contains exactly k balls.
The numbers in each group are consecutive integers
Examples:

Input: arr[] = [10, 1, 2, 11], k = 2
Output: true
Explanation: The hand can be rearranged as [1, 2], [10, 11]. There are two groups of size 2. Each group has 2 consecutive cards.
Input: arr[] = [7, 8, 9, 10, 11], k = 2
Output: false
Explanation: The hand cannot be rearranged into groups of 2, since there are 5 cards, and 5 cards cannot be divided into groups of 2.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 105
1 ≤ k ≤ 103
*/

/*
Approach:
We are given an array `arr` and an integer `k`. The task is to determine whether the array can be divided into groups of size `k`,
where each group consists of `k` consecutive integers.

Steps:
1. Check if the total number of elements `n` is divisible by `k`. If not, return false immediately.
2. Count the frequency of each element using a map.
3. Iterate through the map in sorted order (since `map` keeps keys sorted):
   - For each element `num` with positive frequency `count`, try to form a group starting at `num`.
   - Ensure that the next `k - 1` consecutive elements exist in sufficient quantity.
   - Subtract `count` from those frequencies to mark them as used.

Intuition:
If you can keep forming consecutive sequences of length `k` starting from the smallest unused number,
and never run out of required elements, then grouping is possible.

Time Complexity: O(n log n)
- Inserting `n` elements into `map`: O(n log n)
- Iterating and updating up to `n` times in the map: O(n log n) worst-case

Space Complexity: O(n)
- For the frequency map
*/

class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        int n = arr.size();
        if (n % k != 0) return false;  // Cannot divide into k-sized groups

        map<int, int> freq;  // Frequency map (sorted by key)
        for (int num : arr) {
            freq[num]++;
        }

        // Try forming groups from the smallest number upward
        for (auto &itr : freq) {
            int num = itr.first;
            int count = itr.second;

            // If we have occurrences of this number
            if (count > 0) {
                // Check the next k-1 consecutive numbers
                for (int i = 1; i < k; ++i) {
                    if (freq[num + i] < count) {
                        return false;  // Not enough elements to form a group
                    }
                    freq[num + i] -= count;  // Use those elements
                }
            }
        }

        return true;  // All groups formed successfully
    }
};