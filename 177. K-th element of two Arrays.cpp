/*
K-th element of two Arrays
Difficulty: MediumAccuracy: 37.4%Submissions: 252K+Points: 4
Given two sorted arrays arr1 and arr2 and an element k. The task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: k = 5, arr1[] = [2, 3, 6, 7, 9], arr2[] = [1, 4, 8, 10]
Output: 6
Explanation: The final combined sorted array would be - 1, 2, 3, 4, 6, 7, 8, 9, 10. The 5th element of this array is 6.
Input: k = 7, arr1[] = [100, 112, 256, 349, 770], arr2[] = [72, 86, 113, 119, 265, 445, 892]
Output: 256
Explanation: Combined sorted array is - 72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892. 7th element of this array is 256.
Expected Time Complexity: O(log(n) + log(m))
Expected Auxiliary Space: O(log (n))

Constraints:
1 <= k<= arr1.size()+arr2.size()
1 <= arr1.size(), arr2.size() <= 106
0 <= arr1[i], arr2[i] < 108
*/

// Intuition: This function finds the k-th smallest element in the combined sorted array
// from two sorted arrays. It uses a binary search approach to minimize comparisons and 
// time complexity. The idea is to partition the arrays into two parts such that the 
// largest element in the left part is smaller than the smallest element in the right part.

// Time Complexity: O(log(min(n, m))), where n and m are the lengths of the two arrays. 
// This is because we are performing a binary search on the smaller array.
// Space Complexity: O(1), as we are using only a few extra variables.

class Solution {
public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        
        // Ensure arr1 is the smaller array to minimize binary search operations
        if (n > m) {
            return kthElement(k, arr2, arr1); 
        }
        
        // Binary search boundaries
        int low = max(0, k - m), high = min(k, n);
        
        while (low <= high) {
            int cut1 = (low + high) / 2; // Partition index in arr1
            int cut2 = k - cut1;         // Partition index in arr2
            
            // Left and right elements for the partitions
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            
            // Check if partition is correct
            if (l1 <= r2 && l2 <= r1) {
                return max(l1, l2); // Correct partition found
            }
            else if (l1 > r2) {
                high = cut1 - 1; // Move partition left in arr1
            }
            else {
                low = cut1 + 1; // Move partition right in arr1
            }
        }
        
        return -1; // If no valid partition found
    }
};
