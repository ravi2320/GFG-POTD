/*
The Palindrome Pattern
Difficulty: HardAccuracy: 55.18%Submissions: 13K+Points: 8
Given a two-dimensional integer array arr of dimensions n x n, consisting solely of zeros and ones, identify the row or column (using 0-based indexing) where all elements form a palindrome. If multiple palindromes are identified, prioritize the palindromes found in rows over those in columns. Within rows or columns, the palindrome with the smaller index takes precedence. The result should be represented by the index followed by either 'R' or 'C', indicating whether the palindrome was located in a row or column. The output should be space-separated. If no palindrome is found, return the string -1.

Examples:

Input: 
arr[][] =  [[1, 0, 0], 
           [0, 1, 0],
           [1, 1, 0]]
Output: 1 R
Explanation: In the first test case, 0-1-0 is a palindrome 
occuring in a row having index 1.
Input: 
arr[][] =   [[1, 0],
           [1, 0]]
Output: 0 C
Explanation: 1-1 occurs before 0-0 in the 0th column. And there is no palindrome in the two rows.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
1<= arr.size <= 50
0 <= arr[i][j] <= 1


*/

/**
 * Intuition:
 * - The goal is to find the first row or column in a 2D array that is a palindrome.
 * - A palindrome is a sequence that reads the same backward as forward.
 * - To achieve this, we need to check each row and each column to see if they are palindromes.
 * - Return the index and type (row or column) of the first palindrome found. If no palindrome is found, return "-1".

 * Time Complexity: O(n^2)
 * - Checking if a row is a palindrome takes O(n) time.
 * - Checking if a column is a palindrome also takes O(n) time.
 * - Since we may need to check all rows and columns, the total time complexity is O(n^2), where n is the dimension of the matrix.

 * Space Complexity: O(1)
 * - The space complexity is constant because we only use a few extra variables for index tracking and comparisons.

 * @param arr: a 2D vector representing the matrix
 * @return: a string representing the index and type (row or column) of the first palindrome found, or "-1" if none is found
 */

class Solution {
  public:
    bool isPalindromeRow(vector<vector<int>> &arr, int row, int n) {
        int start = 0, end = n - 1;
        while (start < end) {
            if (arr[row][start] != arr[row][end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    bool isPalindromeCol(vector<vector<int>> &arr, int col, int n) {
        int start = 0, end = n - 1;
        while (start < end) {
            if (arr[start][col] != arr[end][col])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    string pattern(vector<vector<int>> &arr) {
        int n = arr.size();
        
        // Check rows for palindromes
        for (int i = 0; i < n; i++) {
            if (isPalindromeRow(arr, i, n))
                return to_string(i) + " R";
        }
        
        // Check columns for palindromes
        for (int i = 0; i < n; i++) {
            if (isPalindromeCol(arr, i, n))
                return to_string(i) + " C";
        }
        
        return "-1";
    }
};
