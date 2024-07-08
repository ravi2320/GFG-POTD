/*
Square root of a number
Difficulty: EasyAccuracy: 54.03%Submissions: 209K+Points: 2
Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

 

Example 1:

Input:
x = 5
Output: 2
Explanation: Since, 5 is not a perfect 
square, floor of square_root of 5 is 2.
Example 2:

Input:
x = 4
Output: 2
Explanation: Since, 4 is a perfect 
square, so its square root is 2.
 

Your Task:
You don't need to read input or print anything. The task is to complete the function floorSqrt() which takes x as the input parameter and return its square root.
Note: Try Solving the question without using the sqrt function. The value of x>=0.

 

Expected Time Complexity: O(log N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ x ≤ 107
*/

/*
 * Intuition:
 * To find the floor of the square root of a given number x, we use a binary search approach.
 * We search for the largest integer `m` such that `m * m <= x`.
 * 
 * Time Complexity: O(log x), where x is the input number. This is due to the binary search approach.
 * Space Complexity: O(1), as the solution uses constant extra space.
 */

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Special case for small values of x.
        if(x <= 3)
            return 1;
        
        long long low = 2;
        long long high = x - 1;
        
        while(low <= high){
            long long mid = low + (high - low) / 2;
            
            long long res = mid * mid;
            
            if(res == x)
                return mid; // Found exact square root.
            else if(res < x)
                low = mid + 1; // Move to the right half.
            else
                high = mid - 1; // Move to the left half.
        }
        
        return high; // `high` will be the floor of the square root.
    }
};
