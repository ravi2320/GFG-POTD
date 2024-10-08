/*
Generate all binary strings
Difficulty: MediumAccuracy: 65.8%Submissions: 12K+Points: 4
Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.

A binary string is that string which contains only 0 and 1.

Example 1:

Input:
N = 3
Output:
000 , 001 , 010 , 100 , 101
Explanation:
None of the above strings contain consecutive 1s. "110" is not an answer as it has '1's occuring consecutively. 
Your Task:

You don't need to read input or print anything. Your task is to complete the function generateBinaryStrings() which takes an integer N as input and returns a list of all valid binary strings in lexicographically increasing order.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 20
*/

/*
Approach:
1. **Recursion**:
   - We build the binary strings character by character, using backtracking.
   - We keep track of the current string (`curr`) and the current index (`i`).
   - At each step, we either append '0' or '1' to the current string if the condition is met (i.e., no two consecutive '1's).
   
2. **Base Case**:
   - Once we've built a string of length `num`, we add it to the result.

3. **Recursive Case**:
   - If the previous character is '0', we can add either '0' or '1'.
   - If the previous character is '1', we can only add '0' (to avoid two consecutive '1's).
   
4. **Time Complexity**:
   - **O(2^n)**: Since we explore all possible combinations of binary strings of length `num`, the time complexity is exponential.

5. **Space Complexity**:
   - **O(n)**: The recursion depth and the size of the temporary string are proportional to the length `num`.

*/

class Solution{
    vector<string> res;  // Store all the valid binary strings
public:
    // Helper function to generate the binary strings
    void solve(string &curr, int i, int n){
        // Base case: if the current string reaches the required length
        if(i == n){
            res.push_back(curr);
            return;
        }
        
        // If the previous character is '0', we can add '1'
        if(curr[i-1] == '0'){
            curr.push_back('1');
            solve(curr, i+1, n);
            curr.pop_back();  // Backtrack to explore other possibilities
        }
        
        // We can always add '0' regardless of the previous character
        curr.push_back('0');
        solve(curr, i+1, n);
        curr.pop_back();  // Backtrack to explore other possibilities
    }

    // Function to initiate the generation of binary strings
    vector<string> generateBinaryStrings(int num){
        // Start with '0'
        string curr = "0";
        solve(curr, 1, num);  // Start recursion from index 1
        
        // Start with '1'
        curr = "1";
        solve(curr, 1, num);  // Start recursion from index 1
        
        // Sort the result in lexicographical order
        sort(res.begin(), res.end());
        
        return res;  // Return the result containing all valid binary strings
    }
};
