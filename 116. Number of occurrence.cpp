/*
Number of occurrence
Difficulty: MediumAccuracy: 59.34%Submissions: 200K+Points: 4
Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
Example 2:

Input:
N = 7, X = 4
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 0
Explanation: 4 is not present in the
given array.
Your Task:
You don't need to read input or print anything.
Your task is to complete the function count() which takes the array of integers arr, n, and x as parameters and returns an integer denoting the answer.
If x is not present in the array (arr) then return 0.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ 106
1 ≤ X ≤ 106
*/

// Intuition:
// To find the count of occurrences of a number in a sorted array, we can use binary search.
// First, we'll find the first occurrence of the number. Then, we'll find the last occurrence of the number.
// The count of occurrences will be the difference between the positions of the last and first occurrence plus one.

// Time Complexity: O(log n) for each of the helper functions, leading to an overall time complexity of O(log n).
// Space Complexity: O(1) as we are using a constant amount of extra space.

class Solution{
public:	
    int firstPos(int arr[], int n, int x) {
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                ans = mid;
                high = mid - 1;  // look for earlier occurrences
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int lastPos(int arr[], int n, int x) {
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == x) {
                ans = mid;
                low = mid + 1;  // look for later occurrences
            } else if (arr[mid] < x) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    int count(int arr[], int n, int x) {
        int first = firstPos(arr, n, x);
        if (first == -1) return 0;

        int last = lastPos(arr, n, x); 
        return (last - first) + 1;
    }
};
