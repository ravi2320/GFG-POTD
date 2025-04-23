/*
Unique Number II
Difficulty: MediumAccuracy: 36.9%Submissions: 163K+Points: 4Average Time: 15m
Given an array arr[] containing 2*n + 2 positive numbers, out of which 2*n numbers exist in pairs whereas only two number occur exactly once and are distinct. Find the other two numbers. Return the answer in increasing order.

Examples:

Input: arr[] = [1, 2, 3, 2, 1, 4]
Output: [3, 4] 
Explanation: 3 and 4 occur exactly once.
Input: arr[] = [2, 1, 3, 2]
Output: [1, 3]
Explanation: 1 and 3 occur exactly once.
Input: arr[] = [2, 1, 3, 3]
Output: [1, 2]
Explanation: 1 and 2 occur exactly once.
Constraints:
2 ≤ arr.size() ≤ 106 
1 ≤ arr[i] ≤ 5 * 106
arr.size() is even
*/

/*
Intuition:
We are given an array where every element appears **twice except two unique elements** 
that appear only once. We need to find those two elements.

Approach:
1. Use a hash map to count the frequency of each element in the array.
2. Traverse the hash map and collect elements that have a frequency of 1.
3. Sort the resulting two unique elements in ascending order (as per typical problem constraints).

Time Complexity: O(N log N)
- O(N) to build the frequency map.
- O(N) to traverse the map.
- O(1) to store only two unique elements.
- O(1) for sorting two numbers → technically constant, but sort is called, so counted as O(log N) here conservatively.

Space Complexity: O(N)
- Hash map stores frequency of elements which could be up to N in worst case (all elements are unique).
*/

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        unordered_map<int, int> mp;

        // Count frequency of each number
        for(int &x : arr){
            mp[x]++;
        }

        vector<int> ans;

        // Extract numbers that appear only once
        for(auto &itr : mp){
            if(itr.second == 1){
                ans.push_back(itr.first);
            }
        }

        // Sort the result
        sort(ans.begin(), ans.end());

        return ans;
    }
};
