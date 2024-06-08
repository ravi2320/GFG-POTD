/*
Second Largest
EasyAccuracy: 26.72%Submissions: 535K+Points: 2
Be the comment of the day in POTD and win a GfG T-Shirt!
Solve right now

banner
Given an array Arr of size N, print the second largest distinct element from an array. If the second largest element doesn't exist then return -1.

Example 1:

Input: 
N = 6
Arr[] = {12, 35, 1, 10, 34, 1}
Output: 34
Explanation: The largest element of the 
array is 35 and the second largest element
is 34.
Example 2:

Input: 
N = 3
Arr[] = {10, 5, 10}
Output: 5
Explanation: The largest element of 
the array is 10 and the second 
largest element is 5.
Your Task:
You don't need to read input or print anything. Your task is to complete the function print2largest() which takes the array of integers arr and n as parameters and returns an integer denoting the answer. If 2nd largest element doesn't exist then return -1.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ N ≤ 105
1 ≤ Arri ≤ 105

*/

/*
Intuition:
- The task is to find the second largest element in an array. This can be done by maintaining two variables: one for the largest element and one for the second largest element.
- We iterate through the array and update these two variables accordingly to ensure they always hold the largest and second largest values encountered so far.

Approach:
1. Initialize `max` to the first element of the array and `sec_max` to -1 (or another sentinel value that indicates no second largest element has been found yet).
2. Traverse the array starting from the second element.
3. For each element, update `max` and `sec_max`:
   - If the current element is greater than `max`, update `sec_max` to `max` and then update `max` to the current element.
   - If the current element is less than `max` but greater than `sec_max`, update `sec_max` to the current element.
4. After the loop, `sec_max` will hold the second largest value in the array.

Time Complexity: O(n)
- The loop runs for `n` elements, making the approach linear in time complexity.

Space Complexity: O(1)
- The space complexity is constant as we only use a few extra variables regardless of the input size.

*/

class Solution {
public:
    // Function returns the second largest element
    int print2largest(int arr[], int n) {
        int max = arr[0];
        int sec_max = -1;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                sec_max = max;
                max = arr[i];
            } else if (arr[i] > sec_max && arr[i] < max) {
                sec_max = arr[i];
            }
        }
        
        return sec_max;
    }
};
