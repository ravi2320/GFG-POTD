/*
0 - 1 Knapsack Problem
Difficulty: MediumAccuracy: 31.76%Submissions: 431K+Points: 4
You are given weights and values of items, and put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val and wt which represent values and weights associated with items respectively. Also given an integer W which represents knapsack capacity, find out the maximum sum values subset of val[] such that the sum of the weights of the corresponding subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don't pick it (0-1 property).

Examples :

Input: W = 4, val[] = {1,2,3}, wt[] = {4,5,1}
Output: 3
Explanation: Choose the last item that weighs 1 unit and holds a value of 3. 
Input: W = 3, val[] = {1,2,3}, wt[] = {4,5,6}
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
2 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ val[i] ≤ 1000
*/

/*
Intuition:
The problem is a classic example of the 0/1 Knapsack Problem. The objective is to maximize the value of items in a knapsack without exceeding its capacity. For each item, you can either include it in the knapsack or exclude it. We aim to find the optimal combination of items that maximizes the total value without exceeding the given weight capacity.

Approach:
We use dynamic programming (DP) to solve this problem. There are three main approaches:
1. Memoization (Top-Down):
   - Recursively explore each item to decide whether to include it in the knapsack.
   - Use a DP table to store intermediate results and avoid redundant calculations.
2. Tabulation (Bottom-Up):
   - Iteratively build up the solution by solving subproblems first and then constructing the solution for the entire problem.
3. Space Optimization:
   - Optimize the space used in the tabulation approach by only keeping track of the current and previous rows of the DP table.

Time Complexity:
- Memoization: O(n * W), where n is the number of items and W is the capacity of the knapsack.
- Tabulation: O(n * W).
- Space-Optimized Tabulation: O(n * W) with reduced space usage.

Space Complexity:
- Memoization: O(n * W) for the DP table.
- Tabulation: O(n * W) for the DP table.
- Space-Optimized Tabulation: O(W) for the DP array.
*/

class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int fMemo(int idx, int W, vector<int>& wt, vector<int>& val, vector<vector<int>> &dp){
        if(idx == 0){
            if(wt[idx] <= W) return val[idx];
            else return 0;
        }
        
        if(dp[idx][W] != -1){
            return dp[idx][W];
        }
        
        int notTake = 0 + fMemo(idx - 1, W, wt, val, dp);
        
        int take = INT_MIN;
        if(wt[idx] <= W){
            take = val[idx] + fMemo(idx - 1, W - wt[idx], wt, val, dp);
        }
        
        return dp[idx][W] = max(take, notTake);
    }
    
    int fTab(int idx, int W, vector<int>& wt, vector<int>& val){
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        
        for(int i = wt[0]; i <= W; i++) dp[0][i] = val[0];
        
        for(int idx = 1; idx < n; idx++){
            for(int i = 0; i <= W; i++){
                int notTake = 0 + dp[idx - 1][i];
                int take = INT_MIN;
                if(wt[idx] <= i){
                    take = val[idx] + dp[idx - 1][i - wt[idx]];
                }
                dp[idx][i] = max(take, notTake);
            }
        }
        
        return dp[n-1][W];
    }
    
    int fTabOpti(int idx, int W, vector<int>& wt, vector<int>& val){
        int n = wt.size();
        vector<int> prev(W+1, 0), curr(W+1, 0);
        
        for(int i = wt[0]; i <= W; i++) prev[i] = val[0];
        
        for(int idx = 1; idx < n; idx++){
            for(int i = 0; i <= W; i++){
                int notTake = 0 + prev[i];
                int take = INT_MIN;
                if(wt[idx] <= i){
                    take = val[idx] + prev[i - wt[idx]];
                }
                curr[i] = max(take, notTake);
            }
            prev = curr;
        }
        
        return prev[W];
    }
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        /*vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return fMemo(n - 1, W, wt, val, dp);*/
        /*return fTab(n - 1, W, wt, val);*/
        return fTabOpti(n - 1, W, wt, val);
    }
};
