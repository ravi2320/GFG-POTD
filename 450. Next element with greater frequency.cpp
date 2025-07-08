/*
Next element with greater frequency
Difficulty: MediumAccuracy: 63.15%Submissions: 11K+Points: 4
Given an array arr[] of integers, for each element, find the closest (distance wise) to its right that has a higher frequency than the current element.
If no such element exists, return -1 for that position.

Examples:

Input: arr[] = [2, 1, 1, 3, 2, 1]
Output: [1, -1, -1, 2, 1, -1]
Explanation: Frequencies: 1 → 3 times, 2 → 2 times, 3 → 1 time.
For arr[0] = 2, the next element 1 has a higher frequency → 1.
For arr[1] and arr[2], no element to the right has a higher frequency → -1.
For arr[3] = 3, the next element 2 has a higher frequency → 2.
For arr[4] = 2, the next element 1 has a higher frequency → 1.
For arr[5] = 1, no elements to the right → -1.
Input: arr[] = [5, 1, 5, 6, 6]
Output: [-1, 5, -1, -1, -1]
Explanation: Frequencies: 1 → 1 time, 5 → 2 times, 6 → 2 times.
For arr[0] and arr[2], no element to the right has a higher frequency → -1.
For arr[1] = 1, the next element 5 has a higher frequency → 5.
For arr[3] and arr[4], no element to the right has a higher frequency → -1.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/

/*
Approach:
- For each element in the array, we want to find the **next element to the right** that has a **higher frequency**.
- We use a **monotonic stack** to keep track of frequency and corresponding values.
- We traverse the array from right to left (reverse) because we are finding the **next greater frequency** on the right.
- If the stack’s top has **less than or equal frequency**, it's not useful — we pop it.
- If the stack’s top has **greater frequency**, it becomes our answer.
- We use a hashmap to count the frequency of each element in the array.

Intuition:
- This is similar to "Next Greater Element" but instead of comparing values directly, we compare the **frequencies**.
- The stack stores `{frequency, value}` pairs and helps us find the next element with **higher frequency** in O(1) amortized time.

Time Complexity: O(n)  
- We loop through the array once and each element is pushed and popped from the stack at most once.

Space Complexity: O(n)  
- For the frequency map, stack, and output array.

*/

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        unordered_map<int, int> freq;  // Stores frequency of each element
        for(int &x : arr){
            freq[x]++;
        }
        
        int n = arr.size();
        vector<int> ans(n, -1);        // Result array initialized with -1
        stack<pair<int, int>> st;      // Stack stores {frequency, value}
        
        // Traverse from right to left
        for(int i = n - 1; i >= 0; i--) {
            // Remove elements with frequency less than or equal to current
            while(!st.empty() && st.top().first <= freq[arr[i]]) {
                st.pop();
            }
            
            // If stack is not empty, top element has greater frequency
            if(!st.empty()) {
                ans[i] = st.top().second;
            }
            
            // Push current element with its frequency
            st.push({freq[arr[i]], arr[i]});
        }
        
        return ans;
    }
};