/*
Sum of all divisors from 1 to n
EasyAccuracy: 43.37%Submissions: 93K+Points: 2
Get Internship at GfG by submitting your Entries in: Data Science Blogathon

banner
Given a positive integer N., The task is to find the value of Σi from 1 to N F(i) where function F(i) for the number i is defined as the sum of all divisors of i.

Example 1:

Input:
N = 4
Output:
15
Explanation:
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
ans = F(1) + F(2) + F(3) + F(4)
    = 1 + 3 + 4 + 7
    = 15
Example 2:

Input:
N = 5
Output:
21
Explanation:
F(1) = 1
F(2) = 1 + 2 = 3
F(3) = 1 + 3 = 4
F(4) = 1 + 2 + 4 = 7
F(5) = 1 + 5 = 6
ans = F(1) + F(2) + F(3) + F(4) + F(5)
    = 1 + 3 + 4 + 7 + 6
    = 21
Your Task:  
You don't need to read input or print anything. Your task is to complete the function sumOfDivisors() which takes an integer N as an input parameter and returns an integer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= N <= 106
*/

// Intuition:
// - The problem requires us to calculate the sum of all divisors for each number from 1 to N.
// - For each number, we find its divisors and sum them up.
// - We use an efficient approach to find the divisors by iterating up to the square root of the number, ensuring each divisor pair is counted once.

// Time Complexity: O(N * sqrt(N))
// - For each number from 1 to N, we iterate up to the square root of the number to find its divisors.
// - This results in a time complexity of O(N * sqrt(N)) since the divisor function operates in O(sqrt(N)) time.

// Space Complexity: O(1)
// - The algorithm uses a constant amount of extra space for variables and does not require additional data structures.

class Solution {
public:
    // Function to find the sum of all divisors of a number `n`
    long long divisor(int n) {
        long long sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (n / i != i) {
                    sum += n / i;
                }
            }
        }
        return sum;
    }

    // Function to find the sum of divisors of all numbers from 1 to `N`
    long long sumOfDivisors(int N) {
        long long sum = 0;
        for (int i = 1; i <= N; i++) {
            sum += divisor(i);
        }
        return sum;
    }
};


// Intuition:
// - Instead of calculating the sum of divisors for each number individually, we can use a mathematical approach to directly compute the sum.
// - For a given number `i`, it contributes to the sum as a divisor for all multiples of `i`.
// - The number of times `i` appears as a divisor in the range 1 to N is `N / i`.
// - Thus, the sum contribution by `i` for all its multiples is `i * (N / i)`.

// Time Complexity: O(N)
// - We iterate through each number from 1 to N once, performing constant-time calculations in each iteration.

// Space Complexity: O(1)
// - The algorithm uses a constant amount of extra space for variables and does not require additional data structures.

class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        long long sum = 0;
        for (int i = 1; i <= N; i++) {
            sum += i * (N / i);
        }
        return sum;
    }
};
