/*
Find Pair Given Difference
EasyAccuracy: 27.25%Submissions: 219K+Points: 2
Given an array arr[] of size n and an integer x, return 1 if there exists a pair of elements in the array whose absolute difference is x, otherwise, return -1.

Example 1:

Input:
n = 6
x = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output:
1
Explanation:
Pair (2, 80) have absolute difference of 78.
Example 2:

Input:
n = 5
x = 45
arr[] = {90, 70, 20, 80, 50}
Output:
-1
Explanation:
There is no pair with absolute difference of 45.
Your Task:
You need not take input or print anything. Your task is to complete the function findPair() which takes integers n, x, and an array arr[] as input parameters and returns 1 if the required pair exists, return -1 otherwise.

Expected Time Complexity: O(n* Log(n)).
Expected Auxiliary Space: O(1).

Constraints:
1<=n<=106 
1<=arr[i]<=106 
0<=x<=105
*/

// Intuition:
// - The problem requires us to find if there exists a pair of elements in the array with an absolute difference of `x`.
// - We use a two-pointer approach to solve this problem efficiently after sorting the array.
// - The pointers `i` and `j` start from the beginning of the array. We keep adjusting the pointers based on the difference between `arr[j]` and `arr[i]`.
// - If the difference is equal to `x` and `i` is not equal to `j`, we return 1 indicating such a pair exists.
// - If the difference is greater than `x`, we move the `i` pointer forward to decrease the difference.
// - If the difference is less than `x`, we move the `j` pointer forward to increase the difference.
// - If no such pair is found, we return -1.

// Time Complexity: O(N log N), where N is the number of elements in the array.
// - Sorting the array takes O(N log N) time.
// - The two-pointer traversal of the array takes O(N) time.
// - Therefore, the overall time complexity is dominated by the sorting step, resulting in O(N log N).

// Space Complexity: O(1)
// - The solution uses a constant amount of additional space, regardless of the input size.

class Solution {
public:
    int findPair(int n, int x, vector<int> &arr) {
        // Sort the array to facilitate the two-pointer approach
        sort(arr.begin(), arr.end());
        
        int i = 0, j = 1;
        while (i < n && j < n) {
            int diff = abs(arr[j] - arr[i]);
            if (diff == x && i != j)
                return 1;  // Found a pair with the desired difference
            else if (diff > x)
                i++;  // Move the left pointer to reduce the difference
            else
                j++;  // Move the right pointer to increase the difference
        }
        
        return -1;  // No such pair found
    }
};
