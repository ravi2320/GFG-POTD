/*
Row with minimum number of 1's
EasyAccuracy: 25.0%Submissions: 43K+Points: 2
Fast-Track your resumes to top tech companies and get the job you deserve! Register for Job-A-Thon Hiring Challenge  

banner
Given a 2D binary matrix(1-based indexed) a of dimensions nxm , determine the row that contains the minimum number of 1's.
Note: The matrix contains only 1's and 0's. Also, if two or more rows contain the minimum number of 1's, the answer is the lowest of those indices.

Example 1:

Input:
n = 4,m = 4
a = [[1, 1, 1, 1],
     [1, 1, 0, 0], 
     [0, 0, 1, 1],
     [1, 1, 1, 1]]
Output:
2
Explanation:
Rows 2 and 3 contain the minimum number 
of 1's(2 each).Since,row 2 is less than row 3.
Thus, the answer is 2.
Example 2:

Input:
n = 3,m = 3
a = [[0, 0, 0],
     [0, 0, 0],
     [0, 0, 0]]
Output:
1
Explanation:
All the rows contain the same number 
of 1's(0 each).Among them, index 1 
is the smallest, so the answer is 1.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minRow() which takes the two integers n, m as well as the 2D binary matrix a as input parameters and returns the minimum index of the row which contains the least number of 1's.

Expected Time Complexity:O(n*m)
Expected Auxillary Space:O(1)

Constraints:
1 <= n,m <= 1000

0 <= a[i][j] <= 1
*/

// Intuition:
// This class provides a solution to find the row with the minimum number of non-zero elements in a given matrix.
// It iterates through each row of the matrix and counts the number of non-zero elements.
// The row with the minimum count of non-zero elements is considered as the answer.

// Time Complexity: O(n * m)
// - 'n' is the number of rows and 'm' is the number of columns in the matrix.
// - The algorithm iterates through each element of the matrix once, which takes O(n * m) time.

// Space Complexity: O(1)
// - The algorithm uses only a constant amount of extra space for variables.

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int min = INT_MAX, ans = 1; // Initialize variables to store minimum count and corresponding row number
        
        // Iterate through each row of the matrix
        for (int i = 0; i < n; i++) {
            int cnt = 0; // Initialize counter for non-zero elements in the current row
            
            // Count the number of non-zero elements in the current row
            for (int j = 0; j < m; j++) {
                if (a[i][j] != 0)
                    cnt++;
            }
            
            // Update minimum count and corresponding row number if the current row has fewer non-zero elements
            if (min > cnt) {
                min = cnt;
                ans = i + 1;
            }
        }
        
        return ans; // Return the row number with the minimum count of non-zero elements
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    int n = 3, m = 4;
    vector<vector<int>> matrix = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 0, 1, 1}};
    cout << "Row with minimum non-zero elements: " << obj.minRow(n, m, matrix) << endl; // Output: 2
    return 0;
}
