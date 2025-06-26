/*
Game with String
Difficulty: MediumAccuracy: 53.96%Submissions: 60K+Points: 4Average Time: 15m
Given a string s consisting of lowercase alphabets and an integer k, your task is to find the minimum possible value of the string after removing exactly k characters.

The value of the string is defined as the sum of the squares of the frequencies of each distinct character present in the string.

Examples :

Input: s = "abbccc", k = 2
Output: 6
Explaination: We remove two 'c' to get the value as 12 + 22 + 12 = 6 or We remove one 'b' and one 'c' to get the value 12 + 12 + 22 = 6.
Input: s = "aaab", k = 2
Output: 2
Explaination: We remove two 'a'. Now we get the value as 12 + 12 = 2.
Constraints:
0 ≤ k ≤ s.length() ≤ 105
*/

/*
Approach:
We are given a string `s` and an integer `k`. The goal is to remove `k` characters in such a way that the 
**sum of squares of the frequencies** of the remaining characters is minimized.

Strategy:
1. Count the frequency of each character in the string.
2. Use a **max-heap (priority queue)** to always reduce the highest frequency character (since reducing higher frequencies reduces the square sum more effectively).
3. Perform `k` operations where we reduce the top element of the max-heap by 1.
4. After all `k` operations, compute the sum of squares of the frequencies left in the heap.

Intuition:
To minimize the sum of squares, we must target the characters with the highest frequencies and reduce them first.

Time Complexity:
- O(n + 26*log26 + k*log26 + 26*log26) → O(n + k log 26) → O(n + k), since 26 is constant.
  - n = length of string
  - k operations on max heap (log 26 each)
- Final heap summation is O(26 log 26)

Space Complexity:
- O(26) for frequency array and max-heap → O(1)

Note: Only lowercase English letters (26) are considered.
*/

class Solution {
public:
    int minValue(string &s, int k) {
        // Frequency array for 26 lowercase characters
        vector<int> freq(26, 0);
        for (char &x : s) {
            freq[x - 'a']++;
        }

        // Max heap to store frequencies
        priority_queue<int> pq;
        for (int &f : freq) {
            if (f > 0) pq.push(f);
        }

        // Perform k removals by reducing top frequency
        while (!pq.empty() && k > 0) {
            int top = pq.top(); pq.pop();
            top--;
            k--;
            if (top > 0) pq.push(top);
        }

        // Calculate sum of squares of remaining frequencies
        int sum = 0;
        while (!pq.empty()) {
            int top = pq.top(); pq.pop();
            sum += top * top;
        }

        return sum;
    }
};