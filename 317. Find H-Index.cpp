/*
Find H-Index
Difficulty: MediumAccuracy: 53.4%Submissions: 16K+Points: 4
Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.

Examples:

Input: citations[] = [3, 0, 5, 3, 0]
Output: 3
Explanation: There are at least 3 papers (3, 5, 3) with at least 3 citations.
Input: citations[] = [5, 1, 2, 4, 1]
Output: 2
Explanation: There are 3 papers (with citation counts of 5, 2, and 4) that have 2 or more citations. However, the H-Index cannot be 3 because there aren't 3 papers with 3 or more citations.
Input: citations[] = [0, 0]
Output: 0
Constraints:
1 ≤ citations.size() ≤ 106
0 ≤ citations[i] ≤ 106
*/

/*
Approach:
1. The h-index is defined as the maximum value of `h` such that a researcher has at least `h` papers with at least `h` citations each.
2. The problem is solved by:
   - Using a frequency array to count the number of papers with citations in specific ranges.
   - Iterating in reverse to determine the maximum h-index.

Steps:
1. Create a frequency array `freq` of size `n+1`, where `n` is the size of the `citations` array.
   - If a citation count `x` is greater than or equal to `n`, increment `freq[n]`.
   - Otherwise, increment `freq[x]`.
2. Iterate the `freq` array in reverse order, maintaining a cumulative sum `sum` of frequencies.
   - Check if `sum >= i` (at least `i` papers have `i` or more citations).
3. Return `i` as the h-index if the condition is satisfied.

Time Complexity:
- **O(n)**: One pass to build the frequency array and one pass to compute the h-index.

Space Complexity:
- **O(n)**: Additional space for the frequency array.

*/

class Solution {
public:
    // Function to find h-index
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        // Frequency array to count citations
        vector<int> freq(n + 1, 0);

        // Populate frequency array
        for (int &x : citations) {
            if (x >= n) {
                freq[n]++; // Count papers with citations >= n
            } else {
                freq[x]++; // Count papers with citations exactly x
            }
        }

        // Compute h-index
        int sum = 0; // Cumulative sum of papers with citations >= current index
        for (int i = n; i >= 0; i--) {
            sum += freq[i];
            if (sum >= i) {
                return i; // Found h-index
            }
        }

        return 0; // Default case if no h-index is found
    }
};
