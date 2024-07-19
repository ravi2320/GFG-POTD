/*
Count Smaller elements
Difficulty: HardAccuracy: 38.16%Submissions: 55K+Points: 8
Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].

Examples:

Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
Output: [6, 1, 1, 1, 0, 1, 0]
Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.
Input: arr[] = [1, 2, 3, 4, 5]
Output: [0, 0, 0, 0, 0]
Explanation: There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.
Expected Time Complexity: O(n*logn)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i]  ≤ 108
*/

/**
 * Intuition:
 * - To construct the count of smaller elements to the right of each element, we can leverage binary search on a sorted array.
 * - For each element in the original array, we find its position in the sorted array using binary search.
 * - The index in the sorted array represents the count of smaller elements that have already been seen.
 * - After counting, we remove the element from the sorted array to ensure correctness for subsequent elements.
 * 
 * Time Complexity:
 * - The time complexity is O(n^2) in the worst case. This is because for each element in the original array, we perform a binary search (O(log n)) and an erase operation (O(n)).
 *
 * Space Complexity:
 * - The space complexity is O(n), where n is the number of elements in the input array. This is due to the additional array 'temp' used for sorting and binary search operations.
 */

class Solution {
public:
    // Binary search function to find the leftmost occurrence of target in sorted array arr
    int binarySearch(vector<int> &arr, int target){
        int low = 0;
        int high = arr.size() - 1;
        int idx = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(arr[mid] == target){
                idx = mid;
                high = mid - 1; // Move left to find the first occurrence
            }
            else if(arr[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return idx;
    }

    // Function to construct the count of smaller elements to the right of each element
    vector<int> constructLowerArray(vector<int> &arr) {
        vector<int> ans; // Result array to store counts
        vector<int> temp(arr.begin(), arr.end()); // Temporary array for sorting

        sort(temp.begin(), temp.end()); // Sort the temporary array

        // Iterate through each element in the original array
        for(int &num : arr){
            int idx = binarySearch(temp, num); // Find the index of the current element in the sorted array
            ans.push_back(idx); // Add the index to the result array
            temp.erase(temp.begin() + idx); // Remove the element from the sorted array
        }

        return ans; // Return the result array
    }
};


/**
 * Intuition:
 * - To count the number of smaller elements to the right of each element, we can use a modified merge sort.
 * - During the merge step, if we encounter an element from the right half that is smaller than an element from the left half,
 *   it means that this element and all subsequent elements in the right half are smaller than the current element in the left half.
 * - We use an auxiliary array 'indexes' to keep track of the original indices of the elements and a 'count' array to store the result.
 * 
 * Time Complexity:
 * - The time complexity is O(n log n), where n is the number of elements in the input array. This is because we use merge sort, which has O(n log n) complexity.
 *
 * Space Complexity:
 * - The space complexity is O(n), where n is the number of elements in the input array. This is due to the additional arrays used for temporary storage during merging.
 */

class Solution {
public:
    // Merge function to merge two halves and count the number of smaller elements
    void merge(vector<int> &arr, int low, int mid, int high, vector<int> &count, vector<int> &indexes) {
        vector<int> temp(high - low + 1); // Temporary array for sorted elements
        vector<int> tempIndexes(high - low + 1); // Temporary array for indexes
        int left = low, right = mid + 1, k = 0;

        // Merge the two halves while counting the number of smaller elements
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[k] = arr[left];
                tempIndexes[k] = indexes[left];
                count[indexes[left]] += (right - mid - 1); // Count the elements that are smaller
                left++;
            } else {
                temp[k] = arr[right];
                tempIndexes[k] = indexes[right];
                right++;
            }
            k++;
        }

        // Copy the remaining elements from the left half
        while (left <= mid) {
            temp[k] = arr[left];
            tempIndexes[k] = indexes[left];
            count[indexes[left]] += (right - mid - 1); // Count the elements that are smaller
            left++;
            k++;
        }

        // Copy the remaining elements from the right half
        while (right <= high) {
            temp[k] = arr[right];
            tempIndexes[k] = indexes[right];
            right++;
            k++;
        }

        // Copy the sorted elements and their indexes back to the original arrays
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
            indexes[i] = tempIndexes[i - low];
        }
    }

    // Merge sort function to recursively sort and count the number of smaller elements
    void mergeSort(vector<int>& arr, int low, int high, vector<int> &count, vector<int> &indexes) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid, count, indexes);
        mergeSort(arr, mid + 1, high, count, indexes);

        merge(arr, low, mid, high, count, indexes);
    }

    // Main function to construct the count of smaller elements array
    vector<int> constructLowerArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(n, 0); // Array to store the count of smaller elements
        vector<int> indexes(n); // Array to store the original indexes of the elements
        
        // Initialize the indexes array
        for (int i = 0; i < n; ++i) {
            indexes[i] = i;
        }

        // Perform merge sort and count the number of smaller elements
        mergeSort(arr, 0, n - 1, count, indexes);

        return count; // Return the count of smaller elements array
    }
};
