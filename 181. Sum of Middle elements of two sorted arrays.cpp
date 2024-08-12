/*
Sum of Middle elements of two sorted arrays
Difficulty: MediumAccuracy: 47.98%Submissions: 76K+Points: 4
Given 2 sorted integer arrays arr1 and arr2 of the same size. Find the sum of the middle elements of two sorted arrays arr1 and arr2.

Examples:

Input: arr1 = [1, 2, 4, 6, 10], arr2 = [4, 5, 6, 9, 12]
Output: 11
Explanation: The merged array looks like [1, 2, 4, 4, 5, 6, 6, 9, 10, 12]. Sum of middle elements is 11 (5 + 6).
Input: arr1 = [1, 12, 15, 26, 38], arr2 = [2, 13, 17, 30, 45]
Output: 32
Explanation: The merged array looks like [1, 2, 12, 13, 15, 17, 26, 30, 38, 45]. Sum of middle elements is 32 (15 + 17).
Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr1.size() == arr2.size() <= 103
1 <= arr1[i] <= 106
1 <= arr2[i] <= 106
*/

/*
Intuition:
- The goal is to find the sum of the middle elements from two sorted arrays when they are combined.
- Instead of merging the two arrays, we can find the correct partition between the two arrays that divides them into two equal halves.
- By leveraging binary search on one of the arrays, we can efficiently determine this partition.

Time Complexity:
- O(log n): Binary search is used to find the correct partition, making the search logarithmic in relation to the array size.

Space Complexity:
- O(1): Only a constant amount of extra space is used for variables.
*/

class Solution {
public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size(); // Size of the arrays
        int low = 0, high = n; // Binary search range in arr1
        
        // Perform binary search to find the correct partition
        while(low <= high) {
            int mid1 = (low + high) >> 1;  // Middle index in arr1
            int mid2 = n - mid1;            // Corresponding index in arr2
            
            // Determine the boundary elements for the current partition
            int l1 = (mid1 > 0) ? arr1[mid1 - 1] : INT_MIN;  // Left element in arr1
            int l2 = (mid2 > 0) ? arr2[mid2 - 1] : INT_MIN;  // Left element in arr2
            int r1 = (mid1 < n) ? arr1[mid1] : INT_MAX;      // Right element in arr1
            int r2 = (mid2 < n) ? arr2[mid2] : INT_MAX;      // Right element in arr2
            
            // Check if we have found the correct partition
            if(l1 <= r2 && l2 <= r1) {
                // Sum of the middle elements after the merge
                return max(l1, l2) + min(r1, r2);
            }
            else if(l1 > r2) {
                // If l1 is greater, move the partition left in arr1
                high = mid1 - 1;
            }
            else {
                // Otherwise, move the partition right in arr1
                low = mid1 + 1;
            }
        }
        
        return 0; // This line should not be reached
    }
};
