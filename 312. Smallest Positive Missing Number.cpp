/*
Smallest Positive Missing Number
Difficulty: MediumAccuracy: 25.13%Submissions: 361K+Points: 4
You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.

Examples:

Input: arr[] = [2, -3, 4, 1, 1, 7]
Output: 3
Explanation: Smallest positive missing number is 3.
Input: arr[] = [5, 3, 2, 5, 1]
Output: 4
Explanation: Smallest positive missing number is 4.
Input: arr[] = [-8, 0, -1, -4, -3]
Output: 1
Explanation: Smallest positive missing number is 1.
Constraints:  
1 <= arr.size() <= 105
-106 <= arr[i] <= 106
*/

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        //CodeGenius
        int n=arr.size();
        for(int i=0;i<n;i++){
            while(arr[i]>=1 && arr[i]<=n && arr[i]!=arr[arr[i]-1]){
                swap(arr[i],arr[arr[i]-1]);
            }
        }
        for(int i=1;i<=n;i++){
            if(i!=arr[i-1]) return i;
        }
        return n+1;
    }
};

/*
Approach:
1. The problem is to find the smallest positive missing number in the array efficiently.
2. Use a variation of the cyclic sort technique to place each positive number in its correct position:
   - Each number `x` in the range `[1, n]` should ideally be at index `x-1`.
3. After sorting the numbers in this manner, traverse the array to identify the first index where the value is incorrect.

Steps:
1. Iterate through the array:
   - If the current number is in the range `[1, n]` and not in its correct position (`arr[i] != arr[arr[i] - 1]`), swap it with the number at its correct position.
2. Traverse the array again to find the first index `i` where `arr[i] != i+1`, which indicates the missing number.
3. If no such index is found, return `n+1` (the smallest number outside the range `[1, n]`).

Time Complexity:
- O(n), where `n` is the size of the array:
  - O(n) for placing numbers in the correct positions (amortized cost for swaps is O(n)).
  - O(n) for the final traversal to find the missing number.

Space Complexity:
- O(1), as no extra space is used apart from variables.

*/

class Solution {
public:
    // Function to find the smallest positive number missing from the array
    int missingNumber(vector<int> &arr) {
        int n = arr.size(); // Size of the array

        // Place each positive number in its correct position
        for (int i = 0; i < n; i++) {
            while (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Check for the first missing positive number
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return i + 1;
            }
        }

        // If all numbers from 1 to n are present, return n + 1
        return n + 1;
    }
};
