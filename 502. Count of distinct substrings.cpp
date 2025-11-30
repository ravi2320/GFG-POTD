/*
Count of distinct substrings

Given a string s consisting of lowercase English characters, determine the total number of distinct non-empty substrings present in the string. A substring is defined as a contiguous block of characters within the string.

Two substrings are considered distinct if their contents differ, even if they originate from different positions in the string.

Note: The empty substring is not counted.

Examples :

Input: s = "ababa"
Output: 9
Explanation: All distinct substrings of "ababa" are: "a", "b", "ab", "ba", "aba", "bab", "abab", "baba", "ababa".
Input: s = "aaa"
Output: 3
Explanation: The distinct substrings of "aaa" are: "a", "aa", "aaa".
Constraints:
1 ≤ s.size() ≤ 3000
*/

/*
Intuition:
-----------
We want to count the number of **distinct substrings** of a string.

A naive approach would generate all substrings (O(n²)) and insert into a set (O(n) per insert),
leading to O(n³) time in worst case.

A better method is using a **Trie of all suffixes**:
- Insert every substring starting from each index i.
- Each NEW node created in the Trie corresponds to a **new distinct substring**.

So we simply count how many Trie nodes are created.

Approach:
----------
1. Create a Trie root.
2. For each starting index i:
       - Traverse Trie while reading characters s[i], s[i+1], ...
       - If a new character path (link) does not exist → create node and increment count.
3. Total nodes created = number of distinct substrings.

Trie Explanation:
-----------------
Every unique substring forms a unique path in the Trie.
Repeated substrings reuse already existing nodes, so only new branches increase the count.

Time Complexity:
----------------
O(n²)  
We insert all substrings, but each character insertion is O(1) due to array of size 26.

Space Complexity:
-----------------
O(n²) in worst case, number of Trie nodes ≈ number of distinct substrings.

*/

class Node {
public:
    Node* links[26];

    Node() {
        // Initialize all children as NULL
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    // Check if character link exists
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // Insert new node at character position
    void put(Node* node, char ch) {
        links[ch - 'a'] = node;
    }

    // Get the next node for given character
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Solution {
public:
    int countSubs(string& s) {

        Node* root = new Node();     // Trie root
        int n = s.length();
        int cnt = 0;                 // Count of new Trie nodes = distinct substrings

        // Start substring from every index i
        for (int i = 0; i < n; i++) {

            Node* node = root;

            // Extend substring ending at j
            for (int j = i; j < n; j++) {

                // If new character-path does not exist, create it
                if (!node->containsKey(s[j])) {
                    cnt++;
                    node->put(new Node(), s[j]);
                }

                // Move to next character in the Trie
                node = node->get(s[j]);
            }
        }

        return cnt;
    }
};
