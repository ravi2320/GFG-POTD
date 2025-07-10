/*
Find the longest string
Difficulty: MediumAccuracy: 56.04%Submissions: 25K+Points: 4
Given an array of strings words[]. Find the longest string in words[] such that every prefix of it is also present in the array words[]. 

Note: If multiple strings have the same maximum length, return the lexicographically smallest one.

Examples:

Input: words[] = ["p", "pr", "pro", "probl", "problem", "pros", "process", "processor"]
Output: pros
Explanation: "pros" is the longest word with all prefixes ("p", "pr", "pro", "pros") present in the array words[].
Input: words[] = ["ab", "a", "abc", "abd"]
Output: abc
Explanation: Both "abc" and "abd" has all the prefixes in words[]. Since, "abc" is lexicographically smaller than "abd", so the output is "abc".
Constraints:
1 ≤ words.length() ≤ 103
1 ≤ words[i].length ≤ 103
*/

/*
Approach:
- Use a Trie to insert all words from the list.
- A word is considered valid for result only if all its prefixes (up to full length) are present in the list.
- For that, we insert all words into a Trie and mark each node where a word ends.
- Then for each word, we verify that every prefix is also marked as end-of-word while traversing the Trie.
- Among all valid words, choose the one with maximum length (or lexicographically smaller if tied).

Intuition:
- We need to ensure every prefix of a word is present in the word list.
- Trie helps efficiently check for prefix existence.

Time Complexity:
- Insert and Search each word: O(L), where L is length of word.
- For N words: O(N * L)

Space Complexity:
- Trie Node space: O(26 * N * L) in worst case (26 children per character, N words of length L)
*/

class Solution {
  public:
    // Define a Trie node structure
    struct TrieNode {
        bool isEndOfWord;
        TrieNode* children[26];

        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* root = new TrieNode();

    // Insert a word into the Trie
    void insert(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }

    // Check if all prefixes of the word exist in the Trie
    bool search(string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            node = node->children[idx];
            if (!node || !node->isEndOfWord)
                return false;
        }
        return true;
    }

    // Main function to return the longest valid word
    string longestString(vector<string>& words) {
        // Insert all words into Trie
        for (string& word : words) {
            insert(word);
        }

        string result = "";
        for (string& word : words) {
            // Check if all prefixes of word are valid
            if (search(word)) {
                if (word.length() > result.length() || 
                    (word.length() == result.length() && word < result)) {
                    result = word;
                }
            }
        }

        return result;
    }
};
