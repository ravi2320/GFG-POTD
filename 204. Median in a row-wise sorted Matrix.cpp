/*
Median in a row-wise sorted Matrix
Difficulty: HardAccuracy: 55.05%Submissions: 115K+Points: 8
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives 
us {1,2,3}. Hence, 2 is median.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)


Constraints:
1 <= R, C <= 400
1 <= matrix[i][j] <= 2000
*/

/*
**Problem Statement:**
- Given a row-wise sorted matrix of size `R x C`, the task is to find the median of the matrix. The matrix is sorted in non-decreasing order both row-wise and column-wise.

**Approach:**
1. **Binary Search on Answer:**
   - The problem can be solved using a binary search on the range of the possible matrix values, which is between the smallest element and the largest element in the matrix.
   - The goal is to determine the smallest value `mid` such that there are at least `(R * C) / 2` elements in the matrix that are less than or equal to `mid`.

2. **Counting Smaller or Equal Elements:**
   - To count how many elements are less than or equal to `mid`, iterate over each row and find the upper bound for `mid` using binary search. The `upperBound` function returns the index of the first element greater than `mid`. The count of elements less than or equal to `mid` in that row is the index returned by `upperBound`.

3. **Binary Search Process:**
   - Initialize `low` as the smallest element in the matrix and `high` as the largest element.
   - Perform binary search on the range `[low, high]` to find the median. For each mid-point, count the number of elements less than or equal to `mid`. Adjust the `low` and `high` pointers based on the count to narrow down the search space.

4. **Time Complexity:**
   - The time complexity is `O(R * log(C) * log(max-min))`, where `R` is the number of rows, `C` is the number of columns, and `max-min` is the range of the elements in the matrix.

5. **Space Complexity:**
   - The space complexity is `O(1)` as we only use a few extra variables.

**Example Usage:**
- Given a 3x3 matrix `[[1, 3, 5], [2, 6, 9], [3, 6, 9]]`, the median is `5`.
*/

class Solution {
public:
    // Function to find the upper bound in a sorted array
    int upperBound(vector<int> &arr, int m, int x) {
        int low = 0, high = m - 1;

        // Perform binary search for upper bound
        while (low <= high) {
            int mid = (low + high) >> 1;

            if (arr[mid] <= x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }

    // Function to count how many elements are <= x in the matrix
    int countSmallEqual(vector<vector<int>> &matrix, int R, int C, int x) {
        int cnt = 0;

        // Count for each row using the upperBound function
        for (int i = 0; i < R; i++) {
            cnt += upperBound(matrix[i], C, x);
        }

        return cnt;
    }

    // Main function to find the median of the matrix
    int median(vector<vector<int>> &matrix, int R, int C) {
        int low = INT_MAX;
        int high = INT_MIN;

        // Find the smallest and largest element in the matrix
        for (int i = 0; i < R; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }

        int req = (R * C) / 2;

        // Binary search to find the median
        while (low <= high) {
            int mid = (low + high) >> 1;
            int smallEqual = countSmallEqual(matrix, R, C, mid);

            if (smallEqual <= req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
