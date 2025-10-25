/*
Minimum Steps to Halve Sum
Difficulty: MediumAccuracy: 62.81%Submissions: 3K+Points: 4
Given an array arr[], find the minimum number of operations required to make the sum of its elements less than or equal to half of the original sum. In one operation, you may replace any element with half of its value (with floating-point precision).

Examples:

Input: arr[] = [8, 6, 2]
Output: 3
Explanation: Initial sum = (8 + 6 + 2) = 16, half = 8
Halve 8 → arr[] = [4, 6, 2], sum = 12 (still 12 > 8)
Halve 6 → arr[] = [4, 3, 2], sum = 9 (still 9 > 8)
Halve 2 → arr[] = [4, 3, 1], sum = 8. 
Input: arr[] = [9, 1, 2]
Output: 2
Explanation: Initial sum = 12, half = 6
Halve 9 → arr[] = [4.5, 1, 2], sum = 7.5 (still > 6)
Halve 4.5 → arr[] = [2.25, 1, 2], sum = 5.25 ≤ 6
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 104
*/

/*
Intuition:
- We are tasked with minimizing the total sum of the array by repeatedly halving the largest element until the sum of the array becomes less than or equal to half of its original sum.
- At each step, we select the largest element from the array, halve it, and replace it in the array, adjusting the total sum accordingly.
- The number of operations is counted as the number of times we halve the largest element.

Time Complexity:
- Initializing the priority queue with `n` elements takes O(n log n) time.
- Each operation involves popping the top of the heap and pushing a new element, both of which are O(log n).
- Since we may perform up to `n` operations, the time complexity is O(n log n).

Space Complexity:
- The space complexity is O(n) because we store the elements in a priority queue.
*/

class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // Calculate the sum of all elements in the array
        double sum = accumulate(arr.begin(), arr.end(), 0.0);
        
        // Calculate the required sum to achieve (half of the original sum)
        double req = sum / 2;
        
        // Create a max-heap (priority_queue by default is a max-heap in C++)
        priority_queue<double> pq;
        
        // Push all elements into the priority queue
        for(int &x : arr){
           pq.push(x); 
        }
        
        // Variable to count the number of operations
        int ans = 0;
        
        // Continue halving the largest element while the sum is greater than the required sum
        while(!pq.empty() && sum > req){
            // Get the largest element from the heap
            double curr = pq.top();
            pq.pop();
            
            // Halve the largest element
            double half = curr / 2;
            
            // Update the total sum by subtracting the halved value and adding the new value
            sum -= half;
            
            // Push the halved element back into the heap
            pq.push(half);
            
            // Increment the operation count
            ans++;
        }
        
        // Return the number of operations required
        return ans;
    }
};
