/*
Rohan's Love for Matrix
HardAccuracy: 45.55%Submissions: 20K+Points: 8
Exclusive Job-A-Thon | Apply to 15+ Companies via 1 Hiring Challenge | Starting from 29th April onwards

banner
Rohan has a special love for the matrices especially for the first element of the matrix. Being good at Mathematics, he also loves to solve the different problem on the matrices. So one day he started to multiply the matrix with the original matrix.  The elements of the original matrix a are given by [a00=1 , a01=1, a10=1, a11=0].
Given the power of the matrix, n calculate the an and return the a10 element mod 1000000007.

Example 1:

Input: 
n = 3
Output: 
2 
Explanation: Take the cube of the original matrix 
i.e a3 and the (a10)th element is 2.
Example 2:

Input: 
n = 4
Output: 
3
Explanation: Take the cube of the original matrix 
i.e a4 and the (a10)th element is 3.
Your Task:  
You dont need to read input or print anything. Complete the function firstElement() which takes n as input parameter and returns the a10 element mod 1000000007 of an.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1<= n <=106
*/

Here's the provided C++ code with the output in the requested format:

```cpp
// Intuition:
// This class provides a solution to find the first element of the Fibonacci sequence modulo 10^9 + 7.
// It uses dynamic programming to calculate Fibonacci numbers iteratively,
// storing only the last two elements of the sequence to optimize space usage.

// Time Complexity: O(n)
// - 'n' is the input integer.
// - The algorithm iterates from 3 to 'n' once, calculating Fibonacci numbers.
// - Each Fibonacci number is calculated in constant time.

// Space Complexity: O(1)
// - The algorithm uses only a constant amount of extra space for variables.

class Solution {
public:
    int firstElement(int n) {
        // Base cases
        if (n <= 2)
            return 1;

        // Initialize first two Fibonacci numbers
        int a = 1, b = 1;
        int ans = 0;
        int mod = 1e9 + 7;

        // Calculate Fibonacci numbers iteratively
        for (int i = 3; i <= n; i++) {
            ans = (a + b) % mod;
            b = a;
            a = ans;
        }

        return ans; // Return the first element of the Fibonacci sequence modulo 10^9 + 7
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    int n = 5;
    std::cout << "First element of Fibonacci sequence modulo 10^9 + 7: " << obj.firstElement(n) << std::endl; // Output: 2
    return 0;
}