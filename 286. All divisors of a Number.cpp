/*
All divisors of a Number
Difficulty: EasyAccuracy: 46.73%Submissions: 38K+Points: 2
Given an integer N, print all the divisors of N in the ascending order.
 

Example 1:

Input : 20
Output: 1 2 4 5 10 20
Explanation: 20 is completely 
divisible by 1, 2, 4, 5, 10 and 20.

Example 2:

Input: 21191
Output: 1 21191
Explanation: As 21191 is a prime number,
it has only 2 factors(1 and the number itself).

Your Task:

Your task is to complete the function print_divisors() which takes N as input parameter and prints all the factors of N as space seperated integers in sorted order. You don't have to print any new line after printing the desired output. It will be handled in driver code.
 

Expected Time Complexity: O(sqrt(N))
Expected Space Complexity: O(sqrt(N))
 

Constraints:
1 <= N <= 105
*/

/*
Approach:
1. We loop from 1 up to √n to find all divisors.
2. For each integer i, if it divides n (i.e., n % i == 0), we add i as a divisor.
3. Additionally, we add n/i as a divisor if it's distinct from i to avoid duplicates (e.g., in case of perfect squares).
4. After collecting divisors, we sort them to ensure they are in ascending order.
5. Finally, we print each divisor.

Time Complexity: O(√N log(√N)) - O(√N) for finding divisors, and O(log(√N)) for sorting the divisor list.
Space Complexity: O(D) where D is the number of divisors.

*/

class Solution {
public:
    void print_divisors(int n) {
        vector<int> arr;

        // Finding divisors up to the square root of n
        for(int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                arr.push_back(i);
                if (n / i != i) {
                    arr.push_back(n / i);
                }
            }
        }

        // Sorting divisors in ascending order
        sort(arr.begin(), arr.end());

        // Printing divisors
        for (int &num : arr) {
            cout << num << " ";
        }
    }
};
