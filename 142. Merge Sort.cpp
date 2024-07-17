/*
Merge Sort
Difficulty: MediumAccuracy: 54.1%Submissions: 175K+Points: 4
Given an array arr[], its starting position l and its ending position r. Sort the array using merge sort algorithm.
Example 1:

Input:
N = 5
arr[] = {4 1 3 9 7}
Output:
1 3 4 7 9
Example 2:

Input:
N = 10
arr[] = {10 9 8 7 6 5 4 3 2 1}
Output:
1 2 3 4 5 6 7 8 9 10

Your Task:
You don't need to take the input or print anything. Your task is to complete the function merge() which takes arr[], l, m, r as its input parameters and modifies arr[] in-place such that it is sorted from position l to position r, and function mergeSort() which uses merge() to sort the array in ascending order using merge sort algorithm.

Expected Time Complexity: O(nlogn) 
Expected Auxiliary Space: O(n)

Constraints:
1 <= N <= 105
1 <= arr[i] <= 105

Seen this question in a real interview before ?
Yes
No
Company Tags
PaytmAmazonMicrosoftSnapdealOracleGoldman SachsWiproQualcommBoomerang CommerceGrofersTarget CorporationMedlife
*/

class Solution {
public:
    // Function to merge two sorted halves of an array.
    void merge(int arr[], int l, int m, int r) {
        // Intuition:
        // - We are given two sorted halves of the array: from index l to m and from index m+1 to r.
        // - We need to merge these two sorted halves into a single sorted array.
        
        // Time Complexity: O(r - l + 1)
        // - The time complexity for merging is linear with respect to the number of elements being merged.
        
        // Space Complexity: O(r - l + 1)
        // - We use additional space to store the merged elements, which is linear with respect to the number
        //   of elements being merged.
        
        vector<int> temp;  // Temporary vector to store the merged result
        int left = l;  // Pointer to the left half
        int right = m + 1;  // Pointer to the right half

        // Merge the two halves into the temp vector
        while (left <= m && right <= r) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // Copy remaining elements from the left half, if any
        while (left <= m) {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements from the right half, if any
        while (right <= r) {
            temp.push_back(arr[right]);
            right++;
        }

        // Copy the merged result back into the original array
        for (int i = l; i <= r; i++) {
            arr[i] = temp[i - l];
        }
    }

    // Function to perform merge sort on an array.
    void mergeSort(int arr[], int l, int r) {
        // Intuition:
        // - Merge sort is a divide-and-conquer algorithm that splits the array into halves,
        //   recursively sorts each half, and then merges the sorted halves.
        
        // Time Complexity: O(N log N)
        // - The time complexity for merge sort is O(N log N) where N is the number of elements in the array.
        //   This is because we split the array in half (log N times) and merge the halves (N times).
        
        // Space Complexity: O(N)
        // - The space complexity is O(N) due to the temporary vector used for merging.
        
        // Base case: if the array has one or no elements, it's already sorted
        if (l >= r)
            return;

        // Find the midpoint of the array
        int m = (l + r) / 2;

        // Recursively sort the left half
        mergeSort(arr, l, m);

        // Recursively sort the right half
        mergeSort(arr, m + 1, r);

        // Merge the two sorted halves
        merge(arr, l, m, r);
    }
};
