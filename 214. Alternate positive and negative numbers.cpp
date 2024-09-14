/*
Alternate positive and negative numbers
Difficulty: EasyAccuracy: 33.86%Submissions: 185K+Points: 2
Given an unsorted array arr containing both positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with a positive number and 0 (zero) should be considered a positive element.

Examples:

Input: arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]
Output: 9 -2 4 -1 5 -5 0 -3 2
Explanation: Positive elements : [9,4,5,0,2]
Negative elements : [-2,-1,-5,-3]
As we need to maintain the relative order of postive elements and negative elements we will pick each element from the positive and negative and will store them. If any of the positive and negative numbersare completed. we will continue with the remaining signed elements.
The output is 9,-2,4,-1,5,-5,0,-3,2.
Input: arr[] = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
Output: 5 -5 2 -2 4 -8 7 1 8 0
Explanation : Positive elements : [5,2,4,7,1,8,0]
Negative elements : [-5,-2,-8]
The output is 5, -5, 2, -2, 4, -8, 7, 1, 8, 0.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 107
-106 ≤ arr[i] ≤ 107
*/

/*
Approach:
1. The task is to rearrange the elements of the array such that positive and negative numbers alternate. If either positive or negative numbers run out, the remaining numbers of the other type are placed at the end of the array.
2. We first create two separate vectors, `pos` for storing positive numbers and `neg` for storing negative numbers.
3. Based on the size of the `pos` and `neg` arrays, we alternate the positive and negative numbers and fill the array.
4. If one of the arrays (`pos` or `neg`) runs out before the other, the remaining elements are appended to the end of the array.

Time Complexity:
- O(n): We traverse the array twice, once to separate positive and negative numbers and once to rearrange them.

Space Complexity:
- O(n): We use additional space to store the positive and negative numbers in two separate vectors.

*/

class Solution {
public:
    void rearrange(vector<int> &arr) {
        vector<int> pos, neg;

        // Separate positive and negative numbers into `pos` and `neg` vectors.
        for(int &x : arr) {
            if(x < 0) neg.push_back(x);
            else pos.push_back(x);
        }

        int n = pos.size(), m = neg.size(); // Sizes of positive and negative vectors.

        // Case when there are fewer positive numbers than negative.
        if(n < m) {
            for(int i = 0; i < n; i++) {
                arr[2 * i] = pos[i];    // Place positive numbers at even indices.
                arr[2 * i + 1] = neg[i]; // Place negative numbers at odd indices.
            }
            int idx = 2 * n; // Start placing remaining negative numbers.
            for(int i = n; i < m; i++) {
                arr[idx++] = neg[i];
            }
        }
        // Case when there are fewer negative numbers or equal numbers.
        else {
            for(int i = 0; i < m; i++) {
                arr[2 * i] = pos[i];    // Place positive numbers at even indices.
                arr[2 * i + 1] = neg[i]; // Place negative numbers at odd indices.
            }
            int idx = 2 * m; // Start placing remaining positive numbers.
            for(int i = m; i < n; i++) {
                arr[idx++] = pos[i];
            }
        }
    }
};
