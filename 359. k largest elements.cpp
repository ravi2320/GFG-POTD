/*
k largest elements
Difficulty: MediumAccuracy: 53.56%Submissions: 174K+Points: 4
Given an array arr[] of positive integers and an integer k, Your task is to return k largest elements in decreasing order. 

Examples:

Input: arr[] = [12, 5, 787, 1, 23], k = 2
Output: [787, 23]
Explanation: 1st largest element in the array is 787 and second largest is 23.
Input: arr[] = [1, 23, 12, 9, 30, 2, 50], k = 3 
Output: [50, 30, 23]
Explanation: Three Largest elements in the array are 50, 30 and 23.
Input: arr[] = [12, 23], k = 1
Output: [23]
Explanation: 1st Largest element in the array is 23.
Constraints:
1 ≤ k ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
*/

class Solution {
  public:
    /**
     * Approach:
     * - Use a **min-heap (priority queue)** of size `k` to keep track of the `k` largest elements.
     * - Insert elements one by one, and if the heap exceeds size `k`, remove the smallest element.
     * - Extract elements from the heap (which are in ascending order) and reverse the result.
     * 
     * Intuition:
     * - A **min-heap** ensures that the smallest of the `k` largest elements is always at the top.
     * - By maintaining a heap of size `k`, we efficiently track the `k` largest elements.
     * - Extracting elements and reversing them gives the correct descending order.
     * 
     * Time Complexity:
     * - **O(N log K)**: Each insertion/deletion in the heap takes `O(log K)`, and we process `N` elements.
     * - **O(K log K)** for reversing the result.
     * - Overall: **O(N log K)**
     * 
     * Space Complexity:
     * - **O(K)**: Min-heap stores `k` elements at any time.
     * - **O(K)** for the result vector.
     * - Overall: **O(K)**
     */

    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to store k largest elements
        int n = arr.size();
        
        // Insert elements into min-heap
        for(int i = 0; i < n; i++) {
            pq.push(arr[i]);
            
            if(pq.size() > k) { 
                pq.pop(); // Remove the smallest element if heap exceeds size k
            }
        }
        
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top()); // Collect elements from heap
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end()); // Reverse to get descending order
        
        return ans;
    }
};