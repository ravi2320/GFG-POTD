/*
Max sum in sub-arrays
EasyAccuracy: 43.26%Submissions: 37K+Points: 2
Be the comment of the day in POTD and win a GfG T-Shirt!
Solve right now

banner
Given an array Arr, with indexes running from 0 to N-1, select any two indexes, i and j such that i<=j-1. From subarray Arr[i...j], find the two smallest numbers and add them, you will get score for that subarray. Your task is to return maximum score possible in the given array Arr.
 

Example 1:

Input : arr[] = [4, 3, 1, 5, 6]
Output : 11
Subarrays with smallest and 
second smallest are,
[4, 3]        
smallest = 3    second smallest = 4
[4, 3, 1]    
smallest = 1    second smallest = 3
[4, 3, 1, 5]    
smallest = 1    second smallest = 3
[4, 3, 1, 5, 6]    
smallest = 1    second smallest = 3
[3, 1]         
smallest = 1    second smallest = 3
[3, 1, 5]     
smallest = 1    second smallest = 3
[3, 1, 5, 6]    
smallest = 1    second smallest = 3
[1, 5]        
smallest = 1    second smallest = 5
[1, 5, 6]    
smallest = 1    second smallest = 5
[5, 6]         
smallest = 5    second smallest = 6
Maximum sum among all 
above choices is, 5 + 6 = 11
 
Example 2:
Input : arr[] = {5, 4, 3, 1, 6} 
Output : 9
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function pairWithMaxSum() which takes the array Arr[] and its size N as inputs and returns the maximum sum of smallest and second smallest elements chosen from all possible subarrays.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ N ≤ 105
1 ≤ A[i] ≤ 1018
*/

/*
Intuition:
- The task is to find the maximum sum of any pair of adjacent elements in the array.
- This can be achieved by iterating through the array and comparing the sum of each adjacent pair.

Approach:
1. Initialize `maxi` with the sum of the first two elements of the array.
2. Traverse the array from the second element to the last element.
3. For each element, compute the sum of the current element and the previous element.
4. Update `maxi` if the computed sum is greater than the current value of `maxi`.

Time Complexity:
- O(N), where N is the number of elements in the array.

Space Complexity:
- O(1), as we use a constant amount of extra space.

*/

class Solution {
public:
    long long pairWithMaxSum(long long arr[], long long N) {
        // Initializing with the sum of the first two elements
        long long maxi = arr[0] + arr[1];
        
        // Iterating from the second element to the last element
        for(long long i = 1; i < N; i++) {
            // Updating maxi with the maximum sum of adjacent pairs
            maxi = max(maxi, arr[i-1] + arr[i]);
        }
        
        return maxi;
    }
};
