/*
Product array puzzle
Difficulty: EasyAccuracy: 33.46%Submissions: 264K+Points: 2
Given an array, arr[] construct a product array, res[] where each element in res[i] is the product of all elements in arr[] except arr[i]. Return this resultant array, res[].
Note: Each element is res[] lies inside the 32-bit integer range.

Examples:

Input: arr[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]
Explanation: For i=0, res[i] = 3 * 5 * 6 * 2 is 180.
For i = 1, res[i] = 10 * 5 * 6 * 2 is 600.
For i = 2, res[i] = 10 * 3 * 6 * 2 is 360.
For i = 3, res[i] = 10 * 3 * 5 * 2 is 300.
For i = 4, res[i] = 10 * 3 * 5 * 6 is 900.
Input: arr[] = [12, 0]
Output: [0, 12]
Explanation: For i = 0, res[i] is 0.
For i = 1, res[i] is 12.
Constraints:
2 <= arr.size() <= 105
-100 <= arr[i] <= 100
*/

/*
Approach:
1. We need to compute a product array where each element is the product of all elements in the array except the current one.
2. Special cases:
   - If there are more than one zero in the array, all products will be zero.
   - If there is exactly one zero, the product will be zero for all indices except the one with the zero, which will have the product of the non-zero elements.
   - If there are no zeros, the product for each index can be calculated by dividing the total product by the current element.
3. Efficient Calculation:
   - Use a single pass to calculate the total product and count zeros.
   - Depending on the number of zeros, compute the result in \(O(n)\).

Time Complexity:
- \(O(n)\): Single pass to compute the product and another pass to compute the result.

Space Complexity:
- \(O(1)\): Only the result array is used; no extra space is allocated apart from the input.

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        int zeroCount = 0;        // Count the number of zeros in the array
        long long totalProduct = 1; // Store the product of all non-zero elements

        // Step 1: Compute the total product and count zeros
        for (int x : arr) {
            if (x == 0) {
                zeroCount++;
            } else {
                totalProduct *= x;
            }
        }

        // Step 2: Initialize the result array
        vector<int> result(n, 0);

        // Step 3: Handle cases based on the number of zeros
        if (zeroCount > 1) {
            // Case 1: More than one zero, all products are zero
            return result;
        } else if (zeroCount == 1) {
            // Case 2: Exactly one zero, only one index will have a non-zero product
            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) {
                    result[i] = totalProduct; // Assign total product to the index with zero
                    break;
                }
            }
        } else {
            // Case 3: No zeros, compute the product for each index
            for (int i = 0; i < n; i++) {
                result[i] = totalProduct / arr[i]; // Use integer division
            }
        }

        return result;
    }
};


/*
Approach:
1. The goal is to compute a product array where each element is the product of all other elements except the current one.
2. To achieve this without division, use two passes:
   - First pass: Compute prefix products for each element and store them in the result array.
   - Second pass: Compute suffix products while updating the result array with the product of prefix and suffix.
3. By maintaining a single result array and updating it on the fly, the space usage is reduced to \(O(1)\) extra space (excluding the result).

Time Complexity:
- \(O(n)\): Two passes (prefix and suffix).

Space Complexity:
- \(O(1)\): The result array is the only extra space used.

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 1); // Initialize result array with 1s

        // Step 1: Compute prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = prefix;   // Assign the prefix product to the current index
            prefix *= arr[i];  // Update prefix for the next iteration
        }

        // Step 2: Compute suffix products and multiply with the prefix values in ans
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;  // Multiply the current suffix with the prefix value
            suffix *= arr[i];  // Update suffix for the next iteration
        }

        return ans;
    }
};