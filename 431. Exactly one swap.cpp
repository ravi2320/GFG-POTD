/*
Exactly one swap
Difficulty: MediumAccuracy: 48.42%Submissions: 11K+Points: 4
Given a string s, return the number of distinct strings that can be obtained by exactly one swap of two different indices (i < j).

Examples:

Input: s = "geek"
Output: 6
Explanation: After one swap, There are only 6 distinct strings possible.(i.e "egek","eegk","geek","geke","gkee" and "keeg") 
Input: s = "aaaa"
Output: 1
Explanation: Only one distinct string is possible after one swap(i.e "aaaa")
Constraints:
2 ≤ s.size() ≤ 104
*/

/*
Approach:
1. Count the frequency of each character in the string using a hash map.
2. For each character, calculate (n - freq[char]) and sum this value.
3. Divide the total sum by 2 because each valid pair is counted twice.
4. If there's any repeated character, add 1 to account for an extra valid special string.

Intuition:
We want to count the number of valid strings that can be formed by choosing two distinct positions (i, j) such that s[i] != s[j].
If all characters are unique, the number of such pairs is simply n*(n-1)/2.
However, the problem slightly adjusts it by using frequency mapping to count combinations more precisely.
Also, if there are repeated characters, we can additionally form one more special string (like choosing the same character more than once with a twist in definition).

Time Complexity: O(n) - where n is the length of the string.
Space Complexity: O(1) - at most 26 characters stored in the map (constant space).
*/

class Solution {
  public:
    int countStrings(string &s) {
        int n = s.length();

        // Frequency map to count occurrences of each character
        unordered_map<char, int> freq;
        bool isRepeat = false;  // Flag to check if any character is repeated
        int ans = 0;

        // Count frequency of each character and check if any repeats
        for(char &x : s){
            freq[x]++;
            if(freq[x] > 1){
                isRepeat = true;
            }
        }

        // Calculate total valid pairs (i, j) where s[i] != s[j]
        for(char &x : s){
            ans += (n - freq[x]);
        }

        // Each pair is counted twice, so divide by 2
        ans = ans / 2;

        // If any character is repeated, we can form one additional special string
        if(isRepeat) ans += 1;

        return ans;
    }
};