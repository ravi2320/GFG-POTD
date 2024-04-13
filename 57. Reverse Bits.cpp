/*
Reverse Bits
EasyAccuracy: 53.96%Submissions: 56K+Points: 2
Given a number x, reverse its binary form and return the answer in decimal.

Example 1:

Input:
x = 1
Output:
2147483648 
Explanation:
Binary of 1 in 32 bits representation-
00000000000000000000000000000001
Reversing the binary form we get, 
10000000000000000000000000000000,
whose decimal value is 2147483648.
Example 2:

Input:
x = 5
Output:
2684354560 
Explanation:
Binary of 5 in 32 bits representation-
00000000000000000000000000000101
Reversing the binary form we get, 
10100000000000000000000000000000,
whose decimal value is 2684354560.
Your Task:
You don't need to read input or print anything. Your task is to complete the function reversedBits() which takes an Integer x as input and returns the reverse binary form of x in decimal form.

Expected Time Complexity: O(log (x))
Expected Auxiliary Space: O(1)

Constraints:
0  <=  x  <  232
*/

/*
Intuition:
- We iterate through each bit of the input number from the least significant bit (LSB) to the most significant bit (MSB).
- For each bit position, we extract the corresponding bit of the input number and multiply it by 2 raised to the power of the current position.
- We accumulate these values to get the reversed bits representation.

Time Complexity: O(log x)
- The time complexity is proportional to the number of bits in the input number x.

Space Complexity: O(1)
- We use only a constant amount of extra space.
*/

class Solution {
public:
    long long reversedBits(long long x) {
        long long i = 31, ans = 0;
        
        while(x){
            ans += (long long)pow(2, i) * (x & 1);
            i--;
            x >>= 1;
        }
        
        return ans;
    }
};
