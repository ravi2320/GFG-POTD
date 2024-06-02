/*
Construct list using given q XOR queries
MediumAccuracy: 50.86%Submissions: 24K+Points: 4
In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

banner
Given a list s that initially contains only a single value 0. There will be q queries of the following types:

0 x: Insert x in the list
1 x: For every element a in s, replace it with a ^ x. ('^' denotes the bitwise XOR operator)
Return the sorted list after performing the given q queries.

Example 1:

Input:
q = 5
queries[] = {{0, 6}, {0, 3}, {0, 2}, {1, 4}, {1, 5}}
Output:
1 2 3 7
Explanation:
[0] (initial value)
[0 6] (add 6 to list)
[0 6 3] (add 3 to list)
[0 6 3 2] (add 2 to list)
[4 2 7 6] (XOR each element by 4)
[1 7 2 3] (XOR each element by 5)
The sorted list after performing all the queries is [1 2 3 7]. 
Example 2:
Input:
q = 3
queries[] = {{0, 2}, {1, 3}, {0, 5}} 
Output :
1 3 5
Explanation:
[0] (initial value)
[0 2] (add 2 to list)
[3 1] (XOR each element by 3)
[3 1 5] (add 5 to list)
The sorted list after performing all the queries is [1 3 5].

Your Task:  
You don't need to read input or print anything. Your task is to complete the function constructList() which takes an integer q the number of queries and queries[] a list of lists of length 2 denoting the queries as input parameters and returns the final constructed list.


Expected Time Complexity: O(q*log(q))
Expected Auxiliary Space: O(l), where l is only used for output-specific requirements.


Constraints:
1 ≤ q ≤ 105
*/

// Intuition:
// - The goal is to process a list of queries to construct a resulting list of integers.
// - Each query is either of the form (1, v) which indicates a value `v` to XOR with a running variable `x`, or (0, v) which indicates that `v` should be added to the result after being XOR'd with `x`.
// - The final value of `x` is also added to the result list at the end.
// - We process the queries in reverse order to correctly handle the cumulative effect of the XOR operations on `x`.

// Time Complexity: O(Q log Q)
// - We iterate through the queries once which takes O(Q) time.
// - Sorting the result list at the end takes O(Q log Q) time where Q is the number of queries.

// Space Complexity: O(Q)
// - We use additional space to store the result list which can be at most of size Q.

class Solution {
public:
    vector<int> constructList(int q, vector<vector<int>>& queries) {
        vector<int> ans;
        int x = 0;
        
        // Process the queries in reverse order
        for (int i = q - 1; i >= 0; i--) {
            if (queries[i][0] == 1) {
                // XOR operation with x
                x ^= queries[i][1];
            } else {
                // Add the value to the result list after XOR with x
                ans.push_back(queries[i][1] ^ x);
            }
        }
        
        // Add the final value of x to the result list
        ans.push_back(x);
        
        // Sort the result list
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
