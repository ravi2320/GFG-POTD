/*
Max rectangle
Difficulty: HardAccuracy: 36.43%Submissions: 123K+Points: 8Average Time: 35m
You are given a 2D binary matrix mat[ ][ ], where each cell contains either 0 or 1. Your task is to find the maximum area of a rectangle that can be formed using only 1's within the matrix.

Examples:

Input: mat[][] = [[0, 1, 1, 0],
                [1, 1, 1, 1],
                [1, 1, 1, 1],
                [1, 1, 0, 0]]
Output: 8
Explanation: The largest rectangle with only 1’s is from (1, 0) to (2, 3) which is
[1, 1, 1, 1]
[1, 1, 1, 1]
and area is 4 * 2 = 8.
Input: mat[][] = [[0, 1, 1],
                [1, 1, 1],
                [0, 1, 1]]
Output: 6
Explanation: The largest rectangle with only 1’s is from (0, 1) to (2, 2) which is
[1, 1]
[1, 1]
[1, 1]
and area is 2 * 3 = 6.
Constraints:
1 ≤ mat.size(), mat[0].size() ≤1000
0 ≤ mat[][] ≤1
*/

/*
Approach:
1. The problem "maximum rectangle in a binary matrix" can be reduced to solving 
   the "largest rectangle in histogram" problem for each row of the matrix.
   
2. Core idea:
   - Treat each row of the binary matrix as the base of a histogram.
   - If mat[i][j] == 1, then height[j] += 1, else reset height[j] = 0.
   - For each updated histogram row, compute the maximum rectangle area using 
     the largest rectangle in histogram algorithm.

3. Largest Rectangle in Histogram:
   - For each element, compute:
     - Next Smaller Element (NSE) index.
     - Previous Smaller Element (PSE) index.
   - Width of rectangle for index i = NSE[i] - PSE[i] - 1.
   - Area = arr[i] * width.
   - Use stack-based approach to compute NSE and PSE efficiently.

4. Repeat this process row by row and keep track of the global maximum area.

Intuition:
- A row in the binary matrix can be visualized as the "ground level" of a histogram.
- By stacking 1s vertically, each column's height contributes to potential rectangles.
- Largest rectangle in histogram is the key subproblem, which we solve with monotonic stacks.

Time Complexity:
- Finding NSE + PSE for each histogram: O(C) using stacks.
- Processing each row: O(C).
- For R rows: O(R * C).
- Overall: O(R * C).

Space Complexity:
- O(C) for NSE, PSE, and stack.
- Overall: O(C).

*/

class Solution {
public:
    // Function to compute Next Smaller Element indices
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> NSE(n, n);  // default: n (no smaller element to the right)
        stack<int> st;
        
        for(int i = n - 1; i >= 0; i--) {
            // Pop elements >= current since we want strictly smaller
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            NSE[i] = st.empty() ? n : st.top();  
            st.push(i);
        }
        return NSE;
    }

    // Function to compute Previous Smaller Element indices
    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> PSE(n, -1);  // default: -1 (no smaller element to the left)
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            PSE[i] = st.empty() ? -1 : st.top();  
            st.push(i);
        }
        return PSE;
    }
    
    // Function to compute maximum area in histogram
    int getMaxArea(vector<int> &arr) {
        int n = arr.size();
        vector<int> NSE = findNSE(arr);
        vector<int> PSE = findPSE(arr);
        
        int maxArea = 0;
        for(int i=0; i<n; i++){
            int width = NSE[i] - PSE[i] - 1;   // available width for rectangle
            int area = arr[i] * width;         // rectangle area with height arr[i]
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
    
    // Main function to compute maximum rectangle in binary matrix
    int maxArea(vector<vector<int>> &mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<int> arr(cols, 0);  // histogram heights
        int maxi = 0;
    
        for (int i = 0; i < rows; i++) {
            // Update histogram heights row by row
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    arr[j] += 1;  // extend height
                } else {
                    arr[j] = 0;   // reset height
                }
            }
            // Compute largest rectangle for this histogram
            maxi = max(maxi, getMaxArea(arr));
        }
        return maxi;
    }
};
