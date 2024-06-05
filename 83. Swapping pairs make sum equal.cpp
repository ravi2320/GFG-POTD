/*
Swapping pairs make sum equal
MediumAccuracy: 23.94%Submissions: 103K+Points: 4
In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

banner
Given two arrays of integers a[] and b[] of size n and m, the task is to check if a pair of values (one value from each array) exists such that swapping the elements of the pair will make the sum of two arrays equal.

Note: Return 1 if there exists any such pair otherwise return -1.

Example 1:

Input: n = 6, m = 4, a[] = {4, 1, 2, 1, 1, 2}, b[] = (3, 6, 3, 3)
Output: 1
Explanation: Sum of elements in a[] = 11, Sum of elements in b[] = 15, To get same sum from both arrays, we can swap following values: 1 from a[] and 3 from b[]
Example 2:

Input: n = 4, m = 4, a[] = {5, 7, 4, 6}, b[] = {1, 2, 3, 8}
Output: 1
Explanation: We can swap 6 from array a[] and 2 from array b[]
Expected Time Complexity: O(mlogm+nlogn).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ n, m ≤ 106
0 <= a[i], b[i] <= 105
*/

// Intuition:
// - To find if there is a pair of values, one from each array, that can be swapped to make the sums of the two arrays equal.
// - Calculate the sum of both arrays. 
// - Calculate the difference between the sums. If the difference is odd, it is not possible to find such a pair since the sum needs to be an integer.
// - Use a set to store elements of one array for efficient lookup.
// - Check if for each element in the first array, there exists a corresponding element in the second array such that swapping these elements equalizes the sums.

// Approach:
// 1. Calculate the sum of both arrays.
// 2. Calculate the difference between the sums. If it is odd, return -1 since it is not possible to find such pairs.
// 3. Store elements of the second array in a set for efficient lookup.
// 4. For each element in the first array, calculate the target value needed from the second array to equalize the sums.
// 5. If the target value exists in the set, return 1 indicating a valid swap exists. Otherwise, return -1.

// Time Complexity: O(n + m), where n is the size of the first array and m is the size of the second array.
// - Calculating the sums and storing elements in a set takes linear time.
// - Checking for the target value in the set for each element of the first array takes linear time.

// Space Complexity: O(m), where m is the size of the second array.
// - We use additional space to store the elements of the second array in a set.

class Solution {
public:
    int findSwapValues(int a[], int n, int b[], int m) {
        int sum1 = 0, sum2 = 0;
        unordered_set<int> st;

        // Calculate the sum of both arrays
        for(int i = 0; i < n; i++) {
            sum1 += a[i];
        }
        for(int i = 0; i < m; i++) {
            sum2 += b[i];
            st.insert(b[i]);  // Insert elements of b into the set
        }

        int diff = sum1 - sum2;
        if (diff % 2 != 0)  // If the difference is odd, return -1
            return -1;
        
        diff /= 2;

        // Check for each element in array a if there's a corresponding element in b
        for(int i = 0; i < n; i++) {
            int target = a[i] - diff;
            if (st.find(target) != st.end()) {
                return 1;
            }
        }

        return -1;
    }
};
