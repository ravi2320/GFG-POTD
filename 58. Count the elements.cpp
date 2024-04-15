/*
Count the elements
EasyAccuracy: 25.32%Submissions: 54K+Points: 2
Given two arrays a and b both of size n. Given q queries in an array query each having a positive integer x denoting an index of the array a. For each query, your task is to find all the elements less than or equal to a[x] in the array b.

Example 1:

Input:
n = 3
a[] = {4,1,2}
b[] = {1,7,3}
q = 2
query[] = {0,1}
Output : 
2
1
Explanation: 
For 1st query, the given index is 0, a[0] = 4. There are 2 elements(1 and 3) which are less than or equal to 4.
For 2nd query, the given index is 1, a[1] = 1. There exists only 1 element(1) which is less than or equal to 1.
Example 2:

Input:
n = 4
a[] = {1,1,5,5}
b[] = {0,1,2,3}
q = 4
query[] = {0,1,2,3}
Output : 
2
2
4
4
Explanation: 
For 1st query and 2nd query, the given index is 0 and 1 respectively, a[0] = a[1] = 1. There are 2 elements(0 and 1) which are less than or equal to 1. 
For 3rd query and 4th query, the given index is 2 and 3 respectively, a[2] = a[3] = 5. All the 4 elements are less than or equal to 5.   
Your Task:
You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function countElements() that takes array a and b of size n, and array query of size q as parameters and returns an array that contains the answer to the corresponding queries. 

Expected Time Complexity: O(n+q+maximum of a and b).

Expected Auxiliary Space: O(maximum of a and b).

Constraints:
1 ≤ q ≤ n ≤ 105
1 ≤ a[i], b[i] ≤ 105
0 ≤ query[i] < n
*/

/*
Intuition:
- We first find the maximum value in vector b to determine the range of the heap.
- Then, we create a frequency array (heap) to count the occurrences of elements in b.
- Next, we compute the cumulative sum of elements in the heap.
- For each query, we check if the query element exceeds the maximum value in b. If it does, we set the answer to n.
  Otherwise, we set the answer to the cumulative sum of the query element.

Time Complexity: O(n + q + mx)
- n: Size of vector b, used to build the frequency array.
- q: Number of queries, used to process each query.
- mx: Maximum value in vector b, used to determine the range of the heap.

Space Complexity: O(mx)
- We use a heap of size mx + 1 to store the frequency of elements in vector b.
*/

class Solution {
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        // Initialize a variable to store the maximum value in vector b
        int mx = 0;
        // Iterate through vector b to find the maximum value
        for (int i = 0; i < n; i++)
            mx = max(mx, b[i]);
        
        // Initialize a vector to represent a frequency array (heap) to count occurrences of elements in b
        vector<int> heap(mx + 1, 0);
        // Count the occurrences of each element in vector b
        for (int i = 0; i < n; i++)
            heap[b[i]]++;
        
        // Compute the cumulative sum of elements in the heap
        for (int i = 1; i <= mx; i++)
            heap[i] += heap[i - 1];
        
        // Initialize a vector to store the answers to the queries
        vector<int> ans;
        // Process each query
        for (int i = 0; i < q; i++) {
            // If the query element is greater than the maximum value in b, set the answer to n
            if (a[query[i]] > mx)
                ans.push_back(n);
            // Otherwise, set the answer to the cumulative sum of the query element
            else
                ans.push_back(heap[a[query[i]]]);
        }
        
        return ans;
    }
};
