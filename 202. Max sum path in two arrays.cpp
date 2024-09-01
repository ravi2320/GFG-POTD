/*
Max sum path in two arrays
Difficulty: MediumAccuracy: 30.9%Submissions: 54K+Points: 4
Given two sorted arrays of distinct integers arr1 and arr2. Each array may have some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end of any array. You can switch from one array to another array only at the common elements.

Note:  When we switch from one array to other,  we need to consider the common element only once in the result.

Examples : 

Input: arr1 = [2, 3, 7, 10, 12] , arr2 = [1, 5, 7, 8]
Output: 35
Explanation: The path will be 1+5+7+10+12 = 35, where 1 and 5 come from arr2 and then 7 is common so we switch to arr1 and add 10 and 12.
Input: arr1 = [1, 2, 3] , arr2[] = [3, 4, 5]
Output: 15
Explanation: The path will be 1+2+3+4+5=15.
Expected Time Complexity: O(m + n)
Expected Auxiliary Space: O(1)
Constraints:
1 <= arr1.size(), arr2.size() <= 104
1 <= arr1[i], arr2[i] <= 105
*/

/*
**Problem Statement:**
- You are given two sorted arrays `arr1` and `arr2`. You can traverse each array from left to right, but you are allowed to switch between the two arrays only at the common elements (i.e., elements present in both arrays).
- The objective is to find the maximum sum path by choosing elements from both arrays.

**Approach:**
1. **Two-Pointer Technique:**
   - Use two pointers `i` and `j` to traverse `arr1` and `arr2`, respectively.
   - Maintain two cumulative sums, `sum1` for `arr1` and `sum2` for `arr2`, to track the sum of the elements until a common element is encountered.
   - When a common element is found at both `arr1[i]` and `arr2[j]`, add the maximum of `sum1` and `sum2` to the `ansSum`, and then add the common element to `ansSum`.
   - Reset `sum1` and `sum2` to zero after adding the maximum of both sums to `ansSum`.

2. **Handling Remaining Elements:**
   - After traversing both arrays, if there are remaining elements in `arr1` or `arr2`, add them to their respective sums.
   - Finally, add the maximum of the two sums (`sum1` and `sum2`) to `ansSum` to account for the path that includes the remaining elements.

**Time Complexity:**
- The time complexity is `O(n + m)`, where `n` is the length of `arr1` and `m` is the length of `arr2`, since we are iterating through both arrays linearly.

**Space Complexity:**
- The space complexity is `O(1)` because we are using only a few extra variables.

**Example Usage:**
- Given `arr1 = {2, 3, 7, 10, 12}` and `arr2 = {1, 5, 7, 8}`, the function will return the maximum sum path between the two arrays.
*/

class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int i = 0, j = 0;
        long sum1 = 0, sum2 = 0, ansSum = 0;
        int n = arr1.size(), m = arr2.size();
        
        while(i < n && j < m) {
            if(arr1[i] == arr2[j]) {
                // Common element found, add maximum of the two cumulative sums plus the common element
                ansSum += arr1[i];
                ansSum += max(sum1, sum2);
                // Reset the cumulative sums
                sum1 = 0;
                sum2 = 0;
                // Move both pointers forward
                i++, j++;
            } else if(arr1[i] < arr2[j]) {
                // Add the current element of arr1 to sum1
                sum1 += arr1[i++];
            } else {
                // Add the current element of arr2 to sum2
                sum2 += arr2[j++];
            }
        }
        
        // Add remaining elements of arr1, if any
        while(i < n) {
            sum1 += arr1[i++];
        }
        
        // Add remaining elements of arr2, if any
        while(j < m) {
            sum2 += arr2[j++];
        }
        
        // Add the maximum of the two remaining sums to the final answer
        ansSum += max(sum1, sum2);
        
        return ansSum;  // Return the maximum sum path
    }
};

// Example usage:
int main() {
    vector<int> arr1 = {2, 3, 7, 10, 12};
    vector<int> arr2 = {1, 5, 7, 8};
    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(arr1, arr2) << endl;
    return 0;
}
