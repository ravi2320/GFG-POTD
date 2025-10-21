/*
Top K Frequent in Array

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 40.23%Submissions: 104K+Points: 4Average Time: 30m
Given a non-empty integer array arr[]. Your task is to find and return the top k elements which have the highest frequency in the array.

Note: If two numbers have the same frequency, the larger number should be given the higher priority.

Examples:

Input: arr[] = [3, 1, 4, 4, 5, 2, 6, 1], k = 2
Output: [4, 1]
Explanation: Frequency of 4 is 2 and frequency of 1 is 2, these two have the maximum frequency and 4 is larger than 1.
Input: arr[] = [7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9], k = 4
Output: [5, 11, 7, 10]
Explanation: Frequency of 5 is 3, frequency of 11 is 2, frequency of 7 is 2, frequency of 10 is 1.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
1 ≤ k ≤ no. of distinct elements
*/

/*
Time Complexity:
- Iterating through the input array `arr` to count frequencies takes O(n), where n is the size of the array.
- For each element in the frequency map, we insert it into the priority queue. In the worst case, there will be m unique elements, and inserting each into the priority queue takes O(log k) time (since the priority queue will only maintain k elements at any time).
- Extracting the top k elements from the priority queue takes O(k log k) time because we are pushing and popping k elements from the priority queue.

Total time complexity: O(n + m log k), where:
  n = size of the input array `arr`
  m = number of unique elements in the array
  k = number of top frequent elements to return

Space Complexity:
- The space complexity is O(m) due to the frequency map `freq`, where m is the number of unique elements in the array.
- The priority queue will store up to k elements, so it takes O(k) space.

Total space complexity: O(m + k), where:
  m = number of unique elements in the input array
  k = number of top frequent elements to return

Approach:
1. Use an unordered_map to count the frequency of each element in the array.
2. Use a priority queue (min-heap) to store the k most frequent elements.
3. If the size of the heap exceeds k, pop the smallest element to maintain only the k most frequent elements.
4. Extract the elements from the priority queue and reverse the result to return the correct order.
*/

class Solution {
    typedef pair<int, int> P;  // Define P as a pair of integers (frequency, element)
    
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Step 1: Count the frequency of each element in the array
        unordered_map<int, int> freq;
        for(int &x : arr) {
            freq[x]++;
        }
        
        // Step 2: Use a priority queue (min-heap) to keep track of top k frequent elements
        priority_queue<P, vector<P>, greater<P>> pq; // Min-heap of (frequency, element)
        
        for(auto &itr : freq) {
            pq.push({itr.second, itr.first});  // Push frequency and element pair to the heap
            
            // If the heap size exceeds k, remove the smallest element (i.e., the least frequent)
            if(pq.size() > k)
                pq.pop();
        }
        
        // Step 3: Extract elements from the heap and store them in the result vector
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);  // Store the element (not the frequency)
            pq.pop();
        }
        
        // Step 4: Reverse the result vector to return the top k frequent elements in correct order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
