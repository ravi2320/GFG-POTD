/*
Maximum sum Rectangle
Difficulty: HardAccuracy: 49.78%Submissions: 47K+Points: 8
Given a 2D matrix mat[][] with dimensions n×m. Find the maximum possible sum of any submatrix within the given matrix.

Examples:

Input: mat[][] = [[1, 2, -1, -4, -20], [-8, -3, 4, 2, 1], [3, 8, 10, 1, 3], [-4, -1, 1, 7, -6]]
Output: 29
Explanation: The matrix is as follows and the green rectangle denotes the maximum sum rectangle which is equal to 29.

Input: mat[][] = [[-1, -2], [-3, -4]]
Output: -1
Explanation: Taking only the first cell is the optimal choice.
Constraints:
1 ≤ n, m ≤ 300
-1000 ≤ mat[i][j] ≤ 1000
*/

/*
Approach:
We use an extension of Kadane’s algorithm to solve the 2D maximum subarray sum problem.
We fix the left and right column boundaries (cStart and cEnd), and for every such pair,
we reduce the 2D matrix to a 1D array of row sums between those columns.
Then we apply Kadane’s algorithm on this 1D array to find the max sum for that column range.
We repeat this for every possible pair of columns and keep track of the global maximum.

Intuition:
In a 1D array, Kadane’s algorithm helps find the maximum subarray sum in linear time.
In a 2D matrix, we can use the same idea by compressing a submatrix into a 1D array using row sums.
By iterating over all pairs of columns, we ensure that every possible rectangle is considered.

Time Complexity: O(C² * R)
- Outer two loops fix the column boundaries: O(C²)
- Inner loop computes row-wise sum and Kadane’s algorithm: O(R)
- Total: O(C² * R)

Space Complexity: O(R)
- We use an auxiliary array of size R to store row sums.
*/

class Solution {
public:
    // Helper function to compute the max subarray sum using Kadane's algorithm
    int kadans(vector<int> &arr){
        int res = INT_MIN;  // Stores max sum found so far
        int sum = 0;        // Running sum

        for(int &x : arr){
            sum += x;

            // Update result if current sum is greater
            res = max(res, sum);

            // Reset sum if it becomes negative
            if(sum < 0){
                sum = 0;
            }
        }

        return res;
    }

    // Function to find the maximum sum rectangle in a 2D matrix
    int maxRectSum(vector<vector<int>> &mat) {
        int R = mat.size();     // Number of rows
        int C = mat[0].size();  // Number of columns
        int maxSum = INT_MIN;   // To store the final result

        // Fix the starting column
        for(int cStart = 0; cStart < C; cStart++){

            // Initialize row-wise sum array
            vector<int> sum(R, 0);

            // Fix the ending column
            for(int cEnd = cStart; cEnd < C; cEnd++){
                // Add values of current column to each row's sum
                for(int row = 0; row < R; row++){
                    sum[row] += mat[row][cEnd];
                }

                // Apply Kadane's algorithm on updated row sum array
                int currMaxSum = kadans(sum);

                // Update maxSum if current rectangle sum is greater
                maxSum = max(maxSum, currMaxSum);
            }
        }

        return maxSum;  // Return the maximum sum of any subrectangle
    }
};