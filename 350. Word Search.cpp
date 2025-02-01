/*
Word Search
Difficulty: MediumAccuracy: 32.69%Submissions: 65K+Points: 4
You are given a two-dimensional mat[][] of size n*m containing English alphabets and a string word. Check if the word exists on the mat. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.

Examples :

Input: mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
Output: true
Explanation:

The letter cells which are used to construct the "GEEK" are colored.
Input: mat[][] = [['T', 'E', 'U'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
Output: false
Explanation:

It is impossible to construct the string word from the mat using each cell only once.
Input: mat[][] = [['A', 'B', 'A'], ['B', 'A', 'B']], word = "AB"
Output: true
Explanation:

There are multiple ways to construct the word "AB".
Constraints:
1 ≤ n, m ≤ 6
1 ≤ L ≤ 15
mat and word consists of only lowercase and uppercase English letters.
*/

/*
Approach:
1. The problem is essentially about **depth-first search (DFS)** to find if a word exists in a grid.
2. Start at each cell of the grid and attempt to form the word by exploring adjacent cells (up, down, left, right).
3. For each cell, mark it temporarily as visited by replacing it with a special character (`#`).
4. If we find a match for the word, return true.
5. After exploring all directions from a cell, backtrack by resetting the cell to its original value.
6. If no valid path is found after all possible starting points, return false.

Intuition:
- The key idea is **backtracking**, where we try each path until we either complete the word or hit a dead-end.

Time Complexity:
- **O(N * M * 4^L)** where N is the number of rows, M is the number of columns, and L is the length of the word. In the worst case, we explore all possible directions for each cell in the grid.

Space Complexity:
- **O(N * M)** due to the recursion stack.
*/

class Solution {
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Directions: down, up, right, left
    int n, m; // Grid dimensions

  public:
    // Helper function to perform DFS
    bool solve(int i, int j, int idx, string &word, vector<vector<char>> &mat) {
        // If we've reached the end of the word, return true
        if (idx == word.size()) {
            return true;
        }

        // Temporarily mark the current cell as visited
        char temp = mat[i][j];
        mat[i][j] = '#';

        // Explore in all four directions
        for (auto &dir : directions) {
            int i_ = i + dir[0], j_ = j + dir[1];
            
            // Check if the new position is within bounds and matches the next character in the word
            if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m) {
                if (mat[i_][j_] == word[idx]) {
                    if (solve(i_, j_, idx + 1, word, mat)) {
                        return true;
                    }
                }
            }
        }

        // Backtrack: reset the cell to its original character
        mat[i][j] = temp;
        return false;
    }

    // Main function to check if the word exists in the grid
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        n = mat.size(), m = mat[0].size();
        
        // Try starting from each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) { // Match the first character
                    if (solve(i, j, 1, word, mat)) { // Try to form the word
                        return true;
                    }
                }
            }
        }

        return false; // No valid path found
    }
};
