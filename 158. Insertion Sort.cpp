/*
Insertion Sort
Difficulty: EasyAccuracy: 66.61%Submissions: 150K+Points: 2
The task is to complete the insert() function which is used to implement Insertion Sort.


Example 1:

Input:
N = 5
arr[] = { 4, 1, 3, 9, 7}
Output:
1 3 4 7 9
Example 2:

Input:
N = 10
arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
Output:
1 2 3 4 5 6 7 8 9 10

Your Task: 
You don't have to read input or print anything. Your task is to complete the function insert() and insertionSort() where insert() takes the array, it's size and an index i and insertionSort() uses insert function to sort the array in ascending order using insertion sort algorithm. 

Expected Time Complexity: O(N*N).
Expected Auxiliary Space: O(1).


Constraints:
1 <= N <= 1000
1 <= arr[i] <= 1000


*/

/**
 * Intuition:
 * - **Insertion Sort:** The algorithm sorts the array by repeatedly taking the next element and inserting it into its correct position among the previously sorted elements. This implementation uses recursion to perform the insertion process.
 *
 * Time Complexity: O(n^2)
 * - In the worst case, the algorithm needs to shift elements n-1 times for each of the n elements, resulting in a time complexity of O(n^2).
 *
 * Space Complexity: O(n)
 * - The recursive solution has a space complexity of O(n) due to the recursive call stack.
 */

class Solution
{
    public:
    // Recursive function to insert an element into the sorted part of the array
    void insert(int arr[], int n, int i)
    {
        // Base case: if we have reached the end of the array, return
        if (i == n) return;
        
        int j = i;
        
        // Move the current element to its correct position in the sorted part of the array
        while (j > 0 && arr[j-1] > arr[j]) {
            // Swap arr[j] and arr[j-1]
            arr[j] = arr[j] + arr[j-1];
            arr[j-1] = arr[j] - arr[j-1];
            arr[j] = arr[j] - arr[j-1];
            j--;
        }
        
        // Recur for the next element
        insert(arr, n, i + 1);
    }
    
    public:
    // Function to sort the array using the insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        // Start the recursive insertion process from the second element
        insert(arr, n, 1);
    }
};
