/*
Insertion Sort
EasyAccuracy: 66.61%Submissions: 134K+Points: 2
Be the comment of the day in POTD and win a GfG T-Shirt!
Solve right now

banner
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

/*
Intuition:
- Insertion sort is an efficient algorithm for small data sets or nearly sorted arrays.
- It builds the final sorted array one item at a time by repeatedly inserting the next item into the correct position.

Approach:
1. Iterate through the array from the second element to the last.
2. For each element, compare it with the elements before it, and shift these elements one position to the right until the correct position for the current element is found.
3. Insert the current element into its correct position.
4. Repeat until the array is fully sorted.

Time Complexity: O(n^2) in the worst and average case.
- The nested comparisons and shifts result in O(n^2) operations.

Space Complexity: O(1)
- The algorithm sorts the array in place, requiring no additional storage.

Note: The `insert` function helps to place the element in the correct position by comparing and swapping elements in a backward manner.

*/

class Solution
{
    public:
    void insert(int arr[], int i)
    {
        //code here
        while(i > 0 && arr[i-1] > arr[i]){
            int temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
            i--;
        }
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for(int i=1; i<n; i++){
            insert(arr, i);
        }
    }
};
