/*
Count the number of possible triangles
Difficulty: MediumAccuracy: 28.53%Submissions: 123K+Points: 4
Given an integer array arr[]. Find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. 

A triangle with three given sides is only possible if sum of any two sides is always greater than the third side.

Examples:

Input: arr[] = [4, 6, 3, 7]
Output: 3
Explanation: There are three triangles possible [3, 4, 6], [4, 6, 7] and [3, 6, 7]. Note that [3, 4, 7] is not a possible triangle.  
Input: arr[] = [10, 21, 22, 100, 101, 200, 300]
Output: 6
Explanation: There can be 6 possible triangles: [10, 21, 22], [21, 100, 101], [22, 100, 101], [10, 100, 101], [100, 101, 200] and [101, 200, 300]
Input: arr[] = [1, 2, 3]
Output: 0
Explanation: No triangles are possible.
Constraints:
3 <= arr.size() <= 103
0 <= arr[i] <= 105
*/

/*
Approach:
1. Sort the array to simplify checking the triangle inequality.
2. Fix the largest side of the triangle (`arr[i]`) by iterating from the end of the sorted array.
3. Use two pointers (`j` and `k`) to find all pairs of numbers from the left of `arr[i]` such that their sum is greater than `arr[i]`.
   - If the sum of `arr[j]` and `arr[k]` is greater than `arr[i]`, it means all pairs between `j` and `k` can form a triangle with `arr[i]`.
   - Increment the count by `(k - j)` and decrement `k`.
   - Otherwise, increment `j` to increase the sum.
4. Return the total count of triangles.

Intuition:
The triangle inequality states that the sum of any two sides of a triangle must be greater than the third side. By sorting the array, we ensure that once two numbers fail this condition, all smaller pairs will also fail, allowing us to use a two-pointer approach for efficiency.

Time Complexity:
1. Sorting the array: \(O(N \log N)\), where \(N\) is the size of the array.
2. Two-pointer search for each fixed largest side: \(O(N^2)\).
Overall: \(O(N^2)\).

Space Complexity:
- \(O(1)\), as no extra space is used apart from variables.

*/

class Solution {
public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        // Sort the array to apply the triangle inequality efficiently.
        sort(arr.begin(), arr.end());
        int ans = 0, n = arr.size();

        // Fix the largest side of the triangle.
        for (int i = n - 1; i >= 2; i--) {
            int j = 0, k = i - 1;

            // Two-pointer approach to find pairs that satisfy the condition.
            while (j < k) {
                int twoSum = arr[j] + arr[k];

                // If the sum of arr[j] and arr[k] is greater than arr[i], count all pairs.
                if (twoSum > arr[i]) {
                    ans += (k - j);
                    k--; // Move the upper pointer to check smaller pairs.
                } else {
                    j++; // Move the lower pointer to check larger pairs.
                }
            }
        }

        return ans; // Return the total count of triangles.
    }
};