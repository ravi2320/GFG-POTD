/*
Armstrong Numbers
EasyAccuracy: 49.88%Submissions: 118K+Points: 2
Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
Daily rewards up for grabs!

banner
You are given a 3-digit number n, Find whether it is an Armstrong number or not.

An Armstrong number of three digits is a number such that the sum of the cubes of its digits is equal to the number itself. 371 is an Armstrong number since 33 + 73 + 13 = 371.

Note: Return "Yes" if it is an Armstrong number else return "No".

Examples

Input: n = 153
Output: Yes
Explanation: 153 is an Armstrong number since 13 + 53 + 33 = 153. Hence answer is "Yes".
Input: n = 372
Output: No
Explanation: 372 is not an Armstrong number since 33 + 73 + 23 = 378. Hence answer is "No".
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
100 ≤ n <1000
*/

/*
Intuition:
- An Armstrong number (also known as a narcissistic number) for a 3-digit number is one where the sum of the cubes of its digits equals the number itself.
- We can determine if a number is an Armstrong number by extracting each digit, cubing it, summing these cubes, and comparing the result to the original number.

Approach:
1. Initialize a temporary variable to store the original number.
2. Extract each digit of the number by taking the remainder when divided by 10.
3. Cube the extracted digit and add it to an accumulator variable.
4. Repeat until all digits have been processed.
5. Compare the accumulated sum to the original number and return "Yes" if they are equal, otherwise return "No".

Time Complexity:
- O(log(n)), where n is the input number. Since the number of digits in n is log10(n), the loop runs for log10(n) iterations.

Space Complexity:
- O(1), since we are using a fixed amount of extra space.

*/

class Solution {
  public:
    string armstrongNumber(int n){
        int temp = n;
        int sumOfCubes = 0;
        
        while(n > 0){
            int digit = n % 10;
            sumOfCubes += (digit * digit * digit);
            n /= 10;
        }
        
        return sumOfCubes == temp ? "Yes" : "No";
    }
};
