/*
Candy
Difficulty: HardAccuracy: 55.27%Submissions: 47K+Points: 8Average Time: 45m
There are n children standing in a line. Each child is assigned a rating value given in the integer array arr[]. You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating than their neighbors get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute.

Note: The answer will always fit into a 32-bit integer.

Examples:

Input: arr[] = [1, 0, 2]
Output: 5
Explanation: Children at index 0 and 2 will get 2 candies each as their rating is higher than index 1, and index 1 will get 1 candy. Thus total candies = 2 + 1 + 2 = 5.
Input: arr[] = [1, 2, 2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively. The third child gets 1 candy because it satisfies the above two conditions.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 109
*/

/*
Approach:
---------
This is a classic two-pass greedy problem.

Rules:
- Each child must have at least 1 candy.
- A child with a higher rating than an adjacent child must get more candies.

Steps:
1. Initialize a candies array with 1 candy for each child.
2. Left to Right pass:
   - If current rating > previous rating,
     give current child one more candy than the previous.
3. Right to Left pass:
   - If current rating > next rating,
     ensure current child has more candies than the next
     (use max to preserve previous assignments).
4. Sum all candies.

Intuition:
----------
The left-to-right pass handles increasing sequences.
The right-to-left pass fixes decreasing sequences.
Using two passes guarantees both adjacency conditions
while keeping the total number of candies minimum.

Time Complexity:
----------------
O(n)
- Two linear passes through the array

Space Complexity:
-----------------
O(n)
- Extra array used to store candies for each child

*/

class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n = arr.size();

        // Each child gets at least one candy
        vector<int> candies(n, 1);

        // Left to right pass
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        int sum = candies[n - 1];

        // Right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }

        return sum;
    }
};
