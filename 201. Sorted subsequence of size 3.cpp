/*
Sorted subsequence of size 3
Difficulty: MediumAccuracy: 25.95%Submissions: 68K+Points: 4
You are given an array arr, you need to find any three elements in it such that arr[i] < arr[j] < arr[k] and i < j < k.

Note:

The output will be 1 if the subsequence returned by the function is present in the array arr
If the subsequence is not present in the array then return an empty array, the driver code will print 0.
If the subsequence returned by the function is not in the format as mentioned then the output will be -1.
Examples :

Input: arr = [1, 2, 1, 1, 3]
Output: 1
Explanation: A subsequence 1 2 3 exist.
Input: arr = [1, 1, 3]
Output: 0
Explanation: No such Subsequence exist, so empty array is returned (the driver code automatically prints 0 in this case).
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 106
*/

/*
**Explanation:**
1. **Problem Statement:** 
   - Find a subsequence of length 3 in an array such that the elements are in increasing order.
   - The task is to find such a triplet (a, b, c) where `a < b < c`.

2. **Approach:**
   - **Two Auxiliary Arrays:** 
     - `leftSmall[i]`: Stores the smallest element to the left of `arr[i]`.
     - `rightMax[i]`: Stores the largest element to the right of `arr[i]`.
   - **Building the Arrays:**
     - Traverse the array once from left to right to fill `leftSmall`.
     - Traverse the array once from right to left to fill `rightMax`.
   - **Finding the Triplet:** 
     - For each element `arr[i]`, check if there exists an element to its left (in `leftSmall`) that is smaller and an element to its right (in `rightMax`) that is larger. If such elements exist, return the triplet.

3. **Time Complexity:** 
   - The solution runs in O(n) time, where `n` is the size of the array.
   - Filling `leftSmall` and `rightMax` takes O(n) each, and finding the triplet also takes O(n).

4. **Space Complexity:** 
   - The space complexity is O(n) due to the use of two additional arrays, `leftSmall` and `rightMax`.

**Example Usage:** 
- Given an array `arr = [1, 2, 3, 4]`, the function will return the triplet `[1, 2, 3]`.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find a triplet such that a < b < c.
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        vector<int> leftSmall(n, 0), rightMax(n, 0);

        // Fill the leftSmall array with the minimum element to the left of each position.
        leftSmall[0] = arr[0];
        for(int i = 1; i < n; i++){
            leftSmall[i] = min(leftSmall[i - 1], arr[i]);
        }

        // Fill the rightMax array with the maximum element to the right of each position.
        rightMax[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

        // Find the triplet (a, b, c) where a < b < c.
        for(int i = 1; i < n - 1; i++){
            if(leftSmall[i - 1] < arr[i] && arr[i] < rightMax[i + 1]){
                return {leftSmall[i - 1], arr[i], rightMax[i + 1]};
            }
        }

        // If no such triplet is found, return an empty vector.
        return {};
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<int> arr = {1, 2, 1, 3};
    vector<int> result = sol.find3Numbers(arr);

    if(!result.empty()) {
        cout << "Found triplet: ";
        for(int x : result) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << "No triplet found." << endl;
    }

    return 0;
}
