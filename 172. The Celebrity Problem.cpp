/*
The Celebrity Problem
Difficulty: MediumAccuracy: 38.33%Submissions: 258K+Points: 4
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[0 1 0],
                [0 0 0], 
                [0 1 0]]
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
Input: mat[][] = [[0 1],
                [1 0]]
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= mat.size()<= 3000
0 <= mat[i][j]<= 1
*/

/*
Intuition:
To determine if there is a celebrity in the party, we utilize two vectors:
1. `Iknow`: Keeps track of how many people each person knows.
2. `knowMe`: Keeps track of how many people know each person.

A celebrity will be someone who:
1. Knows 0 people (`Iknow[i] == 0`).
2. Is known by everyone else (`knowMe[i] == n-1`).

Time Complexity:
The time complexity is O(n^2) due to the need to traverse the entire matrix.

Space Complexity:
The space complexity is O(n) for the two auxiliary arrays `Iknow` and `knowMe`.

*/

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> Iknow(n, 0), knowMe(n, 0);
        
        // Fill the Iknow and knowMe arrays
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j]) {
                    Iknow[i]++;
                    knowMe[j]++;
                }
            }
        }
        
        // Find the potential celebrity
        for (int i = 0; i < n; i++) {
            if (Iknow[i] == 0 && knowMe[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};

/*
Intuition:
To find the celebrity, we can use a two-pointer approach. By iteratively comparing individuals, we can narrow down the potential celebrity. If a person `i` knows person `j`, then `i` cannot be a celebrity, and we move to the next person. Similarly, if `j` knows `i`, then `j` cannot be a celebrity.

Once we narrow down to one candidate, we verify if this candidate is indeed a celebrity by checking two conditions:
1. They don't know anyone else.
2. Everyone else knows them.

Time Complexity:
The time complexity is O(n) for the two-pointer approach to narrow down the candidate and O(n) to verify the candidate, resulting in an overall time complexity of O(n).

Space Complexity:
The space complexity is O(1) as we only use a few extra variables for the two-pointer approach.

*/

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0;
        int down = n - 1;
        
        // Narrow down the potential celebrity using two-pointer approach
        while (top < down) {
            if (mat[top][down]) {
                top++;
            } else {
                down--;
            }
        }
        
        // Verify the candidate
        int candidate = top;
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                if (mat[candidate][i] != 0 || mat[i][candidate] != 1) {
                    return -1;
                }
            }
        }
        
        return candidate;
    }
};


/*
Intuition:
To find a celebrity in a party, we can leverage the properties of a celebrity:
1. A celebrity is known by everyone.
2. A celebrity knows no one.

The algorithm involves iterating over each person and checking:
1. If everyone else knows this person.
2. This person knows no one else.

Time Complexity:
The time complexity is O(n^2) because we check the entire matrix.

Space Complexity:
The space complexity is O(1) since we are not using any extra space other than variables.

*/

class Solution {
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (mat[j][i]) cnt++;
            }
            // Check if everyone else knows person i
            if (cnt == n - 1) {
                cnt = 0;
                for (int j = 0; j < n; j++) {
                    if (mat[i][j]) cnt++;
                }
                // Check if person i knows no one
                if (cnt == 0) return i;
            }
        }
        return -1;
    }
};
