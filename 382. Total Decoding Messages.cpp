/*
Total Decoding Messages
Difficulty: MediumAccuracy: 15.79%Submissions: 143K+Points: 4Average Time: 20m
A message containing letters A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

You are given a string digits. You have to determine the total number of ways that message can be decoded.

Examples:

Input: digits = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(1, 2, 3), "LC"(12, 3) and "AW"(1, 23).
Input: digits = "90"
Output: 0
Explanation: "90" cannot be decoded, as it's an invalid string and we cannot decode '0'.
Input: digits = "05"
Output: 0
Explanation: "05" cannot be mapped to "E" because of the leading zero ("5" is different from "05"), the string is not a valid encoding message.
Constraints:
1 ≤ digits.size() ≤ 103
*/

 // Approach: This problem is about counting the number of ways to decode a given string of digits into letters. 
// It is similar to the "decode ways" problem where each digit can correspond to a letter, and the two-digit numbers can represent letters '10' to '26'.
// We use a recursive approach with memoization to optimize the solution, where we calculate the number of ways from the current index onward, 
// considering both one-digit and two-digit numbers. If the current digit is '0', it's an invalid decoding, so we return 0. 
// We use dynamic programming to store the results for previously computed subproblems to avoid recomputation.

// Intuition: We break the problem down recursively, checking each valid one-digit or two-digit number and moving forward in the string. 
// The recursive calls compute the number of decodings from the current index, and we memoize the results in the dp array for efficient computation.

// Time Complexity: O(n), where n is the length of the input string 'digits'. Each subproblem is solved once, and the solution is cached in the dp array.
// Space Complexity: O(n), for storing the dp array and recursive call stack.

class Solution {
  public:
    // Function to recursively count the number of decoding ways from the given index
    int solve(int idx, string &digits, int n, vector<int> &dp){
        // Base case: if we reach the end of the string, there's one way (the empty string)
        if(idx == n){
            return 1;
        }
        
        // If the current digit is '0', it cannot be decoded, return 0
        if(digits[idx] == '0'){
            return 0;
        }
        
        // Return the result if already computed
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        // Count the ways by taking one digit at a time
        int one = solve(idx+1, digits, n, dp);
        
        // Count the ways by taking two digits (if valid)
        int two = 0;
        if(idx != n-1 && (digits[idx] == '1' || (digits[idx] == '2' && digits[idx+1] <= '6')))
            two = solve(idx+2, digits, n, dp);
        
        // Store the result in dp array and return
        return dp[idx] = one + two;
    }

    // Main function to initiate the decoding process
    int countWays(string &digits) {
        int n = digits.size();
        vector<int> dp(n, -1);  // dp array to store results for subproblems
        return solve(0, digits, n, dp);  // Start from index 0
    }
};


// Approach: This is a bottom-up dynamic programming approach to count the number of ways to decode a digit string.
// Starting from the end of the string, we fill a dp array where dp[i] represents the number of ways to decode the substring starting at index i.
// If the digit at index i is '0', it cannot be decoded, so dp[i] remains 0. 
// For valid digits, we check:
// 1. Taking one digit at a time: Add dp[i+1].
// 2. Taking two digits together if they form a valid number between 10 to 26: Add dp[i+2].

// Intuition: Instead of recursion, we iteratively build the solution from the back, as the number of ways to decode the string starting at index i depends only on dp[i+1] and dp[i+2].

// Time Complexity: O(n), where n is the length of the input string 'digits'.
// Space Complexity: O(n), used for the dp array.

class Solution {
  public:
    int countWays(string &digits) {
        int n = digits.size();
        vector<int> dp(n+1, 0);  // dp[i] stores number of ways to decode from index i to end
        dp[n] = 1;  // Base case: empty string has 1 valid decoding
        
        // Iterate from the end of the string to the beginning
        for(int i = n-1; i >= 0; i--) {
            // If current digit is '0', no valid decoding, dp[i] remains 0
            if(digits[i] == '0') {
                continue;
            }
            
            // One digit decoding
            int one = dp[i+1];
            
            // Two digit decoding if valid (between 10 and 26)
            int two = 0;
            if(i != n-1 && (digits[i] == '1' || (digits[i] == '2' && digits[i+1] <= '6'))) {
                two = dp[i+2];
            }
            
            // Total ways for index i
            dp[i] = one + two;
        }
        
        return dp[0];  // Result stored at dp[0] (start of the string)
    }
};


// Approach: This is a space-optimized dynamic programming solution for counting the number of ways to decode the digit string.
// Instead of using a dp array of size O(n), we reduce the space complexity to O(1) by using three variables: `curr`, `next`, and `secNext`.
// We iterate from the end of the string towards the start. 
// At each index:
// 1. If the digit is '0', no decoding is possible, so curr = 0.
// 2. Else, we check:
//    a. One-digit decoding: Use `next`.
//    b. Two-digit decoding: If valid (between 10 to 26), use `secNext`.
// After calculation, we update `secNext` and `next` for the next iteration.

// Intuition: The number of decoding ways at index i depends only on dp[i+1] and dp[i+2], so instead of keeping the whole array, 
// we maintain just the last two values (like Fibonacci sequence optimization).

// Time Complexity: O(n), where n is the length of the input string 'digits'.
// Space Complexity: O(1), as only constant space is used.

class Solution {
  public:
    int countWays(string &digits) {
        int n = digits.size();
        int curr = 0, next = 0, secNext = 0;  // Initialize variables for dp[i], dp[i+1], dp[i+2]
        
        // Traverse from the end towards the start
        for(int i = n-1; i >= 0; i--) {
            if(digits[i] == '0') {
                // If current digit is '0', no valid decoding
                curr = 0;
            }
            else {
                // One digit decoding
                int one = (i+1 == n) ? 1 : next;
                
                // Two digit decoding if valid
                int two = 0;
                if(i != n-1 && (digits[i] == '1' || (digits[i] == '2' && digits[i+1] <= '6'))) {
                    two = (i+2 == n) ? 1 : secNext;
                }
                
                // Total ways from current index
                curr = one + two;
            }
            
            // Update for next iteration
            secNext = next;
            next = curr;
        }
        
        return curr;  // Result is stored in curr (dp[0])
    }
};