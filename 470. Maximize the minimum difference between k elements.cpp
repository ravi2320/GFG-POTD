/*
Maximize the minimum difference between k elements
Difficulty: MediumAccuracy: 68.9%Submissions: 8K+Points: 4
Given an array arr[] of integers and an integer k, select k elements from the array such that the minimum absolute difference between any two of the selected elements is maximized. Return this maximum possible minimum difference.

Examples:

Input: arr[] = [2, 6, 2, 5], k = 3
Output: 1
Explanation: 3 elements out of 4 elements are to be selected with a minimum difference as large as possible. Selecting 2, 2, 5 will result in minimum difference as 0. Selecting 2, 5, 6 will result in minimum difference as 6 - 5 = 1.
Input: arr[] = [1, 4, 9, 0, 2, 13, 3], k = 4
Output: 4
Explanation: Selecting 0, 4, 9, 13 will result in minimum difference of 4, which is the largest minimum difference possible.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 106
2 ≤ k ≤ arr.size() 
*/

/*
Approach:
----------
1. Sort the array `arr` since placement of elements is easier when elements are ordered.
2. Use **binary search** on the possible minimum distance (`diff`) between placed elements:
   - The smallest possible distance = 0
   - The largest possible distance = arr[n-1] - arr[0] (between first and last element).
3. For each mid value, check feasibility using `canPlace()`:
   - Place the first element.
   - Iterate through the array and greedily place the next element only if the gap ≥ mid.
   - If we can place at least `k` elements, the distance is feasible.
4. Update result if feasible and try to maximize the distance.

Intuition:
-----------
We are trying to maximize the **minimum distance** between selected elements.  
This is a classic **binary search on answer** problem:
- Guess an answer (mid distance).
- Check if it's possible to place elements with that distance.
- Adjust search space accordingly.

Time Complexity:
-----------------
- Sorting takes **O(N log N)**.
- Binary search runs for **O(log(maxDiff))**, where maxDiff = arr[n-1] - arr[0].
- Each feasibility check (`canPlace`) runs in **O(N)**.
- Total: **O(N log N + N log(maxDiff))**.

Space Complexity:
------------------
- Only uses a few variables for binary search and placement.
- Overall: **O(1)** auxiliary space.

*/

class Solution {
  public:
    // Function to check if we can place at least k elements with minimum distance = diff
    bool canPlace(vector<int> &arr, int diff, int k){
        int cnt = 1; // Place the first element
        int lastPlaced = arr[0]; // Position of last placed element
        
        // Try placing remaining elements
        for(int i=1; i<arr.size(); i++){
            // Place element if distance is at least diff
            if(arr[i] - lastPlaced >= diff){
                cnt++;
                lastPlaced = arr[i];
            }
            
            // If we can place at least k elements, return true
            if(cnt >= k) 
                return true;
        }
        
        return false; // Not possible with this diff
    }
    
    int maxMinDiff(vector<int>& arr, int k) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        int low = 0, high = arr[arr.size()-1] - arr[0];
        int res = 0;
        
        // Step 2: Binary search on possible minimum difference
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(canPlace(arr, mid, k)){
                // If feasible, store result and try larger distance
                res = mid;
                low = mid + 1;
            }
            else{
                // Otherwise, try smaller distance
                high = mid - 1;
            }
        }
        
        return res; // Return maximum minimum difference
    }
};