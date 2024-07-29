/*
Row with max 1s
Difficulty: MediumAccuracy: 33.09%Submissions: 288K+Points: 4
Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

Examples:

Input: arr[][] = [[0, 1, 1, 1],
               [0, 0, 1, 1],
               [1, 1, 1, 1],
               [0, 0, 0, 0]]
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).
Input: arr[][] = [[0, 0], 
               [1, 1]]
Output: 1
Explanation: Row 1 contains 2 1's (0-based indexing).
Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ number of rows, number of columns ≤ 103
0 ≤ arr[i][j] ≤ 1 


*/

/*
Intuition:
The problem is to find the row with the maximum number of 1s in a given binary matrix, where each row is sorted. Since the rows are sorted, once we find a 0 in a row, all subsequent elements to the right will also be 0. This allows us to efficiently navigate through the matrix by starting from the top-right corner and moving left when we find a 1 and down when we find a 0. This way, we can find the row with the most 1s in O(N + M) time, where N is the number of rows and M is the number of columns.

Time Complexity:
The time complexity is O(N + M), where N is the number of rows and M is the number of columns. This is because, in the worst case, we traverse all the rows and columns once.

Space Complexity:
The space complexity is O(1) as we only use a fixed amount of additional space for variables.
*/

class Solution {
public:
    // Function to find the row with the maximum number of 1s
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();    // Number of rows
        int m = arr[0].size(); // Number of columns
        int ans = -1;          // Index of the row with the maximum number of 1s
        
        int i = 0, j = m - 1;  // Start from the top-right corner of the matrix
        
        while(i < n && j >= 0){
            if(arr[i][j] == 1){
                j--;          // Move left if a 1 is found
                ans = i;      // Update the answer to the current row index
            } else {
                i++;          // Move down if a 0 is found
            }
        }
        
        return ans;            // Return the index of the row with the most 1s
    }
};
