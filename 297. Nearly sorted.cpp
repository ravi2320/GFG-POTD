/*
Nearly sorted
Difficulty: MediumAccuracy: 75.25%Submissions: 60K+Points: 4
Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
Note: You need to change the given array arr[] in place.

Examples:

Input: arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
Output: [2, 3, 5, 6, 8, 9, 10]
Explanation: The sorted array will be 2 3 5 6 8 9 10
Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: The sorted array will be 1 2 3 4 5 6 7 8 9 10
DO NOT use the direct library sort() function for this question.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ k < arr.size()
1 ≤ arri ≤ 106
*/

/*
Approach:
1. The problem involves sorting a nearly sorted array where every element is at most `k` positions away from its target position.
2. A min-heap (priority queue) is used to efficiently extract the smallest element within a window of size `k`.
3. We iterate over the array, pushing elements into the min-heap:
   - If the heap size exceeds `k`, the top (smallest) element is popped and placed at the correct position in the array.
4. After the loop, any remaining elements in the heap are extracted and placed back into the array in sorted order.

Functions:
- `nearlySorted`: Sorts the array in-place using a min-heap.

Time Complexity:
- O(n log k), where `n` is the number of elements in the array.
  - Each insertion and extraction operation on the min-heap of size `k` takes `log k` time.

Space Complexity:
- O(k) for the priority queue.

*/

class Solution {
public:
    // Function to sort a nearly sorted array using a min-heap
    void nearlySorted(vector<int>& arr, int k) {
        // Min-heap to store elements
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int idx = 0; // Index to insert sorted elements back into the array
        
        // Iterate over the elements in the array
        for(int &x : arr) {
            pq.push(x); // Insert current element into the heap
            
            // If the heap size exceeds `k`, extract the minimum element
            if(pq.size() > k) {
                arr[idx++] = pq.top(); // Place the minimum element in the correct position
                pq.pop(); // Remove the top element
            }
        }
        
        // Extract remaining elements from the heap and insert into the array
        while(!pq.empty()) {
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};
