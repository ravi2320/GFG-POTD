/*
Container With Most Water
Difficulty: MediumAccuracy: 53.84%Submissions: 65K+Points: 4
Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.

Note: In the case of a single vertical line it will not be able to hold water.

Examples:

Input: arr[] = [1, 5, 4, 3]
Output: 6
Explanation: 5 and 3 are 2 distance apart. So the size of the base is 2. Height of container = min(5, 3) = 3. So, total area to hold water = 3 * 2 = 6.
Input: arr[] = [3, 1, 2, 4, 5]
Output: 12
Explanation: 5 and 3 are 4 distance apart. So the size of the base is 4. Height of container = min(5, 3) = 3. So, total area to hold water = 4 * 3 = 12.
Input: arr[] = [2, 1, 8, 6, 4, 6, 5, 5]
Output: 25 
Explanation: 8 and 5 are 5 distance apart. So the size of the base is 5. Height of container = min(8, 5) = 5. So, the total area to hold water = 5 * 5 = 25.
Constraints:
1<= arr.size() <=105
1<= arr[i] <=104
*/

/*
Approach:
1. Use the **two-pointer technique** to find the maximum water area:
   - Start with two pointers at the two ends of the array.
   - Calculate the area of water contained between the two bars (width × height).
   - Update the maximum water area (`maxWater`) if the current area is greater.
   - Move the pointer pointing to the smaller bar inward to potentially find a taller bar, 
     as the height of the container is limited by the shorter bar.
2. Continue the process until the two pointers meet.

Intuition:
- The width of the container decreases as the pointers move inward.
- To maximize the area, focus on finding the tallest possible bars while maintaining a significant width.

Time Complexity:
- \(O(n)\): Each pointer moves at most \(n\) steps, where \(n\) is the size of the array.

Space Complexity:
- \(O(1)\): No extra space used apart from a few variables.

Edge Cases:
1. If the array has fewer than two elements, the maximum water area is 0.
2. Arrays with all elements equal still calculate correctly.

*/

class Solution {
public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) return 0; // Edge case: Not enough bars for water storage

        int maxWater = 0; // Initialize maximum water area
        int i = 0, j = n - 1; // Two pointers at the two ends of the array

        // Iterate until the two pointers meet
        while (i < j) {
            int width = j - i; // Width between the two bars
            int height = min(arr[i], arr[j]); // Height is determined by the shorter bar

            // Calculate the current water area and update the maximum
            maxWater = max(maxWater, width * height);

            // Move the pointer pointing to the shorter bar inward
            if (arr[i] < arr[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxWater; // Return the maximum water area
    }
};