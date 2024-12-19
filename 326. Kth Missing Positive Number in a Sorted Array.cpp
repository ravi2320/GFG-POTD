/*
Kth Missing Positive Number in a Sorted Array
Difficulty: MediumAccuracy: 53.02%Submissions: 15K+Points: 4
Given a sorted array of distinct positive integers arr[], we need to find the kth positive number that is missing from arr[].  

Examples :

Input: arr[] = [2, 3, 4, 7, 11], k = 5
Output: 9
Explanation: Missing are 1, 5, 6, 8, 9, 10… and 5th missing number is 9.
Input: arr[] = [1, 2, 3], k = 2
Output: 5
Explanation: Missing are 4, 5, 6… and 2nd missing number is 5.
Input: arr[] = [3, 5, 9, 10, 11, 12], k = 2
Output: 2
Explanation: Missing are 1, 2, 4, 6… and 2nd missing number is 2.
Constraints:
1 <= arr.size() <= 105
1 <= k <= 105
1 <= arr[i]<= 106
*/

/*
Approach:
1. Traverse through the sorted array `arr` to determine the k-th missing positive integer.
2. Start with the assumption that `k` represents the number we're searching for.
3. For each number `x` in the array:
   - If `x <= k`, increment `k` because `x` fills in one of the missing numbers.
   - Otherwise, break out of the loop since the k-th missing number lies before the next number in the array.
4. Return `k` after processing all relevant elements.

Steps:
1. Iterate over `arr` to account for missing numbers up to each element.
2. Adjust `k` for each element `x` such that `x <= k`.
3. Stop processing once `x > k`.

Time Complexity:
- O(n): Traverse the array once.

Space Complexity:
- O(1): No extra space is used.

Edge Cases:
- Empty array.
- `k` is smaller than the first element in the array.
- `k` is larger than all elements in the array.

*/

class Solution {
public:
    int kthMissing(vector<int> &arr, int k) {
        // Traverse through the array to adjust k
        for (int &x : arr) {
            // If the current array element is less than or equal to k,
            // it means one missing number has been "filled".
            if (x <= k) {
                k++;
            } else {
                // Stop if the current number is greater than k
                break;
            }
        }
        
        // Return the k-th missing number
        return k;
    }
};



Time Complexity:
- O(log n): Binary search over the array.

Space Complexity:
- O(1): No extra space is used.

Edge Cases:
- Empty array.
- k is smaller than the smallest number in the array.
- k is larger than the total number of missing numbers.

*/

class Solution {
public:
  int kthMissing(vector<int> &arr, int k) {
      int n = arr.size();
      int low = 0, high = n - 1;
      
      // Perform binary search
      while (low <= high) {
          int mid = (low + high) / 2;
          
          // Calculate the missing count up to the mid position
          if (arr[mid] - (mid + 1) < k) {
              // Too few missing elements, move right
              low = mid + 1;
          } else {
              // Enough missing elements, move left
              high = mid - 1;
          }
      }
      
      // Calculate the k-th missing number
      return high + 1 + k;
  }
};
