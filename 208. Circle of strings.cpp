/*
Circle of strings
Difficulty: HardAccuracy: 15.56%Submissions: 69K+Points: 8
Given an array arr of lowercase strings, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is the same as the first character of Y. If every string of the array can be chained with exactly two strings of the array(one with the first character and the second with the last character of the string), it will form a circle.

For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"

Examples

Input: arr[] = ["abc", "bcd", "cdf"]
Output: 0
Explaination: These strings can't form a circle because no string has 'd'at the starting index.
Input: arr[] = ["ab" , "bc", "cd", "da"]
Output: 1
Explaination: These strings can form a circle of strings.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints: 
1 ≤ length of strings ≤ 20
*/

/*
Approach:
1. For a circle to exist, every word must end with a letter that can start the next word. This translates to ensuring that the indegree (number of words starting with a letter) is equal to the outdegree (number of words ending with a letter) for each character.
2. Use two arrays `indegree` and `outdegree` to track the starting and ending letter frequencies of each word.
3. Store words starting with each character in a map for easy access.
4. Perform a BFS to ensure that all words are part of the same connected component.
5. If any letter has unequal indegree and outdegree or if the BFS does not visit all words, return `0` (no circle possible).
6. If all conditions are satisfied, return `1` (circle is possible).

Time Complexity:
- O(n + 26): Where `n` is the number of words. The BFS and degree checking are done in linear time.

Space Complexity:
- O(n + 26): We use space for the `indegree`, `outdegree`, `vis` arrays, and the `mp` map.

*/

class Solution {
  public:
    int isCircle(vector<string> &arr) {
        int n = arr.size();
        
        // Initialize indegree and outdegree for all 26 letters
        vector<int> indegree(26, 0), outdegree(26, 0);
        unordered_map<char, vector<int>> mp; // Map for words starting with each letter
        
        // Calculate indegree, outdegree, and store index of words starting with each letter
        for (int i = 0; i < n; i++) {
            indegree[arr[i][0] - 'a']++;               // Increase indegree for start letter
            outdegree[arr[i].back() - 'a']++;          // Increase outdegree for end letter
            mp[arr[i][0]].push_back(i);                // Map word start letter to its index
        }
        
        // Check if indegree equals outdegree for all characters
        for (int i = 0; i < 26; i++) {
            if (indegree[i] != outdegree[i])
                return 0;  // If any mismatch in degree, circle is not possible
        }
        
        int ans = 1;  // Tracks whether all words can be visited
        queue<int> q;
        vector<int> vis(n, 0);  // Visited array to track visited words

        // Start BFS from the first word
        q.push(0);
        vis[0] = 1;
        
        // Perform BFS to ensure all words can form a circle
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            
            // Check all words that can follow the current word
            for (auto x : mp[arr[idx].back()]) {
                if (!vis[x]) {
                    ans++;
                    vis[x] = 1;  // Mark the word as visited
                    q.push(x);   // Add it to the BFS queue
                }
            }
        }
        
        // Return true if all words are visited, otherwise false
        return ans == n;
    }
};
