/*
Split the Array
Difficulty: EasyAccuracy: 60.35%Submissions: 4K+Points: 2
Given an array arr[] of integers, the task is to count the number of ways to split given array elements into two disjoint groups such that the XOR of elements of each group is equal.
Note: The answer could be very large so print it by doing modulo with 109 + 7. 

Examples:

Input : arr[] = [1, 2, 3]
Output : 3
Explanation: {(1),(2, 3)}, {(2),(1, 3)}, {(3),(1, 2)} are three ways with equal XOR value of two groups.
Input : arr[] = [5, 2, 3, 2]
Output : 0
Explanation: No way to split into  two groups whose XOR is equal.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1<=arr.size()<=106
1<=arr[i]<=106
*/

/*
Approach:
- The problem is to count the number of valid groups from the given array. A valid group is defined as a subset of the array where the XOR of all elements in the subset is zero.
- We start by calculating the XOR of the entire array.
  1. If the XOR of the entire array is non-zero, then there is no valid way to partition the array into subsets with zero XOR.
  2. If the XOR is zero, then we need to count the possible ways to partition the array into two non-empty subsets. This is given by 2^(n-1) - 1, where `n` is the size of the array.

Time Complexity:
- O(n), where n is the size of the array. We compute the XOR of the entire array, which takes O(n) time.

Space Complexity:
- O(1), since we only use a few integer variables for storing XOR values and results.

*/

class Solution {
  public:
    int countgroup(vector<int>& arr) {
        int n = arr.size();  // Size of the input array
        int mod = 1e9+7;     // Modulo value to prevent overflow
        int Xor = 0;         // Variable to store the XOR of the entire array
        
        // Compute the XOR of all elements in the array
        for(int i = 0; i < n; i++) {
            Xor ^= arr[i];
        }
        
        // If the XOR is non-zero, return 0 (no valid subsets)
        if(Xor != 0) {
            return 0;
        }
        
        // If the XOR is zero, calculate the number of valid partitions
        // 2^(n-1) represents the possible ways to partition the array into two non-empty groups
        int ans = (1 << (n-1)) % mod;  // Using modulo to avoid overflow
        
        // Subtract 1 to ensure that we only count valid partitions
        return ans - 1;
    }
};
