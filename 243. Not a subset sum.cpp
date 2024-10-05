/*
Not a subset sum
Difficulty: MediumAccuracy: 45.92%Submissions: 14K+Points: 4
Given a sorted array arr[] of positive integers, find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.

Examples:

Input: arr[] = [1, 2, 3]
Output: 7
Explanation: 7 is the smallest positive number for which no subset is there with sum 7.
Input: arr[] = [3, 6, 9, 10, 20, 28]
Output: 1
Explanation: 1 is the smallest positive number for which no subset is there with sum 1.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints
1 <= arr.size() <= 106
0 <= arr[i] <= 108
*/

/*
Approach:
1. The problem is to find the smallest positive integer that cannot be represented as a sum of any subset of the given array.
2. We maintain a variable `ans` initialized to 1, which represents the smallest number that we cannot form with the subset sum so far.
3. Traverse the sorted array. For each element:
   - If the current element is larger than `ans`, it means we cannot form `ans` using the current element or any elements before it, so we return `ans`.
   - Otherwise, we update `ans` by adding the current element because it can now form a larger sum.
4. After traversing the entire array, `ans` will hold the smallest number that cannot be formed.

Time Complexity:
- O(n log n) due to sorting the array.
- O(n) for the traversal through the array.

Space Complexity:
- O(1), as we are using a constant amount of extra space.

*/

class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Sort the array
        sort(arr.begin(), arr.end());
        
        // Initialize ans to 1 (the smallest number we are looking for)
        int ans = 1;

        // Traverse through the array
        for(int &x : arr){
            // If the current element is greater than the smallest number we cannot form, return ans
            if(x > ans) return ans;
            // Otherwise, update ans by adding the current element
            ans += x;
        }

        // Return the smallest number that cannot be formed
        return ans;
    }
};
