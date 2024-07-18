/*
Longest alternating subsequence
Difficulty: MediumAccuracy: 38.32%Submissions: 45K+Points: 4
You are given an array arr. Your task is to find the longest length of a good sequence. A good sequence {x1, x2, .. xn} is an alternating sequence if its elements satisfy one of the following relations :

1.  x1 < x2 > x3 < x4 > x5. . . . . and so on
2.  x1 >x2 < x3 > x4 < x5. . . . . and so on

Examples:

Input: arr= [1, 5, 4]
Output: 3
Explanation: The entire sequenece is a good sequence.
Input: arr= [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
Output: 7
Explanation: There are several subsequences that achieve this length. 
One maximum length good subsequences is [1, 17, 10, 13, 10, 16, 8].
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= nums.size() <= 105 
1 <= nums[i] <= 104 
*/

/**
 * Intuition:
 * - The problem requires finding the length of the longest subsequence such that the elements in the subsequence
 *   are alternately increasing and decreasing.
 * - We traverse the array and look for peaks and valleys. A peak is where a number is greater than its previous and next
 *   number, and a valley is where a number is smaller than its previous and next number.
 * - By counting these peaks and valleys, we can determine the length of the longest alternating subsequence.
 *
 * Time Complexity:
 * - The time complexity is O(n), where n is the size of the array. This is because we traverse the array once.
 *
 * Space Complexity:
 * - The space complexity is O(1), as we are using a constant amount of extra space.
 */

class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 1; // If there's only one element, the length is 1.
        if(n == 2) return arr[0] == arr[1] ? 1 : 2; // If there are two elements, check if they are equal or not.

        int ans = 1; // Initialize the answer to 1, as the first element is always counted.
        int prev = arr[0]; // Initialize the previous element to the first element in the array.

        // Iterate through the array from the second element to the second last element.
        for(int i = 1; i < n - 1; i++) {
            // Check if the current element forms a peak or a valley.
            if((prev < arr[i] && arr[i] > arr[i + 1]) || (prev > arr[i] && arr[i] < arr[i + 1])) {
                ans++; // Increment the answer count.
                prev = arr[i]; // Update the previous element to the current element.
            }
        }

        return ans + 1; // Add 1 to account for the last element in the sequence.
    }
};


/**
 * Intuition:
 * - This problem requires finding the length of the longest subsequence where the elements alternate between increasing
 *   and decreasing.
 * - We maintain two variables, `up` and `down`, to keep track of the length of the longest subsequence ending with an
 *   increasing or decreasing pattern, respectively.
 * - As we iterate through the array, we update `up` and `down` based on whether the current element is greater than
 *   or less than the previous element.
 *
 * Time Complexity:
 * - The time complexity is O(n), where n is the size of the array. This is because we traverse the array once.
 *
 * Space Complexity:
 * - The space complexity is O(1), as we are using a constant amount of extra space.
 */

class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Initialize variables to keep track of the longest subsequences
        int up = 1;   // Longest subsequence ending with an increasing pattern
        int down = 1; // Longest subsequence ending with a decreasing pattern
        int n = arr.size(); // Size of the array
        
        // Iterate through the array from the second element
        for(int i = 1; i < n; i++) {
            if(arr[i - 1] < arr[i]) { // If current element is greater than the previous one
                up = down + 1; // Update `up` based on the previous `down` value
            }
            else if(arr[i - 1] > arr[i]) { // If current element is less than the previous one
                down = up + 1; // Update `down` based on the previous `up` value
            }
        }
        
        // The result is the maximum length of the subsequences ending with increasing or decreasing patterns
        return max(up, down);
    }
};
