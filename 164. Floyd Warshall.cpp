/*
Floyd Warshall
Difficulty: MediumAccuracy: 32.89%Submissions: 135K+Points: 4
The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. The graph is represented as an adjacency matrix of size n*n. Matrix[i][j] denotes the weight of the edge from i to j. If Matrix[i][j]=-1, it means there is no edge from i to j.
Note : Modify the distances for every pair in-place.

Examples :

Input: matrix = [[0, 25],[-1, 0]]

Output: [[0, 25],[-1, 0]]

Explanation: The shortest distance between every pair is already given(if it exists).
Input: matrix = [[0, 1, 43],[1, 0, 6],[-1, -1, 0]]

Output: [[0, 1, 7],[1, 0, 6],[-1, -1, 0]]

Explanation: We can reach 2 from 0 as 0->1->2 and the cost will be 1+6=7 which is less than 43.
Expected Time Complexity: O(n3)
Expected Space Complexity: O(1)

Constraints:
1 <= n <= 100
-1 <= matrix[ i ][ j ] <= 1000


*/

/*
Intuition:
The task involves finding the shortest path between every pair of vertices in a weighted graph represented by an adjacency matrix. The Floyd-Warshall algorithm is a classical approach to solve this problem. It considers each vertex as an intermediate point and attempts to improve the shortest path estimate between each pair of vertices. This solution also handles the presence of 'no path' cases, represented by -1 in the input matrix.

Time Complexity:
The Floyd-Warshall algorithm runs in O(V^3) time complexity, where V is the number of vertices (or nodes) in the graph. This is due to the three nested loops iterating over the vertices.

Space Complexity:
The space complexity is O(1) additional space beyond the input matrix, as the algorithm updates the matrix in place. The matrix itself requires O(V^2) space to store distances between every pair of vertices.
*/

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Replace -1 with a large number to indicate no direct path
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 100000;
                }
            }
        }

        // Floyd-Warshall algorithm to find shortest paths
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        // Convert large numbers back to -1 to indicate no path
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 100000) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};
