/*
k largest elements
Difficulty: MediumAccuracy: 53.56%Submissions: 156K+Points: 4
Given an array arr of n positive integers and an integer k, Your task is to return k largest elements in decreasing order. 

Examples

Input: arr[] = {12, 5, 787, 1, 23}, n = 5, k = 2
Output: 787 23
Explanation: 1st largest element in the array is 787 and second largest is 23.
Input: arr[] = {1, 23, 12, 9, 30, 2, 50}, n = 7, k = 3 
Output: 50 30 23
Explanation: 3 Largest element in the array are 50, 30 and 23.
Expected Time Complexity: O(k+(n-k)*logk)
Expected Auxiliary Space: O(k+(n-k)*logk)

Constraints:
1 ≤ k ≤ n ≤ 105
1 ≤ arr[i] ≤ 106
*/

/*
 * Intuition:
 * The problem is to find the k largest elements from an array.
 * The simplest approach is to sort the array in non-decreasing order and then take the last k elements.
 *
 * Time Complexity: O(n log n), where n is the number of elements in the array. This is due to the sorting step.
 * Space Complexity: O(k), for storing the k largest elements in the result vector.
 */

class Solution {
public:
    vector<int> kLargest(int arr[], int n, int k) {
        // Step 1: Sort the array in non-decreasing order
        sort(arr, arr + n);
        
        // Step 2: Create a vector to store the k largest elements
        vector<int> ans;
        
        // Step 3: Add the last k elements from the sorted array to the result vector
        for(int i = n - 1; i >= n - k; i--) {
            ans.push_back(arr[i]);
        }
        
        // Step 4: Return the result vector
        return ans;
    }
};


/*
 * Intuition:
 * The goal is to find the k largest elements in an array. Using a min-heap (priority queue) helps efficiently keep track of the largest k elements as we iterate through the array.
 *
 * Time Complexity: O(n log k), where n is the number of elements in the array. Each insertion and deletion operation in the priority queue (of size k) takes O(log k) time.
 * Space Complexity: O(k), for storing the k largest elements in the priority queue.
 */

class Solution{
public:	
    vector<int> kLargest(int arr[], int n, int k) {
        // Create a min-heap (priority queue) to store the largest k elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // Iterate through each element in the array
        for(int i = 0; i < n; i++) {
            // Push the current element into the priority queue
            pq.push(arr[i]);

            // If the size of the priority queue exceeds k, pop the smallest element
            if(pq.size() > k) {
                pq.pop();
            }
        }

        // Vector to store the k largest elements
        vector<int> res;

        // Extract elements from the priority queue and store them in the result vector
        while(!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        // Reverse the result vector to get the elements in descending order
        reverse(res.begin(), res.end());

        return res;
    }
};


