/*
Kth element in Matrix
Difficulty: MediumAccuracy: 61.42%Submissions: 68K+Points: 4Average Time: 35m
Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Examples:
Input: n = 4, mat[][] = [[16, 28, 60, 64], [22, 41, 63, 91], [27, 50, 87, 93], [36, 78, 87, 94]], k = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
Input: n = 4, mat[][] = [[10, 20, 30, 40], [15, 25, 35, 45], [24, 29, 37, 48], [32, 33, 39, 50]], k = 7
Output: 30
Explanation: 30 is the 7th smallest element.
Constraints:
1 <= n <= 500
1 <= mat[i][j] <= 10000
1 <= k <= n*n
*/

/*
Approach:
- Use binary search on the range of values from the smallest to the largest element in the matrix.
- For a mid-value, count how many elements in the matrix are less than or equal to mid.
- If count < k, it means we need larger elements, so shift low = mid + 1.
- If count >= k, it could be a potential answer, so update ans and search in the left half.

Intuition:
- Since each row and column of the matrix is sorted, we can efficiently count how many elements
  are <= a given number using a clever traversal starting from the top-right corner.

Time Complexity: O(N * log(max-min))
- N = matrix size
- Each binary search step takes O(N) time to count elements.

Space Complexity: O(1)
- Only a few variables used, no extra space apart from input.
*/

class Solution {
  public:
    // Function to count elements less than or equal to 'num' in the matrix
    int cntSmallElement(vector<vector<int>> &matrix, int num){
        int cnt = 0;
        int n = matrix.size();
        int r = 0, c = n - 1;

        // Start from top-right and move accordingly
        while(c >= 0 && r < n){
            if(matrix[r][c] <= num){
                cnt += c + 1; // All elements in current row till c are <= num
                r++;          // Move to next row
            }
            else{
                c--;          // Move left in the row
            }
        }

        return cnt;
    }

    // Main function to find kth smallest element
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];             // Smallest element
        int high = matrix[n-1][n-1];        // Largest element
        int ans = -1;

        // Binary search on the value range
        while(low <= high){
            int mid = low + (high - low) / 2;
            int cnt = cntSmallElement(matrix, mid); // Count elements <= mid

            if(cnt < k){
                low = mid + 1;              // kth smallest is larger
            }
            else{
                ans = mid;                  // Mid might be the answer
                high = mid - 1;             // Try to find smaller value
            }
        }

        return ans; // kth smallest element
    }
};
