/*
Print Anagrams Together
Difficulty: MediumAccuracy: 65.78%Submissions: 80K+Points: 4
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The final output will be in lexicographic order.

Examples:

Input: arr[] = ["act", "god", "cat", "dog", "tac"]
Output: [["act", "cat", "tac"], ["god", "dog"]]
Explanation: There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.
Input: arr[] = ["no", "on", "is"]
Output: [["is"], ["no", "on"]]
Explanation: There are 2 groups of anagrams "is" makes group 1. "no", "on" make group 2.
Input: arr[] = ["listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"]
Output: [["abc", "cab", "bac"], ["listen", "silent", "enlist"], ["rat", "tar", "art"]]
Explanation: 
Group 1: "abc", "bac", and "cab" are anagrams.
Group 2: "listen", "silent", and "enlist" are anagrams.
Group 3: "rat", "tar", and "art" are anagrams.
Constraints:
1<= arr.size() <=100
1<= arr[i].size() <=10
*/

/*
Approach:
1. Use a hash map to group strings by their sorted character representation.
2. Iterate through the input array, sort each string, and use the sorted string as a key in the hash map.
3. Store the original strings in a vector corresponding to that key.
4. Finally, collect all grouped anagrams into the result and sort the groups for a consistent order.

Intuition:
Anagrams share the same characters in the same frequency, so sorting them produces identical strings.
This allows grouping strings with the same sorted form as keys in the hash map.

Time Complexity:
- Sorting each string: O(N * K log K), where N is the number of strings, and K is the average length of a string.
- Traversing the map to collect results: O(N).
- Sorting the resulting groups: O(M log M), where M is the number of unique groups.
Overall: O(N * K log K + M log M).

Space Complexity:
- Storing the hash map and result: O(N * K), where N is the number of strings, and K is the average length of a string.
*/

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // Hash map to group strings by their sorted character representation
        unordered_map<string, vector<string>> mp;

        // Iterate through each string in the array
        for (string &x : arr) {
            string temp = x; // Copy the string
            sort(temp.begin(), temp.end()); // Sort characters in the string
            mp[temp].push_back(x); // Group original string under the sorted key
        }

        // Prepare the final result
        vector<vector<string>> ans;
        for (auto &itr : mp) {
            ans.push_back(itr.second); // Add each group of anagrams to the result
        }

        // Sort the groups of anagrams for consistent ordering
        sort(ans.begin(), ans.end());

        return ans; // Return the grouped anagrams
    }
};

/*
Approach:
1. Use a hash map to group strings by a frequency-based key derived from the count of each character.
2. For each string, create a frequency array of size 26 (one for each letter) to count occurrences of characters.
3. Convert the frequency array into a unique string key and use it to group anagrams in the hash map.
4. Collect all grouped anagrams from the hash map and sort the groups for consistent ordering.

Intuition:
Anagrams share the same characters in the same frequency. Using a frequency array as a key avoids the overhead of sorting, making the approach faster for large strings.

Time Complexity:
- Generating the frequency key for each string: O(N * K), where N is the number of strings, and K is the average length of a string.
- Traversing the map to collect results: O(N).
- Sorting the resulting groups: O(M log M), where M is the number of unique groups.
Overall: O(N * K + M log M).

Space Complexity:
- Hash map storage: O(N * K), where N is the number of strings, and K is the average length of a string.
- Frequency array storage for temporary use: O(26) = O(1).
*/

class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // Hash map to group strings by their frequency-based key
        unordered_map<string, vector<string>> mp;

        // Iterate through each string in the array
        for (string &str : arr) {
            vector<int> count(26, 0); // Frequency array for each character
            for (char &x : str) {
                count[x - 'a']++; // Count the frequency of each character
            }

            // Generate a unique key based on the frequency array
            string key = "";
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]); // Append each frequency to the key
            }

            mp[key].push_back(str); // Group the original string under the generated key
        }

        // Prepare the final result
        vector<vector<string>> ans;
        for (auto &itr : mp) {
            ans.push_back(itr.second); // Add each group of anagrams to the result
        }

        // Sort the groups of anagrams for consistent ordering
        sort(ans.begin(), ans.end());

        return ans; // Return the grouped anagrams
    }
};
