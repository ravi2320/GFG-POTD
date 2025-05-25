/*
Pythagorean Triplet
Difficulty: MediumAccuracy: 24.77%Submissions: 236K+Points: 4Average Time: 20m
Given an array arr[], return true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.

Examples:

Input: arr[] = [3, 2, 4, 6, 5]
Output: true
Explanation: a=3, b=4, and c=5 forms a pythagorean triplet.
Input: arr[] = [3, 8, 5]
Output: false
Explanation: No such triplet possible.
Input: arr[] = [1, 1, 1]
Output: false
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 103
*/

/*
Approach:
- Store the square of each number in an unordered set for O(1) lookups.
- Iterate over all unique pairs (a, b) from the array.
- For each pair, check if (a² + b²) exists in the set.
  - If found, a Pythagorean triplet (a, b, c) exists where c² = a² + b².

Intuition:
- If any three numbers a, b, and c satisfy the condition: a² + b² = c²,
  they form a Pythagorean triplet.
- By precomputing and storing all squares, we can check in constant time
  whether such a number exists for any (a, b) pair.

Time Complexity: O(N^2)
- Outer and inner loops generate all pairs of numbers.

Space Complexity: O(N)
- For storing N squared values in the hash set.
*/

class Solution {
public:
    bool pythagoreanTriplet(vector<int>& arr) {
        unordered_set<long long> st;  // Store squares of all elements

        // Precompute squares of all elements
        for (int &x : arr) {
            st.insert(1LL * x * x);  // Store as long long to avoid overflow
        }

        int n = arr.size();

        // Try all pairs (a, b)
        for (int i = 0; i < n; i++) {
            int a = arr[i];
            for (int j = i + 1; j < n; j++) {
                int b = arr[j];

                long long sumSq = 1LL * a * a + 1LL * b * b;

                // Check if c^2 = a^2 + b^2 exists in the set
                if (st.count(sumSq)) {
                    return true;  // Triplet found
                }
            }
        }

        return false;  // No triplet found
    }
};
