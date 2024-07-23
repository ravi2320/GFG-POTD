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
        long long int pos_prod = 1, neg_prod = 1, pos_cnt = 0, neg_cnt = 0, mod = 1e9+7;
        long long int neg_max = INT_MIN;
        
        if(arr.size() == 1){
            return arr[0];
        }
        
        for(int &x : arr){
            if(x < 0){
                neg_prod = (neg_prod * (long long int)x) % mod;
                neg_max = max(neg_max, (long long int)x);
                neg_cnt++;
            }
            else if(x > 0){
                pos_prod = (pos_prod * (long long int) x) % mod;;
                pos_cnt++;
            }
        }
        
        if(neg_cnt <= 1 && pos_cnt == 0){
            return 0;
        }
        
        if(neg_prod < 0) neg_prod /= neg_max;
        
        return (neg_prod * pos_prod) % mod;
    }
};