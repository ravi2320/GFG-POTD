/*
Maximum XOR of two numbers in an array
Difficulty: MediumAccuracy: 50.0%Submissions: 23K+Points: 4
Given an array arr[] of non-negative integers of size n. Find the maximum possible XOR between two numbers present in the array.

Examples:

Input: arr[] = [25, 10, 2, 8, 5, 3]
Output: 28
Explanation: The maximum possible XOR is 5 ^ 25 = 28.
Input: arr[] = [1, 2, 3, 4, 5, 6, 7]
Output: 7
Explanation : The maximum possible XOR is 1 ^ 6 = 7.
Constraints:
2 ≤ arr.size() ≤ 5*104
1 ≤ arr[i] ≤ 106
*/

/*
Intuition:
To find the maximum XOR of any two numbers in an array, we can leverage the binary representation of numbers.
XOR is maximized when bits differ (i.e., 1^0 = 1), so we want to find two numbers such that their bits differ as much as possible.

Approach:
We use a Trie (prefix tree) to store the binary representations of all numbers.
Each node has two children: left for bit 0 and right for bit 1.
To find the max XOR for a number, we greedily traverse the opposite bit at each level if it exists in the Trie.
This helps us maximize the XOR at every bit position (starting from the most significant bit).

Steps:
1. Insert all numbers into the Trie.
2. For each number, traverse the Trie to find the number that yields the maximum XOR with it.
3. Track the maximum result across all such comparisons.

Time Complexity: O(N * 32)
- Each of the N numbers is inserted and queried over 32 bits.

Space Complexity: O(N * 32)
- In the worst case, each number adds 32 nodes to the Trie.
*/

class Solution {
public:
    struct TrieNode {
        TrieNode* left;  // represents bit 0
        TrieNode* right; // represents bit 1
        TrieNode() : left(nullptr), right(nullptr) {}
    };
    
    // Insert number into Trie
    void insert(TrieNode* root, int num) {
        TrieNode* pCrawl = root;
        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 0) {
                if (!pCrawl->left)
                    pCrawl->left = new TrieNode();
                pCrawl = pCrawl->left;
            } else {
                if (!pCrawl->right)
                    pCrawl->right = new TrieNode();
                pCrawl = pCrawl->right;
            }
        }
    }
    
    // Find max XOR for a number with any number in the Trie
    int findMaxXor(TrieNode* root, int num) {
        TrieNode* pCrawl = root;
        int maxi = 0;
        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 0) {
                if (pCrawl->right) {
                    maxi += (1 << i);
                    pCrawl = pCrawl->right;
                } else {
                    pCrawl = pCrawl->left;
                }
            } else {
                if (pCrawl->left) {
                    maxi += (1 << i);
                    pCrawl = pCrawl->left;
                } else {
                    pCrawl = pCrawl->right;
                }
            }
        }
        return maxi;
    }

    // Main function to return the maximum XOR of any two numbers in the array
    int maxXor(vector<int> &arr) {
        TrieNode* root = new TrieNode();
        for (int &x : arr)
            insert(root, x);

        int res = 0;
        for (int &x : arr)
            res = max(res, findMaxXor(root, x));

        return res;
    }
};
