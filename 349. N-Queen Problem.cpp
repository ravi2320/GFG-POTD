/*
N-Queen Problem
Difficulty: HardAccuracy: 35.43%Submissions: 99K+Points: 8
The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

Given an integer n, find all distinct solutions to the n-queens puzzle.
You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.
For eg. below figure represents a chessboard [3 1 4 2].



Examples:

Input: n = 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.
Input: n = 4
Output: [[2 4 1 3 ] [3 1 4 2 ]]
Explaination: There are 2 possible solutions for n = 4.
Input: n = 2
Output: []
Explaination: There are no possible solutions for n = 2.
Constraints:
1 ≤ n ≤ 10
*/

/*
Approach:
1. We use **backtracking** to place queens row by row.
2. We maintain a `board` to track placements.
3. We check for **valid placements** using `isSafe()`, ensuring:
   - No queen exists in the same column.
   - No queen exists on the upper-left diagonal.
   - No queen exists on the upper-right diagonal.
4. If a valid placement is found, we **place the queen** and move to the next row.
5. If we reach the last row (`row == n`), we store the solution.
6. We backtrack to explore other possible placements.

Intuition:
- The problem requires placing `N` queens such that no two attack each other.
- By **checking constraints before placing**, we avoid invalid configurations early.
- Backtracking helps explore all valid configurations efficiently.

Time Complexity:
- \(O(N!)\) because there are \(N!\) possible placements in the worst case.

Space Complexity:
- \(O(N^2)\) for storing the board (can be optimized to \(O(N)\) using arrays).
*/

class Solution {
  public:
    // Function to check if placing a queen at (row, col) is safe.
    bool isSafe(int row, int col, vector<string> &board, int n) {
        // Check previous rows in the same column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // Check upper-left diagonal
        int r = row, c = col;
        while (r >= 0 && c >= 0) {
            if (board[r--][c--] == 'Q') return false;
        }
        
        // Check upper-right diagonal
        r = row, c = col;
        while (r >= 0 && c < n) {
            if (board[r--][c++] == 'Q') return false;
        }
        
        return true; // Position is safe for the queen
    }
    
    // Recursive function to solve N-Queens using backtracking
    void solve(int row, vector<string> &board, vector<vector<int>> &ans, vector<int> &tempAns, int n) {
        // Base case: If all queens are placed
        if (row == n) {
            ans.push_back(tempAns);
            return;
        }
        
        // Try placing a queen in every column of the current row
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, board, n)) {
                // Place the queen
                board[row][col] = 'Q';
                tempAns.push_back(col + 1); // Store 1-based index
                
                // Recur for the next row
                solve(row + 1, board, ans, tempAns, n);
                
                // Backtrack: Remove queen and try the next column
                board[row][col] = '.';
                tempAns.pop_back();
            }
        }
    }
    
    // Function to return all distinct solutions to the N-Queens problem.
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;      // Store all solutions
        vector<string> board(n, string(n, '.')); // N x N board initialized with '.'
        vector<int> tempAns;          // Temporary storage for one solution
        
        solve(0, board, ans, tempAns, n); // Start solving from row 0
        
        return ans;
    }
};


/*
Approach:
1. We use **backtracking** to place queens row by row.
2. Instead of checking the board for safe positions, we use **three hash arrays**:
   - `leftCol`: Tracks occupied columns.
   - `lowerDiag`: Tracks occupied diagonals from **bottom-left to top-right**.
   - `upperDiag`: Tracks occupied diagonals from **top-left to bottom-right**.
3. If a position `(row, col)` is safe, we place a queen and proceed to the next row.
4. If we reach row `n`, we store the valid arrangement.
5. We backtrack by removing the queen and trying another position.

Intuition:
- Using hash arrays reduces the **time complexity of safety checks** from \(O(N)\) to \(O(1)\).
- This **significantly speeds up** the backtracking process.

Time Complexity:
- **\(O(N!)\)** (worst-case: exploring all possibilities).

Space Complexity:
- **\(O(N)\)** (extra arrays for safety checks instead of an `N×N` board).
*/

class Solution {
  public:
    
    // Recursive function to solve N-Queens using backtracking
    void solve(int row, vector<string> &board, vector<vector<int>> &ans, vector<int> &tempAns, 
               int n, vector<int> &upperDiag, vector<int> &lowerDiag, vector<int> &leftCol) {
        
        // Base case: If all queens are placed, store the solution
        if (row == n) {
            ans.push_back(tempAns);
            return;
        }
        
        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            // Check if position (row, col) is safe
            if (leftCol[col] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + row - col] == 0) {
                
                // Place the queen
                board[row][col] = 'Q';
                leftCol[col] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + row - col] = 1;
                tempAns.push_back(col + 1); // Store 1-based index
                
                // Recur to place queen in the next row
                solve(row + 1, board, ans, tempAns, n, upperDiag, lowerDiag, leftCol);
                
                // Backtrack: Remove queen and reset hash arrays
                board[row][col] = '.';
                leftCol[col] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + row - col] = 0;
                tempAns.pop_back();
            }
        }
    }
    
    // Function to return all distinct solutions to the N-Queens problem
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;       // Store all solutions
        vector<int> tempAns;           // Temporary storage for one solution
        vector<string> board(n, string(n, '.')); // N x N board initialized with '.'
        
        // Hash arrays to track safe placements
        vector<int> upperDiag(2 * n + 1, 0), lowerDiag(2 * n + 1, 0), leftCol(n, 0);
        
        // Start solving from row 0
        solve(0, board, ans, tempAns, n, upperDiag, lowerDiag, leftCol);
        
        return ans;
    }
};