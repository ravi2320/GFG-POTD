/*
Single Number
Difficulty: EasyAccuracy: 41.64%Submissions: 43K+Points: 2
Given an array arr[] of positive integers where every element appears even times except for one. Find that number occurring an odd number of times.

Examples:

Input: arr[] = [1, 1, 2, 2, 2]
Output: 2
Explanation: In the given array all element appear two times except 2 which appears thrice.
Input: arr[] = [8, 8, 7, 7, 6, 6, 1]
Output: 1
Explanation: In the given array all element appear two times except 1 which appears once.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arri ≤ 105
*/

/*
Approach:
- The problem is to find the element that appears exactly once in an array where every other element appears twice.
- We use the XOR operation (`^`) to solve this problem efficiently:
  - XOR of two identical numbers is 0, i.e., `a ^ a = 0`.
  - XOR of a number with 0 is the number itself, i.e., `a ^ 0 = a`.
  - Therefore, when we XOR all the numbers in the array, all elements that appear twice will cancel out, and we will be left with the element that appears only once.
  
Time Complexity:
- O(n), where `n` is the size of the array. We iterate through the array once.

Space Complexity:
- O(1), as we are only using a constant amount of extra space (the `Xor` variable).

*/

class Solution {
public:
    // Function to return the single occurring element in the array
    int getSingle(vector<int>& arr) {
        int Xor = 0;  // Initialize a variable to store the XOR result
        
        // XOR all elements in the array
        for (int &x : arr) {
            Xor ^= x;  // XOR each element with the current result
        }
        
        return Xor;  // The result will be the element that appears once
    }
};