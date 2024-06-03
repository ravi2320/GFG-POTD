/*
Count Digits
EasyAccuracy: 30.45%Submissions: 165K+Points: 2
Get Internship at GfG by submitting your Entries in: Data Science Blogathon

banner
Given a number N. Count the number of digits in N which evenly divide N.

Note :- Evenly divides means whether N is divisible by a digit i.e. leaves a remainder 0 when divided.
 

Example 1:

Input:
N = 12
Output:
2
Explanation:
1, 2 both divide 12 evenly
Example 2:

Input:
N = 23
Output
0
Explanation:
2 and 3, none of them
divide 23 evenly

Your Task:
You don't need to read input or print anything. Your task is to complete the function evenlyDivides() which takes an integer N as input parameters and returns an integer, total number factor of digits N which divides N evenly.


Expected Time Complexity: O(log N)
Expected Space Complexity: O(1)
 

Constraints:
1<=N<=105
*/

// Intuition:
// - The problem requires counting the number of digits in `N` that evenly divide `N`.
// - We can extract each digit of `N` by repeatedly taking the remainder when divided by 10.
// - For each non-zero digit, check if it evenly divides `N` and count it if it does.

// Time Complexity: O(d)
// - The algorithm processes each digit of `N`, where `d` is the number of digits in `N`.

// Space Complexity: O(1)
// - The algorithm uses a constant amount of extra space.

class Solution{
public:
    int evenlyDivides(int N) {
        // Initialize count of divisible digits to 0
        int cnt = 0;
        // Make a copy of N to work with
        int n = N;

        // Loop through each digit of n
        while (n > 0) {
            // Get the last digit
            int rem = n % 10;

            // Check if the digit is non-zero and divides N evenly
            if (rem != 0 && N % rem == 0) {
                cnt += 1;
            }

            // Remove the last digit
            n /= 10;
        }

        // Return the count of divisible digits
        return cnt;
    }
};
