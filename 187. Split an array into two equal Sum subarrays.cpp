/*
Split an array into two equal Sum subarrays
Difficulty: EasyAccuracy: 54.45%Submissions: 29K+Points: 2
Given an array of integers arr, return true if it is possible to split it in two subarrays (without reordering the elements), such that the sum of the two subarrays are equal. If it is not possible then return false.

Examples:

Input: arr = [1, 2, 3, 4, 5, 5]
Output: true
Explanation: In the above example, we can divide the array into two subarrays with eqaul sum. The two subarrays are: [1, 2, 3, 4] and [5, 5]. The sum of both the subarrays are 10. Hence, the answer is true.
Input: arr = [4, 3, 2, 1]
Output: false
Explanation: In the above example, we cannot divide the array into two subarrays with eqaul sum. Hence, the answer is false.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1<=arr.size()<=105 
1<=arr[i]<=106
*/

/*
Intuition:
- The problem asks whether it is possible to split the array into two subarrays with equal sums.
- To do this, we first compute the total sum of the array. If the sum is odd, it's impossible to split the array into two equal parts, so we return `false`.
- If the sum is even, we check if there's a point in the array where the cumulative sum from the start equals half of the total sum. If such a point exists, we can split the array into two parts with equal sums.
- If we find that the cumulative sum exceeds half the total sum before reaching the end, it indicates that no such split is possible, so we return `false`.

Time Complexity:
- The time complexity is O(n), where `n` is the number of elements in `arr`. This is because we traverse the array twice: once to calculate the total sum and once to find the split point.

Space Complexity:
- The space complexity is O(1) as we are using only a few extra variables.

*/

class Solution {
public:
    bool canSplit(vector<int>& arr) {
        int sum = 0;
        
        // Calculate the total sum of the array.
        for(int &x : arr) {
            sum += x;
        }
        
        // If the sum is odd, it's impossible to split the array into two equal parts.
        if(sum % 2 != 0) return false;
        
        int half = sum / 2; // We need to find a subarray with this sum.
        
        // Iterate over the array and check if the cumulative sum equals half the total sum.
        for(int &x : arr) {
            half -= x; 
            
            // If we find a cumulative sum that matches half, return true.
            if(half == 0) return true;
            
            // If the cumulative sum exceeds half, return false.
            if(half < 0) return false;
        }
        
        // If no split point is found, return false.
        return false;
    }
};


/*
Intuition:
- The goal is to determine if the array can be split into two non-empty subarrays such that the sum of the left subarray equals the sum of the right subarray.
- We start with two pointers: one at the beginning of the array (left pointer) and the other at the end (right pointer).
- We maintain two sums: `leftSum` starting with the first element and `rightSum` starting with the last element.
- We increment the left pointer or decrement the right pointer based on which sum is smaller, aiming to balance the sums.
- If at any point `leftSum` equals `rightSum`, it indicates that the array can be split accordingly, so we return `true`.

Time Complexity:
- The time complexity is O(n), where `n` is the number of elements in `arr`. This is because we traverse the array once using two pointers.

Space Complexity:
- The space complexity is O(1) as we are using only a few extra variables.

*/

class Solution {
public:
    bool canSplit(vector<int>& arr) {
        int n = arr.size();
        
        // If the array has only one element, it can't be split into two non-empty subarrays.
        if(n == 1) return false;
        
        int i = 1, j = n - 2;
        int leftSum = arr[0], rightSum = arr[n-1];
        
        // Use two pointers to accumulate sums from both ends of the array.
        while(i <= j){
            if(leftSum < rightSum){
                leftSum += arr[i++];
            } else {
                rightSum += arr[j--];
            }
        }
        
        // Return true if the left and right sums are equal, indicating a valid split.
        return leftSum == rightSum;
    }
};
