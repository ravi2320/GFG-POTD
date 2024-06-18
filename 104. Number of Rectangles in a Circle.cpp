/*
Number of Rectangles in a Circle
MediumAccuracy: 72.29%Submissions: 6K+Points: 4
Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
Daily rewards up for grabs!

banner
Given a circular sheet of radius, r. Find the total number of rectangles with integral length and width that can be cut from the sheet that can fit on the circle, one at a time.

Examples :

Input: r=1
Output: 1
Explanation: Only 1 rectangle of dimensions 1x1.
Input: r=2
Output: 8
Explanation: The 8 possible rectangles are 
(1x1)(1x2)(1x3)(2x1)(2x2)(2x3)(3x1)(3x2).
Expected Time Complexity: O(r2)
Expected Auxillary Space: O(1)


Constraints:
1<=r<=1000 
*/

/*
Intuition:
- The problem is to find the number of rectangles that can fit inside a circle of radius `r`.
- Each rectangle with sides `a` and `b` must have a diagonal `d` such that `d <= 2*r`.
- Using the Pythagorean theorem, the diagonal `d` can be calculated as `sqrt(a^2 + b^2)`.
- Iterate through all possible values of `a` and `b` and check if the diagonal length satisfies the condition.

Approach:
1. Iterate over all possible lengths `a` and widths `b` from 1 to `2*r`.
2. For each pair (a, b), calculate the diagonal length.
3. If the diagonal length is less than or equal to `2*r`, increment the count.

Time Complexity:
- O((2*r)^2), which simplifies to O(r^2) since we have two nested loops each iterating from 1 to `2*r`.

Space Complexity:
- O(1) because the space used does not depend on the input size and only a few variables are used for computation.

*/

class Solution {
public:
    int rectanglesInCircle(int r) {
        int ans = 0;

        // Iterate through all possible rectangle dimensions
        for(int a = 1; a <= 2*r; a++) {
            for(int b = 1; b <= 2*r; b++) {
                
                // Calculate the diagonal length
                double diagonal = sqrt(a*a + b*b);
                
                // Check if the rectangle can fit inside the circle
                if(diagonal <= 2*r)
                    ans++;
            }
        }

        return ans;
    }
};