/*
Count Unique Vowel Strings
Difficulty: MediumAccuracy: 58.95%Submissions: 2K+Points: 4
You are given a lowercase string s, determine the total number of distinct strings that can be formed using the following rules:

Identify all unique vowels (a, e, i, o, u) present in the string.
For each distinct vowel, choose exactly one of its occurrences from s. If a vowel appears multiple times, each occurrence represents a unique selection choice.
Generate all possible permutations of the selected vowels. Each unique arrangement counts as a distinct string.
Return the total number of such distinct strings.

Examples:

Input: s = "aeiou"
Output: 120
Explanation: Each vowel appears once, so the number of different strings can form is 5! = 120.
Input: s = "ae"
Output: 2
Explanation: Pick a and e, make all orders → "ae", "ea".
Input: s = "aacidf"
Output: 4 
Explanation: Vowels in s are 'a' and 'i', Pick each 'a' once with a single 'i', make all orders → "ai", "ia", "ai", "ia".
Constraints:
1 ≤ s.size() ≤ 100
*/

// ✅ Approach:
// 1. Count the frequency of each vowel in the string ('a', 'e', 'i', 'o', 'u').
// 2. For each distinct vowel, track how many times it appears.
// 3. Compute the total number of ways as: factorial(count of distinct vowels) × product of frequencies of each vowel.

// ✅ Intuition:
// We are choosing all distinct vowels in all possible orders (factorial of count of distinct vowels).
// For each such order, we multiply the number of combinations possible using the frequency of each vowel.

// ✅ Time Complexity: O(n) — where n is the length of the string (for counting vowels).
// ✅ Space Complexity: O(1) — constant space for frequency array of size 5 (for 5 vowels).

class Solution {
  public:
    // Helper function to compute factorial of a number
    int factorial(int n){
        int ans = 1;
        for(int i = 2; i <= n; i++){
            ans *= i;
        }
        return ans;
    }

    int vowelCount(string& s) {
        // Frequency array for vowels: a, e, i, o, u
        vector<int> freq(5, 0);
        
        // Count each vowel's frequency in the string
        for(char &ch : s){
            if(ch == 'a') freq[0]++;
            else if(ch == 'e') freq[1]++;
            else if(ch == 'i') freq[2]++;
            else if(ch == 'o') freq[3]++;
            else if(ch == 'u') freq[4]++;
        }
        
        int cnt = 0;    // Count of distinct vowels
        int ways = 1;   // Product of frequencies of distinct vowels
        
        // Calculate how many distinct vowels are present and their total arrangements
        for(int &f : freq){
            if(f > 0){
                cnt++;       // Increase count of distinct vowels
                ways *= f;   // Multiply the frequency into the result
            }
        }
        
        // If no vowels found, return 0
        if(cnt == 0)
            return 0;
        
        // Final result = factorial of count of distinct vowels * product of their frequencies
        return ways * factorial(cnt);
    }
};
