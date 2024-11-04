/*
Find All Triplets with Zero Sum
Difficulty: EasyAccuracy: 54.01%Submissions: 9K+Points: 2
Given an array arr[], find all possible indices [i, j, k] of triplets [arr[i], arr[j], arr[k]] in the array whose sum is equal to zero. Return indices of triplets in any order and all the returned triplets indices should also be internally sorted, i.e., for any triplet indices [i, j, k], the condition i < j < k should hold.

Note: Try to solve this using the O(n2) approach.

Examples:

Input: arr[] = [0, -1, 2, -3, 1]
Output: [[0, 1, 4], [2, 3, 4]]
Explanation: Triplets with sum 0 are:
arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0
Input: arr[] = [1, -2, 1, 0, 5]
Output: [[0, 1, 2]]
Explanation: Only triplet which satisfies the condition is arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0
Input: arr[] = [2, 3, 1, 0, 5]
Output: [[]]
Explanation: There is no triplet with sum 0.
Constraints:
3 <= arr.size() <= 103
-104 <= arr[i] <= 104
*/

/*
Approach:
1. We aim to find all unique triplets in the array that sum to zero.
2. We use a hashmap `mp` to store each number along with its index for quick lookups.
3. For each pair of elements `arr[i]` and `arr[j]`, we calculate the required third element `req = -(arr[i] + arr[j])`.
4. We check if `req` exists in the hashmap and if it has an index greater than `j`, ensuring unique and valid triplets.
5. If such an index `k` exists, we add the triplet `{i, j, k}` to the result list `ans`.

Time Complexity: O(n^2), where `n` is the size of the array due to the nested loops.
Space Complexity: O(n), for the hashmap storing indices of elements in `arr`.
*/

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        unordered_map<int, vector<int>> mp;

        // Store each element with its index in a hashmap
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }
        
        // Iterate through each pair of elements in the array
        for(int i = 0; i < n - 2; i++) {
            for(int j = i + 1; j < n - 1; j++) {
                
                int req = -(arr[i] + arr[j]); // Calculate the required element to form a triplet

                // Check if `req` exists and has an index greater than `j`
                if(mp.find(req) != mp.end()) {
                    for(int k : mp[req]) {
                        if(k > j) { // Ensure the third index is after the second
                            ans.push_back({arr[i], arr[j], arr[k]});
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};