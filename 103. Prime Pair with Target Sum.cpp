/*
Prime Pair with Target Sum
MediumAccuracy: 27.67%Submissions: 33K+Points: 4
Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
Daily rewards up for grabs!

banner
Given a number n, find out if n can be expressed as a+b, where both a and b are prime numbers. If such a pair exists, return the values of a and b, otherwise return [-1,-1] as an array of size 2.
Note: If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, and a < c then  [a, b] is considered as our answer.

Examples

Input: n = 10
Output: 3 7
Explanation: There are two possiblities 3, 7 & 5, 5 are both prime & their sum is 10, but we'll pick 3, 7 as 3 < 5.
Input: n = 3
Output: -1 -1
Explanation: There are no solutions to the number 3.
Expected Time Complexity: O(n*loglog(n))
Expected Auxiliary Space: O(n)

Constraints:
2 <= n <= 106
*/

/*
Intuition:
- This problem requires finding two prime numbers that sum up to a given number `n`. This is similar to Goldbach's conjecture, which states that every even integer greater than 2 can be expressed as the sum of two primes.
- We use the Sieve of Eratosthenes to efficiently find all prime numbers up to `n`. Then, we check pairs of prime numbers to see if they sum up to `n`.

Approach:
1. Use the Sieve of Eratosthenes to generate a list of prime numbers up to `n`.
2. Iterate through the list of prime numbers, and for each prime number `i`, check if `n-i` is also a prime number.
3. If such a pair is found, return the pair. If no pair is found, return {-1, -1}.

Time Complexity:
- O(n log log n) for the Sieve of Eratosthenes.
- O(n) for the pair-checking loop.

Space Complexity:
- O(n) for storing the sieve.

*/

class Solution {
public:
    vector<int> getPrimes(int n) {
        // Create a sieve to mark prime numbers
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false; // 0 and 1 are not primes

        // Sieve of Eratosthenes
        for (int i = 2; i * i <= n; ++i) {
            if (sieve[i]) {
                for (int j = i * i; j <= n; j += i) {
                    sieve[j] = false;
                }
            }
        }

        // Check for pairs of primes that sum to n
        for (int i = 2; i <= n; ++i) {
            if (sieve[i] && sieve[n - i]) {
                return {i, n - i};
            }
        }

        // If no pair found, return {-1, -1}
        return {-1, -1};
    }
};
