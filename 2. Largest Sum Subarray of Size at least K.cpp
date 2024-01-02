/*
Largest Sum Subarray of Size at least K
MediumAccuracy: 37.64%Submissions: 48K+Points: 4
90% Refund available on all premium courses 
Discover How  

banner
Given an array a of length n and a number k, find the largest sum of the subarray containing at least k numbers. It is guaranteed that the size of array is at-least k.

Example 1:

Input : 
n = 4
a[] = {1, -2, 2, -3}
k = 2
Output : 
1
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, -2, 2}
Example 2:
Input :
n = 6 
a[] = {1, 1, 1, 1, 1, 1}
k = 2
Output : 
6
Explanation :
The sub-array of length at-least 2
that produces greatest sum is {1, 1, 1, 1, 1, 1}
Your Task:  
You don't need to read input or print anything. Your task is to complete the function maxSumWithK() which takes the array a[], its size n and an integer k as inputs and returns the value of the largest sum of the subarray containing at least k numbers.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 105
-105 <= a[i] <= 105
1 <= k <= n
*/

class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int ans = INT_MIN;
        long long int last = 0;
        long long int sum = 0;
        long long int j = 0;
        
        for(int i=0; i<n; i++)
        {
            sum += a[i];
            if(i-j+1 == k)
                ans = sum;
            else if(i - j + 1 > k)
            {
                last += a[j];
                j++;
                if(last < 0)
                {
                    sum -= last;
                    last = 0;
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};