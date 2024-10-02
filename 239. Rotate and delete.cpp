/*
Rotate and delete
Difficulty: MediumAccuracy: 20.63%Submissions: 38K+Points: 4
Given an array arr integers. Do the following operation until a single element is left. For every kth operation:

Right, rotate the vector clockwise by 1.
Delete the (z– k + 1)th element.
Now, Return the element that is left in the end.
Note: Assume the initial array size to be as z and it will be fixed throughout the operations.

Examples:

Input: arr = [1, 2, 3, 4, 5, 6]
Output: 3
Explanation: Rotate the array clockwise i.e. after rotation the array A = {6, 1, 2, 3, 4, 5} and delete the last element that is {5} that will be A = {6, 1, 2, 3, 4}. Again rotate the array for the second time and deletes the second last element that is {2} that will be A = {4, 6, 1, 3}, doing similar operation when we perform 4th operation, 4th last element does not exist. Then we deletes 1st element ie {1} that will be A = {3, 6}. So, continuing this procedure the last element in A is {3}. So, the output will be 3.
Input: arr = [1, 2, 3, 4]
Output: 2
Explanation: Rotate the vector clockwise i.e. after rotation the vector arr = [4, 1, 2, 3] and delete the last element that is 3 that will be arr = [4, 1, 2]. After doing all the operations, the output will be 2.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 103
1 <= arr[i] <= 106
*/


class Solution {
public:

    int rotateDelete(vector<int> &arr) {
    
        int n = arr.size();
        int temp = n / 2;
        int i = 3 * (temp / 2);
        if(temp % 2) i++;
        
        return arr[n-i];
    }
};
