/*
Minimum K Consecutive Bit Flips
Difficulty: HardAccuracy: 69.6%Submissions: 6K+Points: 8
You are given a binary array arr[] (containing only 0's and 1's) and an integer k. In one operation, you can select a contiguous subarray of length k and flip all its bits (i.e., change every 0 to 1 and every 1 to 0).

Your task is to find the minimum number of such operations required to make the entire array consist of only 1's. If it is not possible, return -1.

Examples:

Input: arr = [1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1], k = 2
Output: 4 
Explanation: 4 operations are required to convert all 0's to 1's.
Select subarray [2, 3] and flip all bits resulting array will be [1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1]
Select subarray [4, 5] and flip all bits resulting array will be [1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1]
Select subarray [5, 6] and flip all bits resulting array will be [1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1]
Select subarray [6, 7] and flip all bits resulting array will be [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
Input: arr = [0, 0, 1, 1, 1, 0, 0], k = 3
Output: -1
Explanation: It is not possible to convert all elements to 1's by performing any number of operations.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ k ≤ arr.size()
*/

/*
Approach:
1. Traverse the array from left to right.
2. Maintain a counter `flipCountFromPastForI` to represent how many flips affect the current index.
   - Use a boolean vector `isFliped` to track whether a flip was started at a certain index.
3. At index i:
   - If i >= k and we started a flip at i-k, then remove its effect (since it no longer affects position i).
   - If the current bit (after considering past flips) is 0, we must flip starting from i.
   - If i + k > n, flipping is not possible → return -1.
   - Otherwise, mark flip at i, increment flip counter and flips taken.
4. Return the total flips used.

Intuition:
- Each time we encounter a 0 at position i (after applying previous flips), we must flip the next k bits.
- Flips can overlap, so we track their effect using a sliding window technique.
- This ensures minimal flips are done greedily from left to right.

Time Complexity:
- O(n), since we iterate once over the array and maintain flip effects in O(1) per step.
Space Complexity:
- O(n), due to the `isFliped` array for tracking flip starts.

*/

class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size();
        int flips = 0;  // total flips performed
        int flipCountFromPastForI = 0;  // number of flips affecting current position
        vector<bool> isFliped(n, false); // marks where flips were initiated
        
        for(int i = 0; i < n; i++) {
            // Remove the effect of a flip that no longer affects current index
            if(i >= k && isFliped[i - k] == true) {
                flipCountFromPastForI--;
            }
            
            // If current bit after flips is 0, we need to flip starting at i
            if(flipCountFromPastForI % 2 == arr[i]) {
                // If not enough space left to flip k bits, return -1
                if(i + k > n) {
                    return -1;
                }
                // Start a flip here
                flipCountFromPastForI++;
                flips++;
                isFliped[i] = true;
            }
        }
        
        return flips;
    }
};
