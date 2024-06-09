/*
Convert array into Zig-Zag fashion
EasyAccuracy: 58.28%Submissions: 129K+Points: 2
Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
Daily rewards up for grabs!

banner
Given an array arr of distinct elements of size n, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the below form: 

arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n]. 

Note: Modify the given arr[] only, If your transformation is correct, the output will be 1 else the output will be 0. 

Examples

Input: n = 7, arr[] = {4, 3, 7, 8, 6, 2, 1}
Output: 1
Explanation:  After modification the array will look like 3 < 7 > 4 < 8 > 2 < 6 > 1, the checker in the driver code will produce 1.
Input: n = 5, arr[] = {4, 7, 3, 8, 2}
Output: 1
Explanation: After modification the array will look like 4 < 7 > 3 < 8 > 2 hence output will be 1.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 106
0 <= arri <= 109
*/

/*
Intuition:
- The task is to rearrange the elements of an array in a zigzag fashion such that the sequence alternates between less than and greater than.
- For even indices (0, 2, 4,...), the element should be less than the next element.
- For odd indices (1, 3, 5,...), the element should be greater than the next element.
- This can be achieved by iterating through the array and swapping elements as needed to maintain the zigzag pattern.

Approach:
1. Iterate through the array from the first element to the second last element.
2. For each index `i`:
   - If `i` is even and `arr[i]` is greater than `arr[i+1]`, swap them.
   - If `i` is odd and `arr[i]` is less than `arr[i+1]`, swap them.

Time Complexity: O(n)
- The algorithm performs a single pass through the array, making it linear in time complexity.

Space Complexity: O(1)
- The algorithm uses a constant amount of extra space.

*/

class Solution {
public:
    void zigZag(int n, vector<int> &arr) {
        for(int i = 0; i < n - 1; i++) {
            if(i % 2 == 0 && arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
            if(i % 2 != 0 && arr[i] < arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
};
