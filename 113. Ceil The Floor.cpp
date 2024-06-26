/*
Ceil The Floor
Difficulty: EasyAccuracy: 43.76%Submissions: 60K+Points: 2
Given an unsorted array Arr[] of N integers and an integer X, find floor and ceiling of X in Arr[0..N-1].

Floor of X is the largest element which is smaller than or equal to X. Floor of X doesn’t exist if X is smaller than smallest element of Arr[].

Ceil of X is the smallest element which is greater than or equal to X. Ceil of X doesn’t exist if X is greater than greatest element of Arr[].

Example 1:

Input:
N = 8, X = 7
Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
Output: 6 8
Explanation:
Floor of 7 is 6 and ceil of 7 
is 8.
Example 2:

Input:
N = 8, X = 10
Arr[] = {5, 6, 8, 9, 6, 5, 5, 6}
Output: 9 -1
Explanation:
Floor of 10 is 9 but ceil of 10 is not 
possible.
Your Task:
You don't need to read input or print anything. Your task is to complete the function getFloorAndCeil() which takes the array of integers arr, n and x as parameters and returns a pair of integers denoting the answer. Return -1 if floor or ceil is not present.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints :
1 ≤ N ≤ 105
1 ≤ Arr[i], X ≤ 106
*/

/**
 * Intuition:
 * - The problem requires finding both the floor and the ceiling of a given number `x` in an unsorted array.
 * - The floor of `x` is the largest number in the array that is less than or equal to `x`.
 * - The ceiling of `x` is the smallest number in the array that is greater than or equal to `x`.
 * - We can iterate through the array once to find these values.

 * Time Complexity: O(n)
 * - We iterate through the array once to find both the floor and ceiling, making the time complexity linear relative to the size of the array.

 * Space Complexity: O(1)
 * - We use only a constant amount of extra space for storing the floor and ceiling values.

 */

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    int floor_no = INT_MIN;
    int ceil_no = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        if (arr[i] <= x) {
            floor_no = max(floor_no, arr[i]);
        }
        
        if (arr[i] >= x) {
            ceil_no = min(ceil_no, arr[i]);
        }
    }
    
    if (floor_no == INT_MIN) {
        floor_no = -1;
    }
        
    if (ceil_no == INT_MAX) {
        ceil_no = -1;
    }
        
    return {floor_no, ceil_no};
}
