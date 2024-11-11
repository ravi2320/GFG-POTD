/*
Make array elements unique
Difficulty: MediumAccuracy: 51.43%Submissions: 54K+Points: 4
Given an array arr[ ], your task is to find the minimum number of increment operations required to make all the elements of the array unique. i.e.- no value in the array should occur more than once. In one operation, a value can be incremented by 1 only.

Examples :

Input: arr[] = [1, 2, 2]
Output: 1
Explanation: If we increase arr[2] by 1 then the resulting array becomes {1, 2, 3} and has all unique values.Hence, the answer is 1 in this case.
Input: arr[] = [1, 1, 2, 3]
Output: 3
Explanation: If we increase arr[0] by 3, then all array elements will be unique. Hence, the answer is 3 in this case.
Input: arr[] = [5, 4, 3, 2, 1]
Output: 0
Explanation: All elements are unique.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
*/

/*
Approach:
1. Sort the array to process duplicates in an orderly manner.
2. Initialize a set to keep track of unique numbers already used and a variable `maxi` to manage the next available unique number.
3. For each element in the array:
   - If the element is already in the set, increment `maxi` and add this new number to the set, keeping track of the difference between the new number and the original element.
   - If it is not in the set, simply add it to the set.
4. The accumulated value in `sum` represents the minimum increments needed to make all elements unique.

Time Complexity: O(n log n) due to sorting, where `n` is the number of elements in the array.
Space Complexity: O(n) for the set used to track unique elements.

*/

class Solution {
public:
    int minIncrements(vector<int>& arr) {
        unordered_set<int> st;
        int maxi = INT_MIN;
        int n = arr.size();
        int sum = 0;

        // Sort array to handle duplicates sequentially
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);

            // If arr[i] is already used, increment `maxi` until it's unique
            if (st.find(arr[i]) != st.end()) {
                maxi++;
                st.insert(maxi);
                sum += maxi - arr[i]; // Add increments to the result
            } else {
                st.insert(arr[i]); // Insert unique element directly
            }
        }

        return sum;
    }
};
