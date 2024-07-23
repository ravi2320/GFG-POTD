/*
Quick Sort
Difficulty: MediumAccuracy: 55.23%Submissions: 207K+Points: 4
Quick Sort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot.
Given an array arr[], its starting position is low (the index of the array) and its ending position is high(the index of the array).

Note: The low and high are inclusive.

Implement the partition() and quickSort() functions to sort the array.

Example 1:

Input: 
N = 5 
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9
Example 2:

Input: 
N = 9
arr[] = { 2, 1, 6, 10, 4, 1, 3, 9, 7}
Output:
1 1 2 3 4 6 7 9 10
Your Task: 
You don't need to read input or print anything. Your task is to complete the functions partition()  and quickSort() which takes the array arr[], low and high as input parameters and partitions the array. Consider the last element as the pivot such that all the elements less than(or equal to) the pivot lie before it and the elements greater than it lie after the pivot.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(logN)

Constraints:
1 <= N <= 103
1 <= arr[i] <= 104
*/

/**
 * Intuition:
 * - **QuickSort:** A divide-and-conquer algorithm that picks an element as a pivot and partitions the array around the pivot.
 * - **Partition:** Rearranges the array such that all elements less than the pivot come before it, and all elements greater than the pivot come after it.
 *
 * Time Complexity:
 * - Best/Average Case: O(n log n)
 * - Worst Case: O(n^2) (when the smallest or largest element is always chosen as the pivot)
 *
 * Space Complexity: O(log n) for the recursion stack.
 */

class Solution
{
    public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // Recursive case: if the subarray has more than one element
        if(low < high){
            // Partition the array and get the pivot index
            int partitionIdx = partition(arr, low, high);
            // Recursively apply quicksort to the left and right subarrays
            quickSort(arr, low, partitionIdx - 1);
            quickSort(arr, partitionIdx + 1, high);
        }
    }
    
    private:
    // Function to partition the array and return the pivot index
    int partition (int arr[], int low, int high)
    {
       // Choose the pivot element (first element of the subarray)
       int pivot = arr[low];
       int i = low; // Start index
       int j = high; // End index
       
       // Rearrange elements around the pivot
       while(i < j){
           // Move the left pointer until an element greater than the pivot is found
           while(i <= high && arr[i] <= pivot){
               i++;
           }
           // Move the right pointer until an element less than or equal to the pivot is found
           while(j >= low && arr[j] > pivot){
               j--;
           }
           // Swap elements to maintain the partitioning condition
           if(i < j){
               swap(arr[i], arr[j]);
           }
       }
       
       // Place the pivot in its correct position
       swap(arr[low], arr[j]);
       
       // Return the pivot index
       return j;
    }
};
