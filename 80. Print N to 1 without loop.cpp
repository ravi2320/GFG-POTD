/*
Print N to 1 without loop
EasyAccuracy: 77.72%Submissions: 35K+Points: 2
Get Internship at GfG by submitting your Entries in: Data Science Blogathon

banner
Print numbers from N to 1 (space separated) without the help of loops.

Example 1:

Input:
N = 10
Output: 10 9 8 7 6 5 4 3 2 1
Your Task:
This is a function problem. You only need to complete the function printNos() that takes N as parameter and prints number from N to 1 recursively. Don't print newline, it will be added by the driver code.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N) (Recursive).

Constraint
1<=n<=1000
*/

// Intuition:
// - The task is to print numbers from N to 1 using recursion.
// - The base case for the recursion will be when N is 0, at which point the recursion stops.
// - Each recursive call prints the current value of N before making the next call with N-1.

// Approach:
// - The function `printNos` is called recursively, decrementing N by 1 each time.
// - The number N is printed before the recursive call, which ensures that numbers are printed in descending order.

// Time Complexity: O(N)
// - The function calls itself N times, where N is the input number.

// Space Complexity: O(N)
// - The recursion depth is N, which corresponds to the maximum depth of the call stack.

class Solution {
public:
    // Function to print numbers from N to 1 using recursion
    void printNos(int N) {
        if (N == 0) {
            return;  // Base case: if N is 0, stop recursion
        }
        
        cout << N << " ";  // Print the current number
        printNos(N - 1);   // Recursive call with N-1
    }
};
