/*
Subarray range with given sum
Difficulty: MediumAccuracy: 42.21%Submissions: 39K+Points: 4
Given an unsorted array of integers arr[], and a target tar, determine the number of subarrays whose elements sum up to the target value.

Examples:

Input: arr[] = [10, 2, -2, -20, 10] , tar = -10
Output: 3
Explanation: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].
Input: arr[] = [1, 4, 20, 3, 10, 5] , tar = 33
Output: 1
Explanation: Subarray with sum 33 is: [20,3,10].
Expected Time Complexity: O(n)
Expected Auxilary Space: O(n)

Constraints:
1 <= arr.size() <= 106
-105 <= arr[i] <= 105
-105 <= tar <= 105
*/

/*
Approach:
1. We use a prefix sum technique to calculate the cumulative sum while traversing the array.
2. We keep a hash map that stores how many times each prefix sum has occurred.
3. For each element, we check if the current prefix sum minus the target exists in the map, indicating the existence of a subarray that adds to the target.
4. If the current prefix sum equals the target, it means a valid subarray starts from the beginning.

Time Complexity: O(n), where n is the size of the array.
Space Complexity: O(n), for storing the prefix sums in the hash map.
*/

class Solution {
  public:
    // Function to count the number of subarrays which add to the given sum (tar).
    int subArraySum(vector<int>& arr, int tar) {
        // Hash map to store the frequency of prefix sums
        unordered_map<int, int> mp;
        int sum = 0;  // Variable to maintain the current prefix sum
        int ans = 0;  // Variable to store the number of valid subarrays
        
        // Traverse the array
        for(int &x : arr){
            // Update the current prefix sum
            sum += x;
            
            // If the current prefix sum is equal to the target, increment the count
            if(sum == tar){
                ans++;
            }
            
            // Check if (sum - tar) exists in the hash map, meaning we found a subarray
            if(mp.find(sum - tar) != mp.end()){
                ans += mp[sum - tar];
            }
            
            // Update the frequency of the current prefix sum in the hash map
            mp[sum]++;
        }
        
        return ans;  // Return the total count of valid subarrays
    }
};
