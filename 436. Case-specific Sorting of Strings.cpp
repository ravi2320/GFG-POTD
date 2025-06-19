/*
Case-specific Sorting of Strings
Difficulty: MediumAccuracy: 69.88%Submissions: 64K+Points: 4Average Time: 45m
Given a string s consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

Examples :

Input: s = "GEekS"
Output: EGekS
Explanation: Sorted form of given string with the same case of character will result in output as EGekS.
Input: s = "XWMSPQ"
Output: MPQSWX
Explanation: Since all characters are of the same case We can simply perform a sorting operation on the entire string.
Constraints:
1 ≤ s.length() ≤ 105
*/

/*
Approach:
We need to sort a string such that **uppercase and lowercase characters retain their positions** (i.e., 
uppercase characters only replace uppercase positions, and lowercase characters only replace lowercase ones),
but within each category, characters are sorted.

Steps:
1. Separate the characters into two vectors: `upper` and `lower`.
2. Sort each of them independently.
3. Traverse the original string:
   - For each uppercase character, insert from sorted `upper` list.
   - For each lowercase character, insert from sorted `lower` list.

Intuition:
We need a stable mapping of sorted letters to the correct cases. Sorting the groups separately and mapping 
them back according to the original positions ensures that.

Time Complexity: O(n log n)
- Collecting and placing characters: O(n)
- Sorting both case groups: O(n log n) in worst case

Space Complexity: O(n)
- To store the separated character groups and the result string
*/

class Solution {
public:
    string caseSort(string& s) {
        int n = s.length();
        vector<char> upper, lower;

        // Separate characters based on case
        for (int i = 0; i < n; i++) {
            if (isupper(s[i]))
                upper.push_back(s[i]);
            else
                lower.push_back(s[i]);
        }

        // Sort uppercase and lowercase characters separately
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());

        // Rebuild the string with sorted cases at correct positions
        int up = 0, low = 0;
        string res = s;  // Create a copy of the original string

        for (int i = 0; i < n; i++) {
            if (isupper(s[i]))
                res[i] = upper[up++];  // Place next uppercase letter
            else
                res[i] = lower[low++]; // Place next lowercase letter
        }

        return res;
    }
};


/*
Approach:
We need to sort the string such that uppercase and lowercase letters retain their respective positions.
However, each group (uppercase and lowercase) must be sorted in alphabetical order.

Instead of storing the characters in separate vectors and sorting them, we optimize using **frequency arrays**:
- `freq1` for uppercase letters ('A' to 'Z')
- `freq2` for lowercase letters ('a' to 'z')

Steps:
1. Count frequency of each uppercase and lowercase letter separately.
2. Traverse the original string:
   - For each uppercase letter, find the next smallest available letter in `freq1`.
   - For each lowercase letter, do the same using `freq2`.
3. Build and return the result string.

Intuition:
Sorting with frequency arrays (counting sort idea) avoids using `sort()` and gives better performance.

Time Complexity: O(n + 26) ≈ O(n)
- O(n) to count and build the result
- O(1) for scanning fixed-length frequency arrays

Space Complexity: O(1)
- Constant space for 2 arrays of size 26
*/

class Solution {
  public:
    string caseSort(string& s) {
        vector<int> freq1(26, 0); // Frequency of uppercase letters
        vector<int> freq2(26, 0); // Frequency of lowercase letters

        // Count frequencies
        for (char &x : s) {
            if (x >= 'A' && x <= 'Z') {
                freq1[x - 'A']++;
            } else {
                freq2[x - 'a']++;
            }
        }

        int idx1 = 0, idx2 = 0;
        string res;

        // Reconstruct the result string based on sorted frequency usage
        for (char &x : s) {
            if (x >= 'A' && x <= 'Z') {
                while (freq1[idx1] == 0) idx1++; // Find next smallest uppercase letter
                res.push_back(idx1 + 'A');      // Append to result
                freq1[idx1]--;
            } else {
                while (freq2[idx2] == 0) idx2++; // Find next smallest lowercase letter
                res.push_back(idx2 + 'a');      // Append to result
                freq2[idx2]--;
            }
        }

        return res;
    }
};