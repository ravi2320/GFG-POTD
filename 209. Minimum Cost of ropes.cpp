/*
Minimum Cost of ropes
Difficulty: EasyAccuracy: 42.73%Submissions: 208K+Points: 2

Given an array arr containing the lengths of the different ropes, we need to connect these ropes to form one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.  

Examples:

Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation: We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Which makes the array [4, 5, 6]. Cost of this operation 2 + 3 = 5. 
2) Now connect ropes of lengths 4 and 5. Which makes the array [9, 6]. Cost of this operation 4 + 5 = 9.
3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9 + 6 =15
Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 
Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three rope of 3, 2 and 10), then connect 10 and 3 (we gettwo rope of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.
Input: arr[] = [4, 2, 7, 6, 9]
Output: 62 
Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost of this operation 4 + 2 = 6. 
Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12.
Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And
finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.
Expected Time Complexity: O(n logn)
Expected Auxilliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 205
1 ≤ arr[i] ≤ 106
*/

/*
Approach:
1. The problem is similar to the classic Huffman coding problem. To minimize the cost of connecting the ropes, we must always connect the two smallest ropes first.
2. Use a min-heap (priority queue) to keep track of the smallest ropes at any point in time.
3. Repeatedly extract the two smallest ropes, connect them (which incurs a cost equal to the sum of their lengths), and insert the resulting rope back into the heap.
4. Continue this process until only one rope remains in the heap, which will give the minimum cost.

Time Complexity:
- O(n log n): Each insertion and extraction from the priority queue takes O(log n) time, and there are n elements to process.

Space Complexity:
- O(n): We use extra space for the priority queue which holds all elements of the array.

*/

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Min-heap to store the ropes
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        // Push all elements (rope lengths) into the priority queue
        for (long long &x : arr) {
            pq.push(x);
        }
        
        long long minCost = 0;  // Initialize the total cost

        // Repeat until only one rope remains
        while (pq.size() != 1) {
            // Extract the two smallest ropes
            long long minEle = pq.top();
            pq.pop();
            
            long long secMinEle = pq.top();
            pq.pop();
            
            // The cost to connect them is the sum of their lengths
            long long cost = minEle + secMinEle;
            minCost += cost;  // Add the cost to the total
            
            // Insert the combined rope back into the priority queue
            pq.push(cost);
        }
        
        // Return the total minimum cost
        return minCost;
    }
};
