/*
Union of Two Sorted Arrays with Distinct Elements
Difficulty: EasyAccuracy: 55.4%Submissions: 13K+Points: 2
Given two sorted arrays a[] and b[], where each array contains distinct elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 3, 4, 5], b[] = [1, 2, 3, 4]
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1], b[] = [2]
Output: 1 2
Explanation: Distinct elements including both the arrays are: 1 2.
Constraints:
1  <=  a.size(), b.size()  <=  105
-109  <=  a[i] , b[i]  <=  109
*/

/*
Approach:
1. Use a two-pointer technique to merge sorted arrays `a` and `b` into a union array without duplicates.
2. Initialize two pointers `i` and `j` for arrays `a` and `b`, respectively.
3. Traverse both arrays until one pointer reaches the end:
   - If `a[i]` equals `b[j]`, add the element to the result and increment both pointers to avoid duplicates.
   - If `a[i]` is smaller, add `a[i]` to the result and increment `i`.
   - If `b[j]` is smaller, add `b[j]` to the result and increment `j`.
4. Once one of the arrays is fully traversed, add the remaining elements of the other array to the result.

Time Complexity: O(n + m), where `n` and `m` are the sizes of `a` and `b`.
Space Complexity: O(n + m), for storing the union of both arrays in `res`.
*/

class Solution {
public:
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> res;
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        
        // Traverse both arrays using two pointers
        while(i < n && j < m) {
            if(a[i] == b[j]) { // Same element in both arrays
                res.push_back(a[i]);
                i++, j++;
            } 
            else if(a[i] < b[j]) { // Element in `a` is smaller
                res.push_back(a[i++]);
            } 
            else { // Element in `b` is smaller
                res.push_back(b[j++]);
            }
        }
        
        // Add remaining elements from array `a`
        while(i < n) {
            res.push_back(a[i++]);
        }
        
        // Add remaining elements from array `b`
        while(j < m) {
            res.push_back(b[j++]);
        }
        
        return res;
    }
};
