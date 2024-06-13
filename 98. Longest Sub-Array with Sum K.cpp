/*
Longest Sub-Array with Sum K
MediumAccuracy: 24.64%Submissions: 270K+Points: 4
Be the comment of the day in POTD and win a GfG T-Shirt!
Solve right now

banner
Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

 

Example 1:
 

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.
Example 2:

Input : 
A[] = {-1, 2, 3}
K = 6
Output : 0
Explanation: 
There is no such sub-array with sum 6.
Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function lenOfLongSubarr() that takes an array (A), sizeOfArray (n),  sum (K)and returns the required length of the longest Sub-Array. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1<=N<=105
-105<=A[i], K<=105
*/

/*
Intuition:
- The task is to find the length of the longest subarray with a sum equal to a given value K.
- This can be efficiently achieved using a hashmap to store the cumulative sum and its corresponding index.

Approach:
1. Initialize a hashmap to store the cumulative sum up to each index.
2. Iterate through the array while maintaining a cumulative sum.
3. For each element, calculate the current cumulative sum.
4. If the cumulative sum equals K, update the maximum length of the subarray.
5. If (cumulative sum - K) is found in the hashmap, it means there is a subarray with the sum K ending at the current index. Update the maximum length if necessary.
6. Add the current cumulative sum to the hashmap if it is not already present.

Time Complexity:
- O(N), where N is the number of elements in the array.

Space Complexity:
- O(N), for storing the cumulative sums in the hashmap.

*/

class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int K) {
        // Complete the function
        unordered_map<int, int> mp;
        int maxLen = 0;
        int sum = 0;

        for(int i = 0; i < N; i++) {
            sum += A[i];

            // If the sum equals K, we found a subarray from the start to the current index
            if(sum == K) {
                maxLen = i + 1;
            }

            // If (sum - K) exists in the map, update maxLen if the subarray length is greater
            if(mp.find(sum - K) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum - K]);
            }

            // If the current sum is not in the map, add it with the current index
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};
