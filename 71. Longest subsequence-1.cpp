/*
Longest subsequence-1
MediumAccuracy: 39.79%Submissions: 61K+Points: 4
In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

banner
Given an integer array a[] of size n, find the length of the longest subsequence such that the absolute difference between adjacent elements is 1.

Example 1:

Input:
n = 7
a[] = {10, 9, 4, 5, 4, 8, 6}
Output: 
3
Explaination: 
The three possible subsequences of length 3 are {10, 9, 8}, {4, 5, 4}, and {4, 5, 6}, where adjacent elements have a absolute difference of 1. No valid subsequence of greater length could be formed.
Example 2:

Input: 
n = 5
a[] = {1, 2, 3, 4, 5}
Output: 
5
Explaination: 
All the elements can be included in the valid subsequence.
Your Task:
You do not need to read input. Your task is to complete the function longestSubseq() which takes integer n and array a[] as input parameters and returns the length of the longest subsequence where the absolute difference of adjacent elements is 1.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 103
1 ≤ a[i] ≤ 103
*/

// Intuition:
// - We need to find the length of the longest subsequence where the absolute difference between any two consecutive elements is 1.
// - We use a hashmap to keep track of the maximum length of subsequences ending at each element.
// - For each element, we check the length of subsequences ending at the previous element (element-1) and the next element (element+1), and update the length for the current element.

// Time Complexity: O(N), where N is the length of the input array.
// - We iterate through the array once and perform constant time operations for each element.

// Space Complexity: O(N)
// - We use a hashmap to store the length of subsequences ending at each element, which in the worst case can store an entry for each element in the array.

class Solution {
public:
    int longestSubseq(int n, vector<int>& a) {
        int ans = 0;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            // Check the longest subsequence length ending at a[i]
            mp[a[i]] = max(mp[a[i] - 1], mp[a[i] + 1]) + 1;
            // Update the global maximum length
            ans = max(ans, mp[a[i]]);
        }
        
        return ans;
    }
};
