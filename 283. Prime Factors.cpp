/*
Prime Factors
Difficulty: EasyAccuracy: 30.47%Submissions: 46K+Points: 2
Given a number N. Find its unique prime factors in increasing order.
 

Example 1:

Input: N = 100
Output: 2 5
Explanation: 2 and 5 are the unique prime
factors of 100.
Example 2:

Input: N = 35
Output: 5 7
Explanation: 5 and 7 are the unique prime
factors of 35.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function AllPrimeFactors() which takes N as input parameter and returns a list of all unique prime factors of N in increasing order.

 

Expected Time Complexity: O(N)
Expected Space Complexity: O(N)
 

Constraints:
1 <= N  <= 106
*/

/*
Approach:
1. We need to find all unique prime factors of `N`.
2. We use the Sieve of Eratosthenes to create a boolean sieve array where `seive[i]` is `true` if `i` is a prime.
3. We iterate through numbers up to `sqrt(N)` to mark non-prime numbers in the sieve array.
4. After creating the sieve, we check each number `i` from `2` to `N`.
   - If `i` is a factor of `N` and `seive[i]` is `true`, then `i` is a prime factor, and we add it to the result vector `ans`.
5. Return `ans` as the list of all prime factors of `N`.

Time Complexity: O(N log(log(N))) for sieve creation and O(N) for factor checking.
Space Complexity: O(N), for the sieve and the result vector `ans`.
*/

class Solution {
  public:
    vector<int> AllPrimeFactors(int N) {
        vector<bool> seive(N + 1, true);
        
        // Sieve of Eratosthenes to mark non-prime numbers
        for(int i = 2; i * i <= N; i++) {
            if(seive[i]) {
                for(int j = i * i; j <= N; j += i) {
                    seive[j] = false;
                }
            }
        }
        
        vector<int> ans;
        
        // Collecting prime factors of N
        for(int i = 2; i <= N; i++) {
            if(N % i == 0 && seive[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};


/*
Approach:
1. We iterate over numbers from `2` to `sqrt(N)` to find the prime factors.
2. For each number `i`, if `i` is a divisor of `N`, it is a prime factor, and we add it to the result vector `ans`.
   - We then divide `N` by `i` as many times as possible to remove all instances of `i` as a factor.
3. After the loop, if `N` is greater than `1`, it means `N` itself is a prime factor that is greater than `sqrt(N)`, so we add it to `ans`.
4. The resulting `ans` vector contains all unique prime factors of the original input `N`.

Time Complexity: O(sqrt(N)), as we only iterate up to `sqrt(N)`.
Space Complexity: O(1) for auxiliary space, excluding the result vector `ans`.

*/

class Solution {
  public:
    vector<int> AllPrimeFactors(int N) {
        vector<int> ans;
        
        // Check for prime factors up to sqrt(N)
        for(int i = 2; i * i <= N; i++) {
            if(N % i == 0) {
                ans.push_back(i);
                
                // Remove all instances of this prime factor
                while(N % i == 0) {
                    N /= i;
                }
            }
        }
        
        // If N is still greater than 1, it is a prime factor
        if(N > 1) ans.push_back(N);
        
        return ans;
    }
};
