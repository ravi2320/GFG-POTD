/*
The Painter's Partition Problem-II
Difficulty: HardAccuracy: 27.52%Submissions: 109K+Points: 8
Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.


Example 1:

Input:
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35
Example 2:

Input:
n = 4
k = 2
arr[] = {10,20,30,40}
Output: 60
Explanation: The most optimal way to paint:
Painter 1 allocation : {10,20,30}
Painter 2 allocation : {40}
Job will be complete at time = 60

Your task:
Your task is to complete the function minTime() which takes the integers n and k and the array arr[] as input and returns the minimum time required to paint all partitions.


Expected Time Complexity: O(n log m) , m = sum of all boards' length
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ n ≤ 105
1 ≤ k ≤ 105
1 ≤ arr[i] ≤ 105
*/

/*
 * Intuition:
 * The problem involves determining the minimum time required to paint all boards such that each painter 
 * paints contiguous boards. We use binary search to find the minimum possible time (maximum length a single
 * painter can work without exceeding the total work needed) that can achieve the goal.
 *
 * Time Complexity: O(n * log(S)), where n is the number of boards and S is the sum of all board lengths.
 *   - Binary search runs in log(S) time.
 *   - The `painterRequired` function, which is called within the binary search, iterates through the array of
 *     board lengths once, making it O(n).
 * Space Complexity: O(1), as we use only a few extra variables and no additional data structures.
 */

class Solution {
public:
    // Function to determine the number of painters required for a given max length per painter
    long long painterRequired(int arr[], int n, long long maxLength) {
        long long painters = 1;
        long long currLength = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > maxLength) {
                return maxLength + 1; // If a single board length exceeds maxLength, return an impossible value
            }
            if (currLength + arr[i] <= maxLength) {
                currLength += arr[i];
            } else {
                painters++;
                currLength = arr[i];
            }
        }

        return painters;
    }

    // Main function to find the minimum time required
    long long minTime(int arr[], int n, int k) {
        long long low = *max_element(arr, arr + n); // Minimum possible time is the length of the longest board
        long long high = accumulate(arr, arr + n, 0LL); // Maximum possible time is the sum of all board lengths

        while (low < high) {
            long long mid = low + (high - low) / 2;

            // Check if it's possible to paint all boards with `k` or fewer painters within `mid` time
            if (painterRequired(arr, n, mid) <= k) {
                high = mid; // Adjust high to mid, not mid - 1, to ensure convergence
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
