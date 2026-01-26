/*
Generate Permutations of an array

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 85.48%Submissions: 4K+Points: 4
Given an array arr[] of unique elements. Generate all possible permutations of the elements in the array.
Note: You can return the permutations in any order, the driver code will print them in sorted order.

Examples:

Input: arr[] = [1, 2, 3]
Output: [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
Explanation: There are 6 possible permutations (3! = 6) of the array.
Input: arr[] = [1, 3]
Output: [[1, 3], [3, 1]]
Explanation: There are 2 possible permutations (2! = 2) of the array.
Constraints:
1 ≤ arr.size() ≤ 9
*/

/*
Approach:
---------
1. Use backtracking to generate all permutations.
2. Maintain:
   - `temp` → current permutation being formed
   - `visited` → marks which elements are already used
3. At each recursion level:
   - Try every unused element
   - Mark it visited, add to temp
   - Recurse further
   - Backtrack by unmarking and removing the element
4. When temp size equals n, store the permutation.

Intuition:
----------
Permutation means arranging all elements in every possible order.
Backtracking explores all choices level by level while ensuring
each element is used exactly once per permutation.
The visited array prevents reuse of the same element.

Time Complexity:
----------------
O(n × n!)
- There are n! permutations
- Each permutation takes O(n) time to construct

Space Complexity:
-----------------
O(n)
- Recursion stack + visited + temp arrays
- Output space is O(n × n!)
*/

class Solution {
    vector<vector<int>> ans;
    int n;

public:
    void solve(vector<int> &arr, vector<int> &temp, vector<bool> &visited) {
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                temp.push_back(arr[i]);
                visited[i] = true;

                solve(arr, temp, visited);

                // Backtrack
                temp.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permuteDist(vector<int>& arr) {
        n = arr.size();
        vector<bool> visited(n, false);
        vector<int> temp;

        solve(arr, temp, visited);

        return ans;
    }
};
