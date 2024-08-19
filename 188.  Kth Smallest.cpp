/*
 Kth Smallest
Difficulty: MediumAccuracy: 35.17%Submissions: 620K+Points: 4
Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. It is given that all array elements are distinct.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output:  7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [7, 10, 4, 20, 15], k = 4 
Output:  15
Explanation: 4th smallest element in the given array is 15.
Expected Time Complexity: O(n+(max_element) )
Expected Auxiliary Space: O(max_element)
Constraints:
1 <= arr.size <= 106
1<= arr[i] <= 106
1 <= k <= n


*/

/*
Intuition:
- The problem requires finding the k-th smallest element in an unsorted array. One efficient way to solve this problem is by using a max-heap (priority queue).
- The idea is to maintain a max-heap of size `k`. As we iterate through the array, we push each element into the heap. If the heap size exceeds `k`, we pop the top element, which is the largest among the k elements currently in the heap.
- At the end of the iteration, the top element of the heap is the k-th smallest element in the array.

Time Complexity:
- The time complexity is O(n log k), where `n` is the number of elements in the array. The log k factor comes from the time required to insert and remove elements from the heap.

Space Complexity:
- The space complexity is O(k), since the heap stores at most `k` elements at any time.

*/

#include <vector>
#include <queue>

class Solution {
  public:
    // arr: given array
    // k: find kth smallest element and return using this function
    int kthSmallest(std::vector<int> &arr, int k) {
        // Max-heap to store the k smallest elements
        std::priority_queue<int> pq;
        
        // Iterate over each element in the array
        for (int &x : arr) {
            pq.push(x); // Push the current element into the heap
            
            // If the heap size exceeds k, remove the largest element
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // The top element of the heap is the k-th smallest element
        return pq.top();
    }
};
