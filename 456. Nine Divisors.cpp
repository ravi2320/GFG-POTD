/*
Nine Divisors
Difficulty: MediumAccuracy: 35.58%Submissions: 23K+Points: 4
Given a positive integer n, you need to count the numbers less than or equal to n having exactly 9 divisors.

Examples :

Input: n = 100
Output: 2
Explanation: Numbers which have exactly 9 divisors are 36 and 100.
Input: n = 200
Output: 3
Explanation: Numbers which have exactly 9 divisors are 36, 100, 196. 
Constraints:
1 ≤ n ≤ 109
*/

/*
Approach:
1. Generate all prime numbers up to √n using the Sieve of Eratosthenes.
2. Count:
   a) Numbers of the form p⁸ ≤ n (where p is a prime).
   b) Numbers of the form p² * q² ≤ n, with p ≠ q (distinct primes).

Intuition:
- These numbers have exactly 4 positive divisors.
- p⁸ → has divisors: 1, p², p⁴, p⁸ (4 in total)
- p² * q² → has divisors: (2+1)*(2+1) = 9 → 9 divisors? NO!
  Wait: actually, p² * q² = (exponents 2+1)(2+1) = 9 divisors — not valid
  So it's incorrect!

Correct 4-divisor forms:
- p³ (1, p, p², p³) → 4 divisors
- p * q (1, p, q, pq) → 4 divisors
So the valid numbers:
1. p³ where p is prime and p³ ≤ n
2. p * q where p and q are distinct primes and p*q ≤ n

We correct the original logic to compute both these forms properly.

Time Complexity:
- O(n^0.5 log log n) for sieve
- O(p^2) for pairwise combinations of primes

Space Complexity: O(n^0.5) for sieve storage
*/

class Solution {
public:
    int countNumbers(int n) {
        int k = sqrt(n);
        vector<bool> sieve(k + 1, true);

        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= k; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= k; j += i) {
                    sieve[j] = false;
                }
            }
        }

        // Collect all primes ≤ √n
        vector<int> primes;
        for (int i = 2; i <= k; i++) {
            if (sieve[i]) primes.push_back(i);
        }

        int cnt = 0;

        // Count numbers of the form p^3 ≤ n
        for (int p : primes) {
            long long cube = 1LL * p * p * p;
            if (cube <= n) cnt++;
        }

        // Count numbers of the form p * q ≤ n where p < q
        int sz = primes.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                long long product = 1LL * primes[i] * primes[j];
                if (product <= n) {
                    cnt++;
                } else {
                    break; // further primes will only increase the product
                }
            }
        }

        return cnt;
    }
};