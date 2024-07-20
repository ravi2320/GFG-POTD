/*
Maximum product subset of an array
Difficulty: MediumAccuracy: 17.21%Submissions: 37K+Points: 4
Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.

Note:

The maximum product can be a single element also.
Since the product can be large, return it modulo 109 + 7.
Examples:

Input: arr[] = [-1, 0, -2, 4, 3]
Output: 24
Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
Input: arr[] = [-1, 0]
Output: 0
Explanation: Maximum product will be ( -1 * 0) = 0
Input: arr[] = [5]
Output: 5
Explanation: Maximum product will be 5.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 2 * 104
-10 <= arr[i] <= 10
*/

class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int mini = INT_MIN;
        long long int mod = 1e9+7;
        long long int prod = 1;
        
        for(int n : arr){
            if(n == 0)
                continue;
            else{
                if(n < 0 && mini < n)
                    mini = n;
                
                prod = (prod * n)%mod;
            }
        }
        
        if(prod < 0)
            return (prod / mini)%mod;
            
        return prod%mod;
    }
};