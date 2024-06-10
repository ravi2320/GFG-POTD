/*
Searching an element in a sorted array
BasicAccuracy: 48.03%Submissions: 200K+Points: 1
Be the comment of the day in POTD and win a GfG T-Shirt!
Solve right now

banner
Given an array arr[] sorted in ascending order of size N and an integer K. Check if K is present in the array or not.


Example 1:

Input:
N = 5, K = 6
arr[] = {1,2,3,4,6}
Output: 1
Exlpanation: Since, 6 is present in 
the array at index 4 (0-based indexing),
output is 1.
 

Example 2:

Input:
N = 5, K = 2
arr[] = {1,3,4,5,6}
Output: -1
Exlpanation: Since, 2 is not present 
in the array, output is -1.
 

Your Task:
You don't need to read input or print anything. Complete the function searchInSorted() which takes the sorted array arr[], its size N and the element K as input parameters and returns 1 if K is present in the array, else it returns -1. 


Expected Time Complexity: O(Log N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 <= N <= 106
1 <= K <= 106
1 <= arr[i] <= 106

 
*/

/*
Intuition:
- The problem is to find if an element K is present in a sorted array.
- Since the array is sorted, we can use binary search to efficiently find the element.

Approach:
1. Initialize two pointers, `l` and `r`, to the beginning and end of the array, respectively.
2. While `l` is less than or equal to `r`:
   - Calculate the mid-point of the array.
   - If the element at the mid-point is equal to K, return 1 (element found).
   - If the element at the mid-point is greater than K, adjust the right pointer `r` to `mid - 1` to search the left half.
   - If the element at the mid-point is less than K, adjust the left pointer `l` to `mid + 1` to search the right half.
3. If the loop terminates without finding the element, return -1 (element not found).

Time Complexity: O(log N)
- The binary search algorithm reduces the search space by half in each iteration.

Space Complexity: O(1)
- The algorithm uses a constant amount of extra space.

*/

class Solution{
public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int searchInSorted(int arr[], int N, int K) { 
        int l = 0, r = N - 1;
        
        while(l <= r){
            int mid = (l + r) / 2;
            
            if(arr[mid] == K)
                return 1;  // Element found
            else if(arr[mid] > K)
                r = mid - 1;  // Search the left half
            else
                l = mid + 1;  // Search the right half
        }
        
        return -1;  // Element not found
    }
};
