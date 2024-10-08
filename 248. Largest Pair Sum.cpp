/*
Largest Pair Sum
Difficulty: EasyAccuracy: 69.64%Submissions: 8K+Points: 2
Find the largest pair sum in an array of distinct integers.

Examples :

Input: arr[] = [12, 34, 10, 6, 40]
Output: 74
Explanation: Sum of 34 and 40 is the largest, i.e, 34 + 40 = 74.
Input: arr[] = [10, 20, 30]
Output: 50
Explanation: 20 + 30 = 50.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
*/

/*
Approach:
1. **Iterating through the array**:
   - We maintain two variables, `max` and `secMax`, to keep track of the largest and second largest distinct elements in the array.
   - If the current element `x` is greater than the current maximum, we update `secMax` to be `max`, and then update `max` to the new value.
   - If the current element is smaller than `max` but greater than `secMax`, we update `secMax` to that value.

2. **Time Complexity**:
   - **O(n)**: We only traverse the array once, comparing and updating the two largest distinct values.

3. **Space Complexity**:
   - **O(1)**: Only a few variables are used to track the maximum and second maximum, so the space complexity is constant.

Edge cases:
- Arrays with fewer than two distinct elements should return an appropriate value, e.g., if all elements are the same or if the array has fewer than two elements.

*/

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // Initialize max and secMax to track the two largest distinct numbers
        int max = -1, secMax = -1;
        
        // Iterate over the array to find the two largest distinct elements
        for(int &x : arr){
            if(x > max){
                // Update secMax to be max before updating max
                secMax = max;
                max = x;
            }
            else if(x < max && x > secMax){
                // Update secMax only if the element is less than max and greater than secMax
                secMax = x;
            }
        }
        
        // Return the sum of the two largest distinct elements
        return max + secMax;
    }
};
