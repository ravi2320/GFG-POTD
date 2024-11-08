/*
Prime Factorization using Sieve
Difficulty: MediumAccuracy: 47.01%Submissions: 20K+Points: 4
You are given a positive number N. Using the concept of Sieve, compute its prime factorisation.

Example:

Input: 
N = 12246
Output: 
2 3 13 157
Explanation: 
2*3*13*157 = 12246 = N.
Your Task:

Comple the function findPrimeFactors(), which takes a positive number N as input and returns a vector consisting of prime factors. You should implement Sieve algorithm to solve this problem.

 

Expected Time Complexity: O(Nlog(log(N)).

Expected Auxiliary Space: O(N).

Constraints:

2<=N<=2*105
*/

/*
Approach:
1. Create a sieve array to store the smallest prime factor (SPF) for each number up to `N`.
   - Initialize `seive[i]` as `i` for each index.
2. For each integer `i` from `2` to `sqrt(N)`, mark multiples of `i` with `i` as their smallest prime factor.
3. Using the sieve array, find the prime factors of `N`:
   - Divide `N` by its smallest prime factor repeatedly and add each prime factor to the result vector until `N` becomes `1`.

Time Complexity: O(N * log(log(N))) for constructing the sieve and O(log(N)) for finding prime factors.
Space Complexity: O(N), for the sieve array.

*/

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {
        // Initialize sieve array
        vector<int> seive(N + 1);
        for (int i = 0; i <= N; i++) {
            seive[i] = i;
        }

        // Construct sieve with smallest prime factors
        for (int i = 2; i * i <= N; i++) {
            if (seive[i] == i) {  // `i` is prime
                for (int j = i * i; j <= N; j += i) {
                    if (seive[j] == j) {
                        seive[j] = i;
                    }
                }
            }
        }

        // Retrieve prime factors of N using sieve
        vector<int> res;
        while (N != 1) {
            res.push_back(seive[N]);
            N /= seive[N];
        }

        return res;
    }
};
