/*
Remove duplicates in array
Difficulty: EasyAccuracy: 35.86%Submissions: 50K+Points: 2
Given an array arr consisting of positive integer numbers, remove all duplicate numbers.

Example:

Input: arr[] = [2, 2, 3, 3, 7, 5] 
Output: [2, 3, 7, 5]
Explanation: After removing the duplicates 2 and 3 we get 2 3 7 5.
Input: arr[] = [2, 2, 5, 5, 7, 7] 
Output: [2, 5, 7]
Input: arr[] = [8, 7] 
Output: [8, 7]
Constraints:
1<= arr.size() <=106
2<= arr[i] <=100
*/

/*
Approach:
1. Use a vector `dp` of size 101 (to cover elements from 0 to 100) to mark the presence of each unique element in `arr`.
2. Traverse the input array `arr`:
   - For each element `x`, set `dp[x]` to 1 to mark its presence.
3. In a second traversal, check for unique elements in `arr`:
   - If `dp[x]` is 1, it indicates that `x` has not yet been added to the result.
   - Add `x` to `res` and reset `dp[x]` to 0 to avoid duplicates in `res`.
4. Return the resulting vector `res` containing unique elements in the same order as they appear in `arr`.

Time Complexity: O(n), where `n` is the number of elements in `arr`.
Space Complexity: O(1), since `dp` size is fixed at 101 regardless of `arr` size.

*/

class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        vector<int> dp(101, 0);  // Track occurrence of elements (0 to 100)
        
        for(int &x : arr){
            dp[x] = 1;  // Mark presence of each element
        }
        
        vector<int> res;  // Resultant vector to store unique elements
        for(int &x : arr){
            if(dp[x]){  // If element is marked, add to result
                res.push_back(x);
                dp[x] = 0;  // Reset to prevent duplicates
            }
        }
        
        return res;
    }
};
