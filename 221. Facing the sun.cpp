/*
Facing the sun
Difficulty: EasyAccuracy: 45.54%Submissions: 57K+Points: 2
Given an array height representing the heights of buildings. You have to count the buildings that will see the sunrise (Assume the sun rises on the side of the array starting point).
Note: The height of the building should be strictly greater than the height of the buildings left in order to see the sun.


Examples :

Input: height = [7, 4, 8, 2, 9]
Output: 3
Explanation: As 7 is the first element, it can see the sunrise. 4 can't see the sunrise as 7 is hiding it. 8 can see. 2 can't see the sunrise. 9 also can see
the sunrise.
Input: height = [2, 3, 4, 5]
Output: 4
Explanation: As 2 is the first element, it can see the sunrise.  3 can see the sunrise as 2 is not hiding it. Same for 4 and 5, they also can see the sunrise.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ height.size() ≤ 106
1 ≤ heighti ≤ 108
*/

/*
Approach:
1. **Linear Scan**:
   - Start by counting the first building because it can always see the sunlight.
   - As we traverse through the array of building heights, if we find a building that is taller than all previously encountered buildings (i.e., has a greater height than the current maximum), we increase the count of buildings that can see sunlight and update the maximum height.

2. **Initial Case**:
   - The first building will always see the sunlight, so we initialize the count to 1 and set the maximum height to the height of the first building.

Time Complexity:
- **O(n)**, where `n` is the number of buildings. We traverse the height array once.

Space Complexity:
- **O(1)**: Only a few variables (`cnt` and `mx`) are used, so the space usage is constant.

*/

class Solution {
public:
    // Returns the count of buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // If there are no buildings, no building can see sunlight
        if(height.empty()) return 0;

        // Initialize count to 1 for the first building, as it always sees sunlight
        int cnt = 1;  
        // Set the maximum height to the height of the first building
        int mx = height[0];
        int n = height.size();

        // Traverse the rest of the buildings
        for(int i = 1; i < n; i++) {
            // If the current building is taller than the maximum seen so far
            if(mx < height[i]) {
                cnt++;  // Increase the count
                mx = height[i];  // Update the maximum height
            }
        }

        return cnt;  // Return the total count of buildings that can see sunlight
    }
};
