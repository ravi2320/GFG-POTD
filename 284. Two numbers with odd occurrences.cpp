/*
Two numbers with odd occurrences
Difficulty: MediumAccuracy: 49.49%Submissions: 61K+Points: 4
Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

Example 1:

Input:
N = 8
Arr = {4, 2, 4, 5, 2, 3, 3, 1}
Output: {5, 1} 
Explanation: 5 and 1 have odd occurrences.

Example 2:

Input:
N = 8
Arr = {1 7 5 7 5 4 7 4}
Output: {7, 1}
Explanation: 7 and 1 have odd occurrences.

Your Task:
You don't need to read input or print anything. Your task is to complete the function twoOddNum() which takes the array Arr[] and its size N as input parameters and returns the two numbers in decreasing order which have odd occurrences.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)


Constraints:
2 ≤ N ≤ 106
1 ≤ Arri ≤ 1012
*/

/*
Approach:
1. First, XOR all elements of the array. Since XOR of two identical numbers is 0, XORing all elements will yield the XOR of the two odd-occurring numbers (as all even-occurring numbers will cancel out).
2. Find the rightmost set bit in the XOR result. This bit is set in one of the odd-occurring numbers but not the other.
3. Use this set bit to divide the array into two groups:
   - One group with this bit set.
   - Another group with this bit not set.
4. XOR all elements within each group to isolate the two odd-occurring numbers.
5. Finally, sort the result to return the numbers in descending order.

Time Complexity: O(N), where N is the number of elements in the array.
Space Complexity: O(1) for auxiliary space.

*/

class Solution {
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        // XOR all elements to get xor of the two odd-occurring numbers
        long long int xor_res = 0;
        for(int i = 0; i < N; i++) {
            xor_res ^= Arr[i];
        }
        
        // Find the rightmost set bit in xor_res
        long long int set_bit = xor_res & ~(xor_res - 1);
        
        // Initialize two results
        long long int res1 = 0, res2 = 0;
        
        // Separate elements based on the rightmost set bit
        for(int i = 0; i < N; i++) {
            if(Arr[i] & set_bit) {
                res1 ^= Arr[i]; // XOR elements with the bit set
            } else {
                res2 ^= Arr[i]; // XOR elements without the bit set
            }
        }
        
        // Return the results in descending order
        if(res1 > res2) return {res1, res2};
        return {res2, res1};
    }
};
