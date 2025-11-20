/*
Make Strings Equal

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 62.79%Submissions: 5K+Points: 4
Given two strings s and t, consisting of lowercase English letters. You are also given, a 2D array transform[][], where each entry [x, y] means that you are allowed to transform character x into character y and an array cost[], where cost[i] is the cost of transforming transform[i][0] into transform[i][1]. You can apply any transformation any number of times on either string.

Your task is to find the minimum total cost required to make the strings identical. If it is impossible to make the two strings identical using the available transformations, return -1.

Examples:

Input: s = "abcc", t = "bccc", transform[][] = [['a', 'b'], ['b', 'c'], ['c', 'a']], cost[] = [2, 1, 4]
Output: 3
Explanation: We can convert both strings into "bccc" with a cost of 3 using these operations:
transform at Position 0 in s: a -> b (cost 2)
transform at Position 1 in s: b -> c (cost 1)
Other characters already match.
Input: s = "az", t = "dc", transform[][] = [['a', 'b'], ['b', 'c'], ['c', 'd'], ['a', 'd'], ['z', 'c']], cost[] = [5, 3, 2, 50, 10]
Output: 20
Explanation: We can convert both strings into "dc" with a cost of 20 using these operations:
transform at Position 0 in s: a -> d by path a -> b -> c -> d (cost 5 + 3 + 2 = 10)
transform at Position 1 in s: z -> c (cost 10)
Input: s = "xyz", t = "xzy", transform[][] = [['x', 'y'], ['x', 'z']], cost[] = [3, 3]
Output: -1
Explanation: It is not possible to make the two strings equal.
Constraints:
1 ≤ s.size() = t.size() ≤ 105
1 ≤ transform.size() = cost.size() ≤ 500
'a' ≤ transform[i][0], transform[i][1] ≤ 'z'
1 ≤ cost[i] ≤ 500
*/

// Intuition:
// The problem is essentially about transforming one string into another using a set of allowed character transformations, 
// and for each transformation, there is a cost associated. The goal is to minimize the total transformation cost.
// The approach is based on graph theory, where we treat each character as a node and each transformation as an edge with a weight (cost).

// Approach:
// 1. Represent each character transformation as a directed edge in a graph where the nodes are the characters (0 to 25 for 'a' to 'z').
// 2. Use the Floyd-Warshall algorithm to compute the shortest path (minimum cost) between every pair of characters.
//    This will allow us to find the minimum cost of transforming one character into another (possibly via intermediate transformations).
// 3. For each character in the input strings, calculate the minimum cost to transform the character in the source string into the corresponding character in the target string.
// 4. If there is no valid transformation path between a pair of characters, return -1 since it's impossible to transform that character.
// 5. Sum the costs to get the final answer.

class Solution {
public:
    // Main function to calculate the minimum cost to convert string s to string t
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        
        int n = s.size();  // Length of the input strings
        // Initialize a 26x26 matrix to store the minimum transformation cost between any two characters
        vector<vector<int>> minCost(26, vector<int>(26, INT_MAX));
        
        // Step 1: Populate the minCost matrix with direct transformation costs
        for (int i = 0; i < transform.size(); i++) {
            int a = transform[i][0] - 'a';  // Convert char to its corresponding index (0 to 25)
            int b = transform[i][1] - 'a';  // Convert char to its corresponding index (0 to 25)
            minCost[a][b] = min(minCost[a][b], cost[i]);  // Take the minimum of existing cost and new transformation cost
        }
        
        // Step 2: The cost to transform a character into itself is 0
        for (int i = 0; i < 26; i++) {
            minCost[i][i] = 0;  // No cost to transform a character into itself
        }
        
        // Step 3: Use the Floyd-Warshall algorithm to calculate the minimum cost for all pairs of characters
        for (int k = 0; k < 26; k++) {  // Iterate over all intermediate nodes (characters)
            for (int i = 0; i < 26; i++) {  // Iterate over all starting nodes (characters)
                for (int j = 0; j < 26; j++) {  // Iterate over all destination nodes (characters)
                    // If there is a path from i to k and from k to j, update the cost from i to j
                    if (minCost[i][k] != INT_MAX && minCost[k][j] != INT_MAX) {
                        minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                    }
                }
            }
        }
        
        long long ans = 0;  // Variable to store the total minimum cost
        
        // Step 4: Calculate the minimum cost to transform string s into string t
        for (int i = 0; i < n; i++) {
            int a = s[i] - 'a';  // Convert character s[i] to its corresponding index
            int b = t[i] - 'a';  // Convert character t[i] to its corresponding index
            int temp = INT_MAX;  // Variable to store the minimum cost for transforming s[i] to t[i]
            
            // Step 5: Try all possible intermediate characters and find the minimum cost transformation
            for (int ch = 0; ch < 26; ch++) {
                // Check if there's a valid path from s[i] to ch and from t[i] to ch
                if (minCost[a][ch] != INT_MAX && minCost[b][ch] != INT_MAX) {
                    temp = min(temp, minCost[a][ch] + minCost[b][ch]);
                }
            }
            
            // If no valid transformation exists, return -1
            if (temp == INT_MAX) {
                return -1;
            }
            
            ans += temp;  // Add the minimum cost for this transformation to the total answer
        }
        
        return ans;  // Return the total minimum cost
    }
};

// Time Complexity:
// The Floyd-Warshall algorithm runs in O(26^3) time because there are 26 characters, and we check every triplet of characters.
// This simplifies to O(26^3) which is constant time (since 26 is a small number).
// The second loop iterates over the length of the string (n) and for each character, we check all 26 possible intermediate characters.
// This gives a time complexity of O(n * 26).

// Thus, the overall time complexity is O(26^3 + n * 26), which simplifies to O(n * 26) since 26^3 is a constant.

// Space Complexity:
// We use a 26x26 matrix to store the minimum transformation costs, which requires O(26^2) space.
// In addition, we store the input strings and transformation costs, which require O(n) space.

