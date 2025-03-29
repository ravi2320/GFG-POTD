/*
Job Sequencing Problem
Difficulty: MediumAccuracy: 34.51%Submissions: 287K+Points: 4
You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
Examples :

Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).
Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).
Constraints:
1 ≤ deadline.size() == profit.size() ≤ 105
1 ≤ deadline[i] ≤ deadline.size()
1 ≤ profit[i] ≤ 500
*/

/*
Approach:
1. **Sort Jobs by Profit (Descending Order)**:
   - Prioritize jobs with higher profit first.

2. **Use Disjoint Set to Track Available Slots**:
   - A **Disjoint Set** (`find` and `union`) efficiently finds the latest available slot for scheduling a job.

3. **Process Each Job Greedily**:
   - Try to schedule the job at its **latest possible deadline**.
   - If no slot is available, discard the job.

Intuition:
- Sorting by profit ensures we always select the most profitable jobs first.
- **Disjoint Set Union-Find** helps efficiently find the nearest available slot in **O(α(N))** time.
- Instead of iterating linearly to find an available slot, **path compression** speeds up slot allocation.

Time Complexity:
- **O(N log N)** → Sorting the jobs.
- **O(N α(N))** → Finding and merging slots using Union-Find.
- **Overall:** **O(N log N)** (since α(N) ≈ constant for practical inputs)

Space Complexity:
- **O(N)** → To store parent array for Disjoint Set.
*/

#include <bits/stdc++.h>
using namespace std;

// Disjoint Set (Union-Find) with Path Compression
class DisJoint {
    vector<int> parent;
public:
    DisJoint(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // Initialize each node as its own parent
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);  // Path compression
    }

    void Union(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();
        vector<pair<int, int>> Jobs;
        int maxDeadline = 0;

        // Store {profit, deadline} pairs and find max deadline
        for (int i = 0; i < n; i++) {
            Jobs.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        // Sort jobs in descending order of profit
        sort(Jobs.rbegin(), Jobs.rend());

        // Disjoint Set to track available slots
        DisJoint ds(maxDeadline);

        int jobCount = 0, totalProfit = 0;

        // Iterate through sorted jobs
        for (auto &[p, d] : Jobs) {
            int availableSlot = ds.find(d);  // Find the latest available slot

            if (availableSlot > 0) {
                ds.Union(availableSlot, availableSlot - 1);  // Mark the slot as used
                totalProfit += p;
                jobCount++;
            }
        }

        return {jobCount, totalProfit};
    }
};

// Driver Code
int main() {
    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> profit = {100, 50, 30, 40, 80};

    Solution obj;
    vector<int> result = obj.jobSequencing(deadline, profit);
    
    cout << "Total Jobs Scheduled: " << result[0] << "\n";
    cout << "Total Profit: " << result[1] << "\n";
    
    return 0;
}