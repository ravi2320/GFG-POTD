/*
Count numbers containing 4
EasyAccuracy: 37.85%Submissions: 31K+Points: 2
Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
Daily rewards up for grabs!

banner
You are given a number n, Return the count of total numbers from 1 to n containing 4 as a digit.

Examples:

Input: n = 9
Output: 1
Explanation: 4 is the only number between 1 to 9 which contains 4 as a digit.
Input: n = 44
Output: 9
Explanation: 4, 14, 24, 34, 40, 41, 42, 43 & 44, there are total 9 numbers containing 4 as a digit.
Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 105
*/

/*
Intuition:
- The problem is to count how many numbers between 1 and `n` contain the digit '4'.
- We can solve this problem by iterating through all numbers from 1 to `n` and checking if they contain the digit '4'.

Approach:
1. Iterate through all numbers from 1 to `n`.
2. For each number, check its digits to see if any digit is '4'.
3. If a number contains the digit '4', increment the count.
4. Return the count after checking all numbers.

Time Complexity:
- O(n * d), where n is the number of integers to check and d is the average number of digits in those integers.

Space Complexity:
- O(1), as we use a constant amount of extra space.

*/

class Solution {
public:
    int countNumberswith4(int n) {
        int cnt = 0;
        for(int i = 4; i <= n; i++) {
            int j = i;
            while(j > 0) {
                if(j % 10 == 4) {
                    cnt++;
                    break;
                }
                j /= 10;
            }
        }
        return cnt;
    }
};
