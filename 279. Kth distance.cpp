/*
Kth distance
Difficulty: EasyAccuracy: 48.69%Submissions: 15K+Points: 2
Given an unsorted array arr and a number k which is smaller than size of the array. Find if the array contains duplicates within k distance.

Examples:

Input: arr[] = [1, 2, 3, 4, 1, 2, 3, 4] and k = 3
Output: false
Explanation: All duplicates are more than k distance away.
Input: arr[] = [1, 2, 3, 1, 4, 5] and k = 3
Output: true
Explanation: 1 is repeated at distance 3.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ k < arr.size()
1 ≤ arr[i] ≤ 105
*/

/*
Approach:
1. Use a sliding window of size `k` to track unique elements within a range of indices in `arr`.
2. Initialize an unordered set `st` to store elements in the current window of size `k`.
3. First, populate the initial window:
   - For each element in the initial window, check if it's already in `st`:
     - If it is, return true, indicating a duplicate exists within the window.
     - Otherwise, insert the element into `st`.
4. For the rest of the elements:
   - Slide the window by removing the element that moves out of the window (`arr[i - k]`).
   - Check if the current element (`arr[i]`) already exists in `st`:
     - If it does, return true for a duplicate within range `k`.
     - If not, insert it into `st`.
5. If no duplicates are found within any window of size `k`, return false.

Time Complexity: O(n), where `n` is the size of the array `arr`.
Space Complexity: O(k), for storing up to `k` elements in the unordered set `st`.
*/

class Solution {
  public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_set<int> st;

        // Populate the initial window of size k
        for (int i = 0; i < k && i < n; i++) {
            if (st.count(arr[i])) 
                return true;  // Duplicate found in the initial window
            st.insert(arr[i]);
        }
        
        // Slide the window across the rest of the array
        for (int i = k; i < n; i++) {

            // Check for duplicates in the current window
            if (st.count(arr[i])) 
                return true;
                
            // Remove the element that is sliding out of the window
            st.erase(arr[i - k]);

            // Insert the new element into the window
            st.insert(arr[i]);
        }

        return false;
    }
};
