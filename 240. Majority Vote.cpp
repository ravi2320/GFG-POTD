/*
Majority Vote
Difficulty: MediumAccuracy: 48.1%Submissions: 50K+Points: 4
You are given an array of integer nums[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return -1. 

Note: The answer should be returned in an increasing format.

Examples:

Input: nums = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.
Input: nums = [1, 2, 3, 4, 5]
Output: [-1]
Explanation: no candidate occur more than n/3 times.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraint:
1 <= nums.size() <= 106
0 <= nums[i] <= 109
*/

/*
Approach:
- The problem asks to find all the majority elements in the array, where a majority element is defined as an element that appears more than `n/3` times.
- This approach uses **Boyer-Moore Voting Algorithm** to find up to two potential candidates for the majority elements (since a majority element can appear more than `n/3` times and at most two elements can meet this condition).
- The algorithm has two phases:
  1. **Candidate Selection**: Identify two potential candidates (`ele1` and `ele2`) that could be the majority elements.
  2. **Validation**: Validate these candidates by counting their occurrences in the array.

Time Complexity:
- O(n) for traversing the array twice (once for candidate selection and once for validation).
- The overall time complexity is O(n).

Space Complexity:
- O(1), since only a constant amount of extra space is used.

*/

class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;  // Counters for two potential majority elements
        int ele1, ele2;  // Variables to store the two potential candidates

        // Step 1: Candidate Selection using Boyer-Moore Voting Algorithm
        for(int &x : nums) {
            if(cnt1 == 0 && x != ele2) {  // Select first candidate
                cnt1++;
                ele1 = x;
            }
            else if(ele1 == x) {  // If current element matches the first candidate, increase its count
                cnt1++;
            }
            else if(cnt2 == 0) {  // Select second candidate
                cnt2++;
                ele2 = x;
            }
            else if(ele2 == x) {  // If current element matches the second candidate, increase its count
                cnt2++;
            }
            else {  // Decrease the count for both candidates if the current element matches neither
                cnt1--;
                cnt2--;
            }
        }
        
        // Step 2: Validate the candidates
        cnt1 = 0, cnt2 = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(ele1 == nums[i]) cnt1++;  // Count occurrences of the first candidate
            if(ele2 == nums[i]) cnt2++;  // Count occurrences of the second candidate
        }
        
        // Step 3: Store valid majority elements in the result vector
        vector<int> res;
        if(cnt1 > n / 3) res.push_back(ele1);  // Check if the first candidate is a majority element
        if(cnt2 > n / 3 && ele2 != ele1) res.push_back(ele2);  // Check if the second candidate is a majority element
        
        // If no majority element is found, return {-1}
        if(res.empty()) res.push_back(-1);
        
        return res;
    }
};
