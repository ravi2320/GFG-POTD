/*
Merge Without Extra Space
Difficulty: HardAccuracy: 32.01%Submissions: 247K+Points: 8
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

Example 1:

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.
Example 2:

Input: 
n = 2, arr1[] = [10 12] 
m = 3, arr2[] = [5 18 20]
Output: 
arr1[] = [5 10]
arr2[] = [12 18 20]
Explanation:
After merging two sorted arrays 
we get 5 10 12 18 20.
Your Task:
You don't need to read input or print anything. You only need to complete the function merge() that takes arr1, arr2, n and m as input parameters and modifies them in-place so that they look like the sorted merged array when concatenated.

Expected Time Complexity:  O((n+m) log(n+m))
Expected Auxilliary Space: O(1)

Constraints:
1 <= n, m <= 105
0 <= arr1i, arr2i <= 107
*/

/**
 * Intuition:
 * - The goal is to merge two sorted arrays into one sorted array without using extra space.
 * - We can use an auxiliary array to hold the merged elements and then copy the results back to the original arrays.
 * - This approach ensures the merged result remains sorted.
 * 
 * Time Complexity:
 * - The time complexity is O(n + m), where n is the size of the first array and m is the size of the second array.
 * - This is because we are iterating through both arrays once.
 *
 * Space Complexity:
 * - The space complexity is O(n + m) due to the auxiliary array used for merging.
 */

class Solution{
    public:
        // Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) { 
            long long i = 0; // Pointer for arr1
            long long j = 0; // Pointer for arr2
            long long idx = 0; // Pointer for the auxiliary array
            long long arr3[n + m]; // Auxiliary array to hold merged elements

            // Merge elements from both arrays in sorted order
            while(i < n && j < m){
                if(arr1[i] <= arr2[j]){
                    arr3[idx++] = arr1[i++];
                }
                else{
                    arr3[idx++] = arr2[j++];
                }
            }

            // If any elements remain in arr1, add them to arr3
            while(i < n){
                arr3[idx++] = arr1[i++];
            }

            // If any elements remain in arr2, add them to arr3
            while(j < m){
                arr3[idx++] = arr2[j++];
            }

            // Copy the merged elements back to arr1 and arr2
            for(int k = 0; k < n + m; k++){
                if(k < n){
                    arr1[k] = arr3[k];
                }
                else{
                    arr2[k - n] = arr3[k];
                }
            }
        } 
};

/**
 * Intuition:
 * - The goal is to merge two sorted arrays into one sorted sequence without using extra space.
 * - By swapping elements between the two arrays, we can ensure that the larger elements of arr1 are moved to arr2 and the smaller elements of arr2 are moved to arr1.
 * - After the swap process, sorting both arrays ensures the merged result remains sorted.
 * 
 * Time Complexity:
 * - The time complexity is O((n + m) log(n + m)) due to the sorting steps.
 *   - Swapping takes O(min(n, m)) time.
 *   - Sorting arr1 takes O(n log n) time.
 *   - Sorting arr2 takes O(m log m) time.
 * 
 * Space Complexity:
 * - The space complexity is O(1) as we are not using any extra space apart from a few variables.
 */

class Solution{
    public:
        // Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) { 
            int left = n - 1; // Pointer for the end of arr1
            int right = 0; // Pointer for the start of arr2
            
            // Swap elements to ensure larger elements of arr1 are moved to arr2
            while (left >= 0 && right < m) {
                if (arr1[left] > arr2[right]) {
                    swap(arr1[left], arr2[right]);
                    left--;
                    right++;
                } else {
                    break;
                }
            }
            
            // Sort both arrays to ensure the merged result is sorted
            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
        } 
};

/**
 * Intuition:
 * - The goal is to merge two sorted arrays into one sorted sequence without using extra space.
 * - We use a variation of the Shell sort algorithm to compare and swap elements across the two arrays.
 * - By iteratively reducing the gap, we ensure that the elements are sorted in place.
 * 
 * Time Complexity:
 * - The time complexity is O((n + m) log(n + m)) due to the multiple passes with decreasing gap sizes.
 * 
 * Space Complexity:
 * - The space complexity is O(1) as we are not using any extra space apart from a few variables.
 */

class Solution{
    private:
        // Helper function to swap elements if the element in arr1 is greater than in arr2
        void swapIfGreater(long long arr1[], long long arr2[], int idx1, int idx2){
            if(arr1[idx1] > arr2[idx2]){
                swap(arr1[idx1], arr2[idx2]);
            }
        }
    public:
        // Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) { 
            int len = n + m; // Total length of both arrays
            int gap = (len / 2) + (len % 2); // Initial gap size
            
            // Loop until gap is greater than 0
            while(gap > 0){
                int left = 0; // Left pointer
                int right = left + gap; // Right pointer
                
                // Traverse the arrays with the current gap
                while(right < len){
                    // Compare and swap elements in arr1 and arr2
                    if(left < n && right >= n){
                        swapIfGreater(arr1, arr2, left, right - n); 
                    }
                    // Compare and swap elements within arr2
                    else if(left >= n){
                        swapIfGreater(arr2, arr2, left - n, right - n);
                    }
                    // Compare and swap elements within arr1
                    else{
                        swapIfGreater(arr1, arr1, left, right);
                    }
                    
                    left++;
                    right++;
                }
                
                // If the gap is 1, break the loop as we are done
                if(gap == 1)
                    break;
                    
                // Reduce the gap for the next pass
                gap = (gap / 2) + (gap % 2);
            }
        } 
};

