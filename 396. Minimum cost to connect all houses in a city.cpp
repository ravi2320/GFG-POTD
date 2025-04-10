/*
Minimum cost to connect all houses in a city
Difficulty: MediumAccuracy: 75.5%Submissions: 3K+Points: 4
Given a 2D array houses[][], consisting of n 2D coordinates {x, y} where each coordinate represents the location of each house, the task is to find the minimum cost to connect all the houses of the city.

The cost of connecting two houses is the Manhattan Distance between the two points (xi, yi) and (xj, yj) i.e., |xi – xj| + |yi – yj|, where |p| denotes the absolute value of p.

Examples :

Input: n = 5 houses[][] = [[0, 7], [0, 9], [20, 7], [30, 7], [40, 70]]
Output: 105
Explanation:
Connect house 1 (0, 7) and house 2 (0, 9) with cost = 2
Connect house 1 (0, 7) and house 3 (20, 7) with cost = 20
Connect house 3 (20, 7) with house 4 (30, 7) with cost = 10 
At last, connect house 4 (30, 7) with house 5 (40, 70) with cost 73.
All the houses are connected now.
The overall minimum cost is 2 + 10 + 20 + 73 = 105.

Input: n = 4 houses[][] = [[0, 0], [1, 1], [1, 3], [3, 0]]
Output: 7
Explanation: 
Connect house 1 (0, 0) with house 2 (1, 1) with cost = 2
Connect house 2 (1, 1) with house 3 (1, 3) with cost = 2 
Connect house 1 (0, 0) with house 4 (3, 0) with cost = 3 
The overall minimum cost is 3 + 2 + 2 = 7.
Constraint:
1 ≤ n ≤ 103
0 ≤ houses[i][j] ≤ 103
*/

/*
Approach:
- Treat each house as a node in a graph.
- Edge weight between two nodes is their Manhattan distance.
- Build a complete graph and apply Prim’s algorithm to find MST.

Time Complexity: O(V^2 * log V)
Space Complexity: O(V^2) for adjacency list
*/

class Solution {
    typedef pair<int, int> P; // {weight, node}

public:
    // Prim's algorithm to find MST weight
    int prims(int V, vector<vector<P>> &adj) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> inMST(V, false); // track visited nodes

        pq.push({0, 0}); // start with node 0, weight 0
        int sum = 0;

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (inMST[node]) continue;

            inMST[node] = true;
            sum += wt;

            for (auto &tmp : adj[node]) {
                int ngbr = tmp.first;
                int ngbr_wt = tmp.second;

                if (!inMST[ngbr]) {
                    pq.push({ngbr_wt, ngbr});
                }
            }
        }

        return sum;
    }

    int minCost(vector<vector<int>>& houses) {
        int V = houses.size();
        vector<vector<P>> adj(V); // adjacency list

        // Build complete graph with Manhattan distances
        for (int i = 0; i < V; i++) {
            int x1 = houses[i][0];
            int y1 = houses[i][1];

            for (int j = i + 1; j < V; j++) {
                int x2 = houses[j][0];
                int y2 = houses[j][1];

                int dist = abs(x2 - x1) + abs(y2 - y1);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        return prims(V, adj);
    }
};