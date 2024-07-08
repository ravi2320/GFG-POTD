/*
Find Nth root of M
Difficulty: EasyAccuracy: 25.06%Submissions: 117K+Points: 2
You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
 

Example 1:

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
Example 2:

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not
integer.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function NthRoot() which takes n and m as input parameter and returns the nth root of m. If the root is not integer then returns -1.
 

Expected Time Complexity: O(n* log(m))
Expected Space Complexity: O(1)
 

Constraints:
1 <= n <= 30
1 <= m <= 109
*/

/*
 * Intuition:
 * To find the n-th root of a number m, we can use a binary search approach to search for an integer k such that k^n = m.
 * If no such integer exists, return -1.
 * 
 * Time Complexity: O(log m * log n), where m is the input number and n is the root. The outer binary search runs in O(log m), and each power computation runs in O(log n) due to repeated multiplication.
 * Space Complexity: O(1), as the solution uses constant extra space.
 */

class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int low = 1;
	    int high = m;
	    
	    while(low <= high){
	        int mid = low + (high - low) / 2;
	        long long midPowN = 1;
	        for(int i = 0; i < n; i++){
	            midPowN *= mid;
	            if(midPowN > m) break;
	        }
	        
	        if(midPowN == m)
	            return mid; // Found exact n-th root.
	        else if(midPowN > m)
	            high = mid - 1; // Move to the left half.
	        else
	            low = mid + 1; // Move to the right half.
	    }
	    
	    return -1; // No integer n-th root found.
	}  
};
