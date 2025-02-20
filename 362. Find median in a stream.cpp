/*
Find median in a stream
Difficulty: HardAccuracy: 30.34%Submissions: 126K+Points: 8Average Time: 45m
Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.

Examples:

Input:  arr[] = [5, 15, 1, 3, 2, 8]
Output: [5.0, 10.0, 5.0, 4.0, 3.0, 4.0] 
Explanation: 
After reading 1st element of stream – 5 -> median = 5.0
After reading 2nd element of stream – 5, 15 -> median = (5+15)/2 = 10.0 
After reading 3rd element of stream – 5, 15, 1 -> median = 5.0
After reading 4th element of stream – 5, 15, 1, 3 ->  median = (3+5)/2 = 4.0
After reading 5th element of stream – 5, 15, 1, 3, 2 -> median = 3.0
After reading 6th element of stream – 5, 15, 1, 3, 2, 8 ->  median = (3+5)/2 = 4.0
Input: arr[] = [2, 2, 2, 2]
Output: [2.0, 2.0, 2.0, 2.0]
Explanation: 
After reading 1st element of stream – 2 -> median = 2.0
After reading 2nd element of stream – 2, 2 -> median = (2+2)/2 = 2.0
After reading 3rd element of stream – 2, 2, 2 -> median = 2.0
After reading 4th element of stream – 2, 2, 2, 2 ->  median = (2+2)/2 = 2.0
Constraints:
1 <= arr.size() <= 105
1 <= x <= 106
*/

/**
 * Approach:
 * - We compute the **running median** while iterating through the array.
 * - The naive approach sorts the array every time a new element is added.
 * - This results in **O(N^2)** time complexity, which is inefficient.
 * - A **more optimized approach** uses **two heaps** (min-heap and max-heap) for O(N log N) complexity.
 *
 * Intuition:
 * - We maintain a **sorted order** of elements seen so far.
 * - The median is extracted based on **odd/even count** of elements.
 * - If the count is odd, return the middle element.
 * - If the count is even, return the average of the two middle elements.
 *
 * Time Complexity:
 * - **O(N^2)** due to repeated **insertion sorting**.
 * - Optimal heap-based approach would take **O(N log N)**.
 *
 * Space Complexity:
 * - **O(N)** for storing the running median results.
 */

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        int n = arr.size();
        vector<double> ans;
        
        // Iterate through the array
        for(int i=0; i<n; i++){
            
            // Insertion sorting logic to maintain order
            int j = 0;
            while(j < i){
                if(arr[i] < arr[j]){
                    swap(arr[i], arr[j]);
                }
                j++;
            }
            
            // Determine median based on current length
            if(i % 2 == 0){
                ans.push_back(arr[i / 2]); // Odd size → middle element
            }
            else{
                double median = (arr[(i + 1) / 2] + arr[i / 2]) / 2.0;
                ans.push_back(median); // Even size → average of middle two
            }
        }
        
        return ans;
    }
};

/**
 * Approach:
 * - We use **two heaps** to efficiently find the median of a stream.
 * - **maxHeap** stores the smaller half of the numbers.
 * - **minHeap** stores the larger half of the numbers.
 * - This allows quick retrieval of the median in **O(log N)** time.
 *
 * Intuition:
 * - Maintain a **balanced split** of elements.
 * - If sizes are **equal**, median = average of roots of both heaps.
 * - If sizes are **unequal**, median = root of the larger heap.
 *
 * Time Complexity:
 * - **O(N log N)** due to heap insertions/removals.
 *
 * Space Complexity:
 * - **O(N)** for storing the median results.
 */

class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        int n = arr.size();
        vector<double> ans;
        
        // Min heap (stores larger half)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        // Max heap (stores smaller half)
        priority_queue<int> maxHeap;
        
        for(int i = 0; i < n; i++){
            // Insert element into appropriate heap
            if(maxHeap.empty() || arr[i] <= maxHeap.top()){
                maxHeap.push(arr[i]);
            }
            else{
                minHeap.push(arr[i]);
            }
            
            // Balance the heaps to maintain size property
            if(maxHeap.size() > minHeap.size() + 1){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            else if(minHeap.size() > maxHeap.size()){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            
            // Find median based on heap sizes
            if(maxHeap.size() > minHeap.size()){
                ans.push_back(maxHeap.top()); // Odd count → top of maxHeap
            }
            else{
                ans.push_back((maxHeap.top() + minHeap.top()) / 2.0); // Even count → avg of roots
            }
        }
        
        return ans;
    }
};