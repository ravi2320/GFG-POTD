/*
Number of NGEs to the right
Difficulty: MediumAccuracy: 56.74%Submissions: 25K+Points: 4
Given an array of N integers and Q queries of indices. Return a list NGEs[] where NGEs[i] stores the count of elements strictly greater than the current element (arr[indices[i]]) to the right of indices[i].


Examples :

Input:  arr[]     = [3, 4, 2, 7, 5, 8, 10, 6]
        queries = 2
        indices[] = [0, 5]
Output:  6, 1
Explanation: The next greater elements to the right of 3(index 0) are 4,7,5,8,10,6. The next greater elements to the right of 8(index 5) is only 10.

Input:  arr[]     = [1, 2, 3, 4, 1]
        queries = 2
        indices[] = [0, 3]
Output:  3, 0
Explanation: The count of numbers to the right of index 0 which are greater than arr[0] is 3 i.e. (2, 3, 4). Similarly, the count of numbers to the right of index 3 which are greater than arr[3] is 0, since there are no greater elements than 4 to the right of the array.

Expected Time Complexity: O(N * queries).
Expected Auxiliary Space: O(queries).


Constraints:
1 <= N <= 104
1 <= arr[i] <= 105
1 <= queries <= 100

0 <= indices[i] <= N - 1
*/

/*
Approach:
1. The task is to count the number of elements greater than `arr[idx]` for each index specified in `indices`.
2. For each query, iterate over the elements to the right of the given index and count how many are greater.
3. The result for each query should be stored and returned in a vector.

Steps:
1. Initialize a result vector `res` to store the counts of Next Greater Elements (NGE) for each query.
2. Iterate over each index in the `indices` vector:
   - For each index `idx`, initialize a counter `cnt` to 0.
   - Traverse the `arr` from `idx + 1` to the end, counting elements greater than `arr[idx]`.
   - Store the count in the result vector.
3. Return the result vector.

Time Complexity:
- O(q * n), where `q` is the number of queries and `n` is the size of the array.
  - For each query, a linear scan of the remaining elements is performed.

Space Complexity:
- O(q), for storing the result vector with counts for each query.

*/

class Solution {
public:
    // Function to count the number of elements greater than arr[idx] for each query index
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        vector<int> res;  // Result vector to store the count of NGEs for each query

        // Iterate over each index specified in the indices vector
        for (int &idx : indices) {
            int cnt = 0;  // Counter to track the number of NGEs for current index

            // Traverse elements to the right of the given index to find NGEs
            for (int i = idx + 1; i < n; i++) {
                if (arr[i] > arr[idx]) {
                    cnt++;
                }
            }

            // Store the count of NGEs in the result vector
            res.push_back(cnt);
        }

        // Return the result vector
        return res;
    }
};
