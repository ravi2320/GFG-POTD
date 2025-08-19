/*
Farthest Smaller Right

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 50.08%Submissions: 13K+Points: 4
You are given an array arr[]. For each element at index i (0-based indexing), find the farthest index j to the right (i.e., j > i) such that arr[j] < arr[i]. If no such index exists for a given position, return -1 for that index. Return the resulting array of answers.

Examples:

Input: arr[] = [2, 5, 1, 3, 2]
Output: [2, 4, -1, 4, -1]
Explanation: arr[0] = 2: Farthest smaller element to the right is arr[2] = 1.
arr[1] = 5: Farthest smaller element to the right is arr[4] = 2.
arr[2] = 1: No smaller element to the right → -1.
arr[3] = 3: Farthest smaller element to the right is arr[4] = 2.
arr[4] = 2: No elements to the right → -1.
Input: arr[] = [2, 3, 5, 4, 1] 
Output: [4, 4, 4, 4, -1]
Explanation: arr[4] is the farthest smallest element to the right for arr[0], arr[1], arr[2] and arr[3].
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
*/

/*
Approach:
1. Precompute the "nextSmall" array where nextSmall[i] stores the minimum element
   from index i to the end of the array.
   - This helps in quickly knowing the minimum value to the right of any index.
2. For each index i, perform a binary search on the "nextSmall" array (from i+1 to n-1) 
   to find the farthest index j such that nextSmall[j] < arr[i].
   - Binary search is used because nextSmall[] is non-increasing (monotonic).
3. Store j in the answer array; if no such index is found, keep -1.

Intuition:
- We want to find the farthest index `j` (greater than i) such that arr[j] is strictly smaller than arr[i].
- Instead of checking each element to the right (O(N²)), we precompute the running minimum 
  and leverage binary search to achieve efficiency.
- The monotonic nature of `nextSmall` allows binary search, reducing the time complexity.

Time Complexity:
- Precomputing nextSmall: O(N)
- For each index, we do a binary search: O(log N), repeated N times → O(N log N)
- Overall Time Complexity: O(N log N)
- Space Complexity: O(N) for nextSmall and ans arrays
*/

class Solution {
public:
    // Binary search to find farthest index where value < target
    int binarySearch(vector<int> &arr, int low, int high, int target){
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            
            // If arr[mid] is strictly smaller, move right to get farthest
            if(arr[mid] < target){
                ans = mid;
                low = mid + 1;
            }
            else{
                // Otherwise shrink the search space to the left
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Build nextSmall[] storing min from i to end
        vector<int> nextSmall(n);
        nextSmall[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            nextSmall[i] = min(nextSmall[i+1], arr[i]);
        }
        
        // Step 2: For each i, binary search on nextSmall for farthest j
        vector<int> ans(n, -1);
        for(int i=0; i<n-1; i++){
            int idx = binarySearch(nextSmall, i+1, n-1, arr[i]);
            ans[i] = idx;
        }
        
        return ans;
    }
};
