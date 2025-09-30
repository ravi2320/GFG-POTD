/*
Generate all binary strings
Difficulty: MediumAccuracy: 63.9%Submissions: 38K+Points: 4Average Time: 20m
Given an integer n. You need to generate all the binary strings of n characters representing bits.

Note: Return the strings in  ascending order.

Examples:

Input: n = 2
Output: [00, 01, 10, 11]
Explanation: As each position can be either 0 or 1, the total possible combinations are 4.
Input: n = 3
Output: [000, 001, 010, 011, 100, 101, 110, 111]
Explanation: As each position can be either 0 or 1, the total possible combinations are 8.
Constraints:
1 ≤ n ≤ 20
*/

/*
Approach:
1. Start with an n-length string of all '0's and add it to the result.
2. Iteratively, for each bit position from right to left, duplicate all existing strings in the result.
3. In each duplicate, flip the current bit to '1' and append to the result.
4. Continue until all 2^n binary strings are generated.

Intuition:
We are essentially generating all possible binary strings of length n.
The process works like constructing a binary tree of decisions:
- For each position, either keep it '0' or flip it to '1'.
This doubling process ensures all 2^n combinations are covered.

Time Complexity: O(n * 2^n)  
- Each of the 2^n strings has length n, and flipping requires O(n).  
Space Complexity: O(n * 2^n)  
- We store all 2^n binary strings, each of length n.
*/

class Solution {
  public:
    vector<string> binstr(int n) {
        // Initialize base string of n zeroes
        string str = "0000000000000000000000";  // large enough to cover max n
        vector<string> res;
        res.push_back(str.substr(0, n)); // push initial string of size n

        // For each bit position from rightmost to leftmost
        for(int i = 0; i < n; i++) {
            int m = res.size(); // current size of result

            // Duplicate each string in result
            for(int j = 0; j < m; j++) {
                string curr = res[j];          // copy existing string
                curr[n - i - 1] = '1';         // set bit at position (right to left)
                res.push_back(curr);           // add new string to result
            }
        }
        
        return res;
    }
};
