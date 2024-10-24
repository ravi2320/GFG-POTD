/*
Modify the Array
Difficulty: EasyAccuracy: 29.5%Submissions: 54K+Points: 2
Given an array arr. Return the modified array in such a way that if the current and next numbers are valid numbers and are equal then double the current number value and replace the next number with 0. After the modification, rearrange the array such that all 0's are shifted to the end.

Note:

Assume ‘0’ as the invalid number and all others as a valid number.
The sequence of the valid numbers is present in the same order.
Example:

Input: arr[] = [2, 2, 0, 4, 0, 8] 
Output: [4, 4, 8, 0, 0, 0] 
Explanation: At index 0 and 1 both the elements are the same. So, we will change the element at index 0 to 4 and the element at index 1 is 0 then we will shift all the zeros to the end of the array. So, the array will become [4, 4, 8, 0, 0, 0].
Input: arr[] = [0, 2, 2, 2, 0, 6, 6, 0, 0, 8] 
Output: [4, 2, 12, 8, 0, 0, 0, 0, 0, 0]
Explanation: At index 5 and 6 both the elements are the same. So, we will change the element at index 5 to 12 and the element at index 6 is 0. We will change the element at index 1 to 4 and the element at index 2 is 0. Then we shift all the zeros to the end of the array. So, array will become [4, 2, 12, 8, 0, 0, 0, 0, 0, 0].
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
*/

/*
Approach:
1. **Modification Step**:
   - Traverse through the array, and whenever two consecutive elements are the same, double the value of the first element and set the second element to 0.
   - This ensures that adjacent duplicates are handled according to the given requirement.

2. **Rearrangement Step**:
   - After modification, we rearrange the array such that all non-zero elements are moved to the front, and zeros are shifted towards the back.
   - This can be done using a two-pointer technique: iterate through the array, and whenever a non-zero element is found, swap it with the element at the pointer indicating the next available position.

Time Complexity: O(n), where n is the size of the array, since we traverse the array twice.
Space Complexity: O(1), as the modifications are done in-place.

*/

class Solution {
  public:
    // Function to modify and rearrange the array as per the given problem
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: Modify the array (merge consecutive equal elements)
        for(int i = 0; i < n - 1; i++) {
            if(arr[i] == arr[i + 1]) {
                arr[i] *= 2;    // Double the value of arr[i]
                arr[i + 1] = 0; // Set arr[i+1] to 0
            }
        }
        
        // Step 2: Rearrange the array (move non-zero elements to the front)
        int j = 0; // Pointer to track the position to place non-zero elements
        for(int i = 0; i < n; i++) {
            if(arr[i] != 0) {
                swap(arr[i], arr[j]); // Move non-zero element to the front
                j++;
            }
        }
        
        return arr; // Return the modified array
    }
};
