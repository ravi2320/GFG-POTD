/*
Union of Two Sorted Arrays
MediumAccuracy: 31.39%Submissions: 226K+Points: 4
Be the comment of the day in POTD and win a GfG T-Shirt!
Solve right now

banner
Given two sorted arrays of size n and m respectively, find their union. The Union of two arrays can be defined as the common and distinct elements in the two arrays. Return the elements in sorted order.

Example 1:

Input: 
n = 5, arr1[] = {1, 2, 3, 4, 5}  
m = 5, arr2 [] = {1, 2, 3, 6, 7}
Output: 
1 2 3 4 5 6 7
Explanation: 
Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Example 2:

Input: 
n = 5, arr1[] = {2, 2, 3, 4, 5}  
m = 5, arr2[] = {1, 1, 2, 3, 4}
Output: 
1 2 3 4 5
Explanation: 
Distinct elements including both the arrays are: 1 2 3 4 5.
Example 3:

Input:
n = 5, arr1[] = {1, 1, 1, 1, 1}
m = 5, arr2[] = {2, 2, 2, 2, 2}
Output: 
1 2
Explanation: 
Distinct elements including both the arrays are: 1 2.
Your Task: 
You do not need to read input or print anything. Complete the function findUnion() that takes two arrays arr1[], arr2[], and their size n and m as input parameters and returns a list containing the union of the two arrays.

Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(n+m).

Constraints:
1 <= n, m <= 105
-109 <= arr1[i], arr2[i] <= 109
*/

/*
Intuition:
- The problem is to find the union of two sorted arrays, ensuring no duplicates and maintaining sorted order.
- We can use a two-pointer technique to traverse both arrays simultaneously, adding unique elements to the result vector.

Approach:
1. Initialize two pointers, `i` and `j`, to the beginning of the arrays `arr1` and `arr2`, respectively.
2. Initialize an empty result vector `res` to store the union of the two arrays.
3. Traverse both arrays using the two pointers:
   - Skip duplicate elements in both arrays by incrementing the pointers until a new element is found.
   - Compare the current elements pointed by `i` and `j`:
     - If `arr1[i]` is less than `arr2[j]`, add `arr1[i]` to `res` and increment `i`.
     - If `arr1[i]` is greater than `arr2[j]`, add `arr2[j]` to `res` and increment `j`.
     - If `arr1[i]` is equal to `arr2[j]`, add either element to `res` and increment both `i` and `j`.
4. If any elements are left in either array after one pointer reaches the end, add the remaining elements to `res` while skipping duplicates.
5. Return the result vector `res`.

Time Complexity: O(n + m)
- Each element of both arrays is processed at most once.

Space Complexity: O(n + m)
- The result vector stores all unique elements from both arrays.

*/

class Solution {
public:
    //Function to return a list containing the union of the two arrays.
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        vector<int> res;
        int i = 0, j = 0;
        
        while (i < n && j < m) {
            // Skip duplicate elements in arr1
            while (i > 0 && i < n && arr1[i] == arr1[i - 1]) {
                i++;
            }
            // Skip duplicate elements in arr2
            while (j > 0 && j < m && arr2[j] == arr2[j - 1]) {
                j++;
            }
            
            if (i < n && j < m) {
                if (arr1[i] < arr2[j]) {
                    res.push_back(arr1[i]);
                    i++;
                } else if (arr1[i] > arr2[j]) {
                    res.push_back(arr2[j]);
                    j++;
                } else {
                    res.push_back(arr1[i]);
                    i++;
                    j++;
                }
            }
        }
        
        // Add remaining elements from arr1
        while (i < n) {
            if (i > 0 && arr1[i] != arr1[i - 1]) {
                res.push_back(arr1[i]);
            } else if (i == 0) {
                res.push_back(arr1[i]);
            }
            i++;
        }
        
        // Add remaining elements from arr2
        while (j < m) {
            if (j > 0 && arr2[j] != arr2[j - 1]) {
                res.push_back(arr2[j]);
            } else if (j == 0) {
                res.push_back(arr2[j]);
            }
            j++;
        }
        
        return res;
    }
};
