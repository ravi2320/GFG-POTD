/*
Number of occurrence
Difficulty: EasyAccuracy: 59.34%Submissions: 259K+Points: 2
Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

Examples :

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.
Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106
*/

class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1, start = -1, end = -1;
        
        // Binary search for the start index of the target
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == target) {
                start = mid;
                high = mid - 1; // Move to the left half to find the first occurrence
            }
            else if (arr[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        // If the target is not found, return 0
        if (start == -1) {
            return 0;
        }
        
        // Binary search for the end index of the target
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (arr[mid] == target) {
                end = mid;
                low = mid + 1; // Move to the right half to find the last occurrence
            }
            else if (arr[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        
        // The frequency is the difference between the end and start indices, inclusive
        return end - start + 1;
    }
};