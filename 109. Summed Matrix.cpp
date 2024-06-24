/*
Summed Matrix
Difficulty: EasyAccuracy: 46.76%Submissions: 26K+Points: 2
A matrix is constructed of size n*n and given an integer ‘q’. The value at every cell of the matrix is given as, M(i,j) = i+j, where ‘M(i,j)' is the value of a cell, ‘i’ is the row number, and ‘j’ is the column number. Return the number of cells having value ‘q’.

Note: Assume, the array is in 1-based indexing.

Examples:

Input: n = 4, q = 7
Output: 2
Explanation: Matrix becomes
2 3 4 5 
3 4 5 6 
4 5 6 7
5 6 7 8
The count of 7 is 2.
Input: n = 5, q = 4
Output: 3
Explanation: Matrix becomes
2 3 4 5 6 
3 4 5 6 7 
4 5 6 7 8 
5 6 7 8 9 
6 7 8 9 10 
The count of 4 is 3.
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n,q ≤ 1018
*/

/*
Intuition:
- Given a matrix with size `n x n` where the element at (i, j) is the sum of `i + j`.
- We need to find the sum of all elements in the matrix that are equal to `q`.

Time Complexity:
- O(1): The solution uses a constant number of operations regardless of the input size.

Space Complexity:
- O(1): The solution uses a constant amount of space regardless of the input size.
*/

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // If q is outside the range of possible sums in the matrix
        if (q > 2 * n || q < 2) {
            return 0;
        } 
        // If q is within the range where q <= n
        else if (n >= q) {
            return q - 1;
        }

        // If q is within the range where q > n
        long long diff = q - n;
        return n - (diff - 1);
    }
};
