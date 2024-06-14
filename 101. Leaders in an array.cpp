/*
Leaders in an array
EasyAccuracy: 29.94%Submissions: 650K+Points: 2
Be the comment of the day in POTD and win a GfG T-Shirt!
Solve right now

banner
Given an array arr of n positive integers, your task is to find all the leaders in the array. An element of the array is considered a leader if it is greater than all the elements on its right side or if it is equal to the maximum element on its right side. The rightmost element is always a leader.

Examples

Input: n = 6, arr[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.
Input: n = 5, arr[] = {10,4,2,4,1}
Output: 10 4 4 1
Explanation: Note that both of the 4s are in output, as to be a leader an equal element is also allowed on the right. side
Input: n = 4, arr[] = {5, 10, 20, 40} 
Output: 40
Explanation: When an array is sorted in increasing order, only the rightmost element is leader.
Input: n = 4, arr[] = {30, 10, 10, 5} 
Output: 30 10 10 5
Explanation: When an array is sorted in non-increasing order, all elements are leaders.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= n <= 107
0 <= arr[i] <= 107
*/

/*
Intuition:
- Leaders in an array are elements that are greater than or equal to all elements to their right.
- To find these leaders efficiently, we can use a backward traversal to keep track of the maximum element encountered so far.
- We will maintain an array (`preArr`) where each element at index `i` stores the maximum element from the subarray starting from index `i+1` to the end.
- This allows us to compare each element with the maximum element to its right and determine if it is a leader.

Approach:
1. Initialize a vector `preArr` to store the maximum element to the right of each index.
2. Traverse the array from right to left, updating `preArr` with the maximum element encountered so far.
3. Traverse the array again and compare each element with the corresponding value in `preArr`.
4. If an element is greater than or equal to the value in `preArr`, it is a leader and is added to the result vector `ans`.

Time Complexity:
- O(n), where n is the number of elements in the array, since we traverse the array twice (once for filling `preArr` and once for identifying leaders).

Space Complexity:
- O(n), due to the additional space used by the `preArr` vector.

*/

class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        // Initialize the preArr to store the maximum elements to the right of each index.
        vector<int> preArr(n);
        preArr[n-1] = 0;
        int greater = arr[n-1];
        
        // Traverse the array from right to left to fill preArr with the maximum elements.
        for(int i=n-2; i>=0; i--){
            if(arr[i+1] > greater)
                greater = arr[i+1];
            preArr[i] = greater;
        }
        
        // Initialize the result vector to store the leaders.
        vector<int> ans;
        
        // Traverse the array and check if the current element is a leader.
        for(int i=0; i<n; i++){
            if(arr[i] >= preArr[i])
                ans.push_back(arr[i]);
        }
        
        return ans;
    }
};


/*
Intuition:
- Leaders in an array are elements that are greater than or equal to all elements to their right.
- By traversing the array from right to left, we can keep track of the maximum element encountered so far.
- If the current element is greater than or equal to this maximum element, it is a leader.

Approach:
1. Initialize `maxi` to a very small value (`INT_MIN`) to track the maximum element encountered.
2. Traverse the array from right to left.
3. For each element, check if it is greater than or equal to `maxi`. If so, add it to the result vector `ans`.
4. Update `maxi` to be the maximum of the current element and `maxi`.
5. Since leaders are added in reverse order (from right to left), reverse the result vector `ans` before returning it.

Time Complexity:
- O(n), where n is the number of elements in the array, since we traverse the array once.

Space Complexity:
- O(1) additional space, aside from the space used to store the result vector.

*/

class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        // Initialize the maximum element to a very small value.
        int maxi = INT_MIN;
        vector<int> ans;
        
        // Traverse the array from right to left.
        for(int i=n-1; i>=0; i--){
            // If the current element is greater than or equal to the maximum encountered, add it to the result.
            if(arr[i] >= maxi)
                ans.push_back(arr[i]);
                
            // Update the maximum element encountered so far.
            maxi = max(maxi, arr[i]);
        }
        
        // Reverse the result vector since leaders were added in reverse order.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
