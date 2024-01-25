/*
Shortest Prime Path
MediumAccuracy: 63.49%Submissions: 20K+Points: 4
Got your Geekbits? Now Get 90% Of Your Course Fee Refund! 

banner
You are given two four digit prime numbers num1 and num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get after changing a digit is a four digit prime number with no leading zeros.

Example 1:

Input:
num1 = 1033 
num2 = 8179
Output: 6
Explanation:
1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179.
There are only 6 steps reuired to reach num2 from num1. 
and all the intermediate numbers are 4 digit prime numbers.
Example 2:

Input:
num1 = 1033 
num2 = 1033
Output:
0
Your Task:  
You don't need to read input or print anything. Your task is to complete the function solve() which takes two integers num1 and num2 as input parameters and returns the distance of the shortest path from num1 to num2. If it is unreachable then return -1.

Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)

Constraints:
1000<=num1,num2<=9999
num1 and num2 are prime numbers.
*/

class Solution {
private:
    vector<string> primes;
    bool computed = false;

public:
    void sieve() {
        int n = 9999;
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        for (int i = 1000; i <= 9999; i++) {
            if (prime[i]) primes.push_back(to_string(i));
        }
        computed = true;
    }

    int solve(int num1, int num2) {
        if (num1 == num2) return 0;

        if (!computed) sieve();

        const int inf = 1e9;

        unordered_map<string, int> d;
        for (const string& i : primes)
            d[i] = inf;

        string start = to_string(num1);
        string end = to_string(num2);

        d[start] = 0;
        queue<string> q;
        q.push(start);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                for (char j = (i == 0 ? '1' : '0'); j <= '9'; j++) {
                    if (j != curr[i]) {
                        string next = curr;
                        next[i] = j;

                        auto ptr = d.find(next);
                        if (ptr != d.end() && ptr->second > d[curr] + 1) {
                            ptr->second = d[curr] + 1;
                            q.push(next);

                            if (next == end)
                                return d[next];
                        }
                    }
                }
            }
        }
        return -1;
    }
};