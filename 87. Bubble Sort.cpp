/*
Bubble Sort
EasyAccuracy: 59.33%Submissions: 171K+Points: 2
Be the comment of the day in POTD and win a GfG T-Shirt!
Solve right now

banner
Given an Integer N and a list arr. Sort the array using bubble sort algorithm.
Example 1:

Input: 
N = 5
arr[] = {4, 1, 3, 9, 7}
Output: 
1 3 4 7 9
Example 2:

Input:
N = 10 
arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
Output: 
1 2 3 4 5 6 7 8 9 10

Your Task: 
You don't have to read input or print anything. Your task is to complete the function bubblesort() which takes the array and it's size as input and sorts the array using bubble sort algorithm.

Expected Time Complexity: O(N^2).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 103
1 <= arr[i] <= 103
*/

/*
Intuition:
- Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
- This process is repeated until the list is sorted.

Approach:
1. Iterate over the array multiple times.
2. During each iteration, compare adjacent elements and swap them if they are in the wrong order.
3. Each complete iteration places the next largest element in its correct position, reducing the number of elements to be sorted by one.
4. Repeat the process until no swaps are needed, indicating that the array is sorted.

Time Complexity: O(n^2) in the worst and average case.
- The nested loops result in O(n^2) comparisons and swaps.

Space Complexity: O(1)
- The algorithm sorts the array in place, requiring no additional storage.

Note: The provided code sorts the array incorrectly. The inner loop should iterate in the reverse direction to perform a proper bubble sort.
*/

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n) {
        // Your code here
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};
