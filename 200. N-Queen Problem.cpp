/*
N-Queen Problem
Difficulty: HardAccuracy: 35.43%Submissions: 78K+Points: 8
The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].



Examples:

Input: 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.
Input: 4
Output: [[2 4 1 3 ],[3 1 4 2 ]]
Explaination: These are the 2 possible solutions.
Expected Time Complexity: O(n!)
Expected Auxiliary Space: O(n2) 

Constraints:
1 ≤ n ≤ 10
*/

/*
**Intuition:**
The N-Queens problem involves placing N queens on an N×N chessboard such that no two queens threaten each other. This means no two queens can be in the same row, column, or diagonal.

**Approach:**
1. **Backtracking:** 
   - We use a backtracking approach to try placing queens column by column.
   - For each column, we check each row to see if placing a queen there is safe.
   - If it’s safe, we place the queen and move to the next column.
   - If placing the queen leads to a solution, we save the board configuration.
   - If not, we backtrack by removing the queen and trying the next possible row.

2. **Safety Check:** 
   - We maintain arrays to keep track of whether a queen can be placed in a specific row, upper diagonal, or lower diagonal:
     - `leftRow`: Tracks if a row is occupied.
     - `upperDiagonal`: Tracks the diagonals from the upper left to the lower right.
     - `lowerDiagonal`: Tracks the diagonals from the lower left to the upper right.

**Time Complexity:** O(N!), where N is the number of queens.
**Space Complexity:** O(N^2) due to the board and auxiliary arrays used for backtracking.
*/

class Solution {
public:
    void solve(int col, vector<int> &ansRow, vector<string> &board, vector<vector<int>> &ans, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n) {
        if (col == n) {
            ans.push_back(ansRow);  // Collect the current configuration
            return;
        }

        for (int row = 0; row < n; row++) {
            // Check if placing a queen at board[row][col] is safe
            if (leftRow[row] == 0 && upperDiagonal[n - 1 + col - row] == 0 && lowerDiagonal[row + col] == 0) {
                board[row][col] = 'Q';
                ansRow[col] = row + 1;  // Store the row index (1-based) in ansRow at position `col`
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                solve(col + 1, ansRow, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> ansRow(n, 0);  // To store the row position of queens
        vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
        solve(0, ansRow, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
        return ans;
    }
};

// Example usage:
int main() {
    Solution sol;
    int n = 4;  // Example: Solving 4-Queens problem
    vector<vector<int>> solutions = sol.nQueen(n);

    // Expected Output: A list of solutions where each solution is a vector containing the row positions of queens in each column.
    for (auto &solution : solutions) {
        for (int pos : solution) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
