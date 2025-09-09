/*
Assign Mice Holes
Difficulty: EasyAccuracy: 55.93%Submissions: 19K+Points: 2
You are given two arrays mices[] and holes[] of the same size. The array mices[] represents the positions of the mice on a straight line, while the array holes[] represents the positions of the holes on the same line. Each hole can accommodate exactly one mouse. A mouse can either stay in its current position, move one step to the right, or move one step to the left, and each move takes one minute. The task is to assign each mouse to a distinct hole in such a way that the time taken by the last mouse to reach its hole is minimized.

Examples:

Input: mices[] = [4, -4, 2], holes[] = [4, 0, 5] 
Output: 4
Explanation: Assign the mouse at position 4 to the hole at position 4, so the time taken is 0 minutes. Assign the mouse at position −4 to the hole at position 0, so the time taken is 4 minutes. Assign the mouse at position 2 to the hole at position 5, so the time taken is 3 minutes. Hence, the maximum time required by any mouse is 4 minutes.
Input: mices[] = [1, 2], holes[] = [20, 10] 
Output: 18 
Explanation: Assign the mouse at position 1 to the hole at position 10, so the time taken is 9 minutes. Assign the mouse at position 2 to the hole at position 20, so the time taken is 18 minutes. Hence, the maximum time required by any mouse is 18 minutes.
Constraints:
1 ≤ mices.size() = holes.size() ≤ 105
-105 ≤ mices[i] , holes[i] ≤ 105
*/

/*
Approach:
1. Sort both `mices` and `holes`.
   - Sorting ensures that each mouse is paired with the closest available hole.
2. Assign mouse[i] to hole[i] after sorting.
   - This greedy matching minimizes the maximum distance because pairing in order
     avoids creating large mismatches.
3. Track the maximum distance among all pairings.

Intuition:
- If mice and holes are not sorted, pairing could leave some mice far away.
- Sorting ensures the optimal arrangement: the farthest mouse will only need to 
  travel the minimum possible distance given the distribution.
- The result is the maximum distance any mouse travels.

Time Complexity: O(n log n)  
- Sorting both arrays dominates the complexity.

Space Complexity: O(1)  
- Only extra variables used, no additional space beyond input storage.
*/

class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // Step 1: Sort both mice and hole positions
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int n = mices.size();
        int maxi = 0;

        // Step 2: Pair mice[i] with holes[i] and track max distance
        for(int i = 0; i < n; i++){
            int dist = abs(mices[i] - holes[i]);
            maxi = max(maxi, dist);
        }
        
        return maxi; // maximum distance any mouse travels
    }
};