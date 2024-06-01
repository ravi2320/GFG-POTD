/*
Odd Even Problem
EasyAccuracy: 50.0%Submissions: 16K+Points: 2
In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

banner
Given a string s of lowercase English characters, determine whether the summation of x and y is EVEN or ODD.
where:

x is the count of distinct characters that occupy even positions in the English alphabet and have even frequency. 
y is the count of distinct characters that occupy odd positions in the English alphabet and have odd frequency.
Ex: string = "ab" here 'a' has an odd(1) position in the English alphabet & has an odd(1) frequency in the string so a is odd but b has an even(2) position in the English alphabet & has odd(1) frequency so it doesn't count(since string doesn't have 2 b's) so the final answer x + y = 1+0 = 1(odd) would be "ODD".

Note: Return "EVEN" if the sum of x & y is even otherwise return "ODD".

Example 1:

Input: 
s = "abbbcc"
Output: 
ODD
Explanation: 
x = 0 and y = 1 so (x + y) is ODD. 'a' occupies 1st place(odd) in english alphabets and its frequency is odd(1), 'b' occupies 2nd place(even) but its frequency is odd(3) so it doesn't get counted and 'c' occupies 3rd place(odd) but its frequency is even(2) so it also doesn't get counted.
Example 2:

Input: 
s = "nobitaa"
Output: 
EVEN
Explanation: 
Here n, b, t & a would not count since doesn't match with the even condition but o & i will be counted as it satisfies the odd conditions so x = 0 and y = 2 so (x + y) is EVEN.
Your Task:  
You don't need to read input or print anything. Complete the function evenOdd() which takes s as input parameter and returns "EVEN"  if x + y is even, and returns "ODD" otherwise.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(1) 

Constraints:
1 ≤ |s| ≤ 105


*/

// Intuition:
// - We need to classify characters in the string based on their position in the alphabet (odd or even) and their frequency (odd or even).
// - For characters at odd positions (1-based index), we check if their frequency is odd.
// - For characters at even positions (1-based index), we check if their frequency is even.
// - We count the number of characters that satisfy these conditions and determine if this count is odd or even.

// Time Complexity: O(N)
// - We iterate through the string once to count character frequencies, which takes O(N) time.
// - We then iterate through the character frequency map, which takes O(1) time since the map can have at most 26 entries (one for each letter).

// Space Complexity: O(1)
// - We use a fixed amount of extra space for the character frequency map (at most 26 entries).

class Solution {
public:
    string oddEven(string s) {
        unordered_map<char, int> mp;
        
        // Count the occurrences of each character
        for (char ch : s) {
            mp[ch]++;
        }
        
        int cnt = 0;
        
        // Iterate through the map to count characters based on the conditions
        for (auto& itr : mp) {
            char ch = itr.first;
            int frequency = itr.second;
            
            // Check if the character is at an odd index position (1-based)
            if ((ch - 'a' + 1) % 2 == 1) {
                // Check if the frequency is odd
                if (frequency % 2 == 1) {
                    cnt++;
                }
            } else { // Even indexed characters (1-based)
                // Check if the frequency is even
                if (frequency % 2 == 0) {
                    cnt++;
                }
            }
        }
        
        // Return "ODD" or "EVEN" based on the count
        return (cnt % 2) ? "ODD" : "EVEN";
    }
};
