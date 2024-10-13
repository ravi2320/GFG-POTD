/*
Subset Sums
Difficulty: MediumAccuracy: 72.55%Submissions: 133K+Points: 4
Given a list arr of n integers, return sums of all subsets in it. Output sums can be printed in any order.

Examples:

Input: n = 2, arr[] = {2, 3}
Output: 0 2 3 5
Explanation: When no elements is taken then Sum = 0. When only 2 is taken then Sum = 2. When only 3 is taken then Sum = 3. When element 2 and 3 are taken then Sum = 2+3 = 5.
Example 2:

Input: n = 3, arr = {1, 2, 1}
Output: 0 1 1 2 2 3 3 4
 
Your Task:  
You don't need to read input or print anything. Your task is to complete the function subsetSums() which takes a list/vector and an integer n as an input parameter and returns the list/vector of all the subset sums.

Expected Time Complexity: O(2n)
Expected Auxiliary Space: O(2n)

Constraints:
1 <= n <= 15
0 <= arr[i] <= 104

*/

/*
Approach:
1. Recursively generate all subset sums.
2. For each element, either include it in the current sum or exclude it.
3. Store the subset sums in the result vector.

Time Complexity: O(2^n), since we generate all subsets of the array (2^n subsets).
Space Complexity: O(2^n), for storing the results and recursion stack.
*/

class Solution {
  public:
    // Recursive function to calculate all subset sums
    void solve(int i, int sum, vector<int> &arr, vector<int> &res, int n) {
        // Base case: if we've considered all elements, store the sum
        if(i == n) {
            res.push_back(sum);  // Add the current sum to the result
            return;
        }
        
        // Recursive call excluding the current element from the subset
        solve(i + 1, sum, arr, res, n);
        
        // Recursive call including the current element in the subset
        solve(i + 1, sum + arr[i], arr, res, n);
    }

    // Function to return all subset sums
    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int> res;  // To store the subset sums
        solve(0, 0, arr, res, n);  // Start recursion from the first element
        return res;
    }
};
