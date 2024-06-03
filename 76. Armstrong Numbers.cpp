/*
Armstrong Numbers
EasyAccuracy: 49.88%Submissions: 113K+Points: 2
Get Internship at GfG by submitting your Entries in: Data Science Blogathon

banner
For a given 3-digit number n, find whether it is an Armstrong number. 

An Armstrong number of three digits is a number such that the sum of the cubes of its digits is equal to the number itself. Return "Yes" if it is an Armstrong number else return "No".
NOTE: 371 is an Armstrong number since 33 + 73 + 13 = 371

Example 1:

Input: 
n = 153
Output: 
Yes
Explanation: 
153 is an Armstrong number since 13 + 53 + 33 = 153. Hence answer is "Yes".
Example 2:

Input: 
n = 372
Output: 
No
Explanation: 
372 is not an Armstrong number since 33 + 73 + 23 = 378. Hence answer is "No".
Your Task:  
You don't need to read input or print anything. Complete the function armstrongNumber() which takes n as the input parameter and returns "Yes" if it is an Armstrong number else returns "No".

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
100 ≤ n <1000
*/

// Intuition:
// - An Armstrong number (also known as a narcissistic number) is a number that is equal to the sum of its own digits each raised to the power of the number of digits.
// - For a 3-digit number, we check if the number equals the sum of the cubes of its digits.
// - We extract each digit of the number using the modulus operator and compute the sum of their cubes.
// - Finally, we compare this sum with the original number to determine if it is an Armstrong number.

// Time Complexity: O(d)
// - The algorithm processes each digit of `n`, where `d` is the number of digits in `n`.

// Space Complexity: O(1)
// - The algorithm uses a constant amount of extra space.

class Solution {
  public:
    string armstrongNumber(int n) {
        // Initialize sum to 0 to calculate the sum of cubes of digits
        int sum = 0;
        // Store the original number in a temporary variable
        int temp = n;

        // Loop through each digit of the number
        while (n > 0) {
            // Extract the last digit
            int LD = n % 10;
            
            // Add the cube of the last digit to sum
            sum += (LD * LD * LD);
            
            // Remove the last digit
            n /= 10;
        }

        // Check if the sum of cubes of digits equals the original number
        // Return "Yes" if it matches, otherwise "No"
        return temp == sum ? "Yes" : "No";
    }
};
