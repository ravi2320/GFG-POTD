/*
Count Indices to Balance Even and Odd Sums

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 76.84%Submissions: 5K+Points: 4
Given an array arr[], count the number of indices such that deleting the element at that index and shifting all elements after it one position left results in an array where the sum of elements at even indices equals the sum at odd indices.

Examples:

Input: arr[] = [2, 1, 6, 4]
Output: 1
Explaination: After removing arr[1], the resulting array will be [2, 6, 4] the sums of elements at odd index is arr[1] = 6 and the sum of elements at even index is arr[0] + arr[2] = 6.
Input: arr[] = [1, 1, 1]
Output: 3
Explaination: Removing any element makes the sum of odd and even indexed elements equal.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 104
*/

/*
Approach:
---------
We need to count the number of indices i such that after removing arr[i],
the sum of elements at even indices equals the sum of elements at odd indices.

Key observation:
----------------
When an element at index i is removed, all elements to the right of i
shift one position to the left, which flips their parity (even ↔ odd).

Steps:
------
1. Compute total sums of elements at even indices (evenSum)
   and odd indices (oddSum).
2. Traverse the array index by index and treat each index as a removal point.
3. Maintain:
   - currEvenSum: sum of even-indexed elements to the left of i
   - currOddSum:  sum of odd-indexed elements to the left of i
4. For index i:
   - Remove arr[i] from evenSum or oddSum.
   - After removal:
        New even sum  = currEvenSum + (oddSum - currOddSum)
        New odd sum   = currOddSum  + (evenSum - currEvenSum)
   - Instead of calculating both explicitly, we check:
        evenSum - currEvenSum == oddSum - currOddSum
5. Count how many indices satisfy the condition.

Intuition:
----------
The challenge is handling index parity changes after deletion.
By splitting the array into left and right parts and tracking sums,
we simulate the effect of deletion in O(1) time per index.

Time Complexity:
----------------
O(n) — Single pass through the array.

Space Complexity:
-----------------
O(1) — Only constant extra variables used.

*/

class Solution {
  public:
    int cntWays(vector<int>& arr) {
        long long evenSum = 0, oddSum = 0;
        int n = arr.size();
        
        // Calculate initial even-index and odd-index sums
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                evenSum += arr[i];
            else
                oddSum += arr[i];
        }
        
        long long currEvenSum = 0, currOddSum = 0;
        int ans = 0;
        
        // Try removing each index i
        for (int i = 0; i < n; i++) {
            
            // Remove current element from the right-side sums
            if (i % 2 == 0)
                evenSum -= arr[i];
            else
                oddSum -= arr[i];
                
            // Check if sums become equal after removal
            if (evenSum - currEvenSum == oddSum - currOddSum)
                ans++;
                
            // Add current element to the left-side sums
            if (i % 2 == 0)
                currEvenSum += arr[i];
            else
                currOddSum += arr[i];
        }
        
        return ans;
    }
};
