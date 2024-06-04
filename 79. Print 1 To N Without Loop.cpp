/*
Print 1 To N Without Loop
SchoolAccuracy: 61.33%Submissions: 175K+Points: 0
Get Internship at GfG by submitting your Entries in: Data Science Blogathon

banner
Print numbers from 1 to N without the help of loops.

Example 1:

Input:
N = 10
Output: 1 2 3 4 5 6 7 8 9 10

Example 2:

Input:
N = 5
Output: 1 2 3 4 5
 

Your Task:
This is a function problem. You only need to complete the function printNos() that takes N as parameter and prints number from 1 to N recursively. Don't print newline, it will be added by the driver code.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N) (Recursive).


Constraints:
1 <= N <= 1000
*/

// Intuition:
// - The task is to print numbers from 1 to N using recursion.
// - The base case for the recursion will be when N is greater than 1, decrementing by 1 each call until it reaches 1.
// - After the recursive call, the number N is printed. This ensures that numbers are printed in ascending order.

// Approach:
// - The function `printNos` is called recursively, decrementing N by 1 each time.
// - Once N reaches 1, it stops decrementing and starts printing numbers in reverse order of the calls, resulting in ascending order print.

// Time Complexity: O(N)
// - The function calls itself N times, where N is the input number.

// Space Complexity: O(N)
// - The recursion depth is N, which corresponds to the maximum depth of the call stack.

class Solution {
public:
    // Function to print numbers from 1 to N using recursion
    void printNos(int N) {
        if (N > 1) {
            printNos(N - 1);  // Recursive call with N-1
        }
        cout << N << " ";  // Print the number after the recursive call
    }
};
