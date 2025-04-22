/*
Unique Number I
Difficulty: EasyAccuracy: 66.09%Submissions: 10K+Points: 2
Given a unsorted array arr[] of positive integers having all the numbers occurring exactly twice, except for one number which will occur only once. Find the number occurring only once.

Examples :

Input: arr[] = [1, 2, 1, 5, 5]
Output: 2
Explanation: Since 2 occurs once, while other numbers occur twice, 2 is the answer.
Input: arr[] = [2, 30, 2, 15, 20, 30, 15]
Output: 20
Explanation: Since 20 occurs once, while other numbers occur twice, 20 is the answer.
Constraints
1 ≤  arr.size()  ≤ 106
0 ≤ arr[i] ≤ 109
*/

/*
Intuition:
If every number appears twice **except one unique number**, we can find that number using XOR.
Why?
- x ^ x = 0 (any number XOR with itself is 0)
- x ^ 0 = x (any number XOR with 0 stays unchanged)
- XOR is both commutative and associative, so the order doesn’t matter.

Approach:
1. Initialize a result variable as 0.
2. XOR every element in the array with `res`.
3. At the end, all duplicates cancel out (since x ^ x = 0) and we are left with the unique number.

Time Complexity: O(N)
- We traverse the array once.

Space Complexity: O(1)
- Only a single integer is used for tracking the result.
*/

class Solution {
  public:
    int findUnique(vector<int> &arr) {
        int res = 0;
        
        for(int &x : arr){
            res ^= x;  // XOR to cancel out duplicates
        }
        
        return res;
    }
};
