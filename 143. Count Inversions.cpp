/*
Count Inversions
Difficulty: MediumAccuracy: 16.93%Submissions: 522K+Points: 4
Given an array of integers. Find the Inversion Count in the array.  Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum. 

Examples:

Input: n = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
Input: n = 5, arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.
Input: n = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.
Expected Time Complexity: O(nLogn).
Expected Auxiliary Space: O(n).

Constraints:
1 ≤ n ≤ 5*105
1 ≤ arr[i] ≤ 1018
*/

/**
 * Intuition:
 * - The problem of counting inversions can be efficiently solved using the merge sort algorithm.
 * - During the merge step, if an element from the right subarray is smaller than an element from the left subarray,
 *   it indicates that there are inversions. Specifically, all remaining elements in the left subarray are greater
 *   than the current element from the right subarray.
 *
 * Time Complexity:
 * - The time complexity of the merge sort algorithm is O(n log n), where n is the size of the array.
 * - The merge step takes O(n) time, and since we are performing it for each level of recursion, the total time complexity
 *   is O(n log n).
 *
 * Space Complexity:
 * - The space complexity is O(n) due to the temporary array used during the merge step.
 * - Additionally, the recursion stack can go up to O(log n) levels deep.
 */

class Solution {
  public:
    /**
     * Helper function to merge two sorted halves of the array and count inversions.
     * @param arr The input array.
     * @param low The starting index of the first half.
     * @param mid The ending index of the first half.
     * @param high The ending index of the second half.
     * @return The number of inversions found during the merge step.
     */
    long long int merge(long long arr[], long long low, long long mid, long long high){
        vector<long long> temp;
        long long left = low;
        long long right = mid + 1;
        long long cnt = 0;
        
        // Merge the two halves while counting inversions.
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); // Count inversions.
                right++;
            }
        }
        
        // Copy the remaining elements from the left half.
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        
        // Copy the remaining elements from the right half.
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        
        // Copy the sorted elements back into the original array.
        for(long long i = low; i <= high; i++){
            arr[i] = temp[i - low];
        }
        
        return cnt;
    }
    
    /**
     * Helper function to perform merge sort and count inversions.
     * @param arr The input array.
     * @param low The starting index of the subarray.
     * @param high The ending index of the subarray.
     * @return The number of inversions in the array.
     */
    long long int mergeSort(long long arr[], long long low, long long high){
        long long int cnt = 0;
        if(low >= high) return cnt;
        long long mid = low + (high - low) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }
    
    /**
     * Function to count inversions in the array.
     * @param arr The input array.
     * @param n The size of the array.
     * @return The number of inversions in the array.
     */
    long long int inversionCount(long long arr[], int n) {
        return mergeSort(arr, 0, n - 1);
    }
};
