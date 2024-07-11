/*
Allocate Minimum Pages
Difficulty: MediumAccuracy: 35.51%Submissions: 195K+Points: 4
You have n books, each with arr[i] a number of pages. m students need to be allocated contiguous books, with each student getting at least one book.
Out of all the permutations, the goal is to find the permutation where the sum of the maximum number of pages in a book allotted to a student should be the minimum, out of all possible permutations.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Examples:

Input: n = 4, arr[] = [12, 34, 67, 90], m = 2
Output: 113
Explanation: Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90} Maximum Pages =113.
Therefore, the minimum of these cases is 113, which is selected as the output.
Input: n = 3, arr[] = [15, 17, 20], m = 5
Output: -1
Explanation: Allocation can not be done.
Expected Time Complexity: O(n logn)
Expected Auxilliary Space: O(1)

Constraints:
1 <=  n, m <= 105
1 <= arr[i] <= 106                       
*/

/*
 * Intuition:
 * To determine the minimum number of pages to allocate to m students, we use binary search.
 * We try to minimize the maximum number of pages allocated to a student.
 *
 * Time Complexity: O(n log(sum - max_element)), where n is the number of books.
 * Space Complexity: O(1) excluding input and output storage.
 */

int bookAllocated(vector<int>& arr, int pages) {
    int cnt = 1;
    int last = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (last + arr[i] <= pages) {
            last += arr[i];
        } else {
            cnt++;
            last = arr[i];
        }
    }
    return cnt;
}

int findPages(vector<int>& arr, int n, int m) {
    // If the number of students is more than the number of books, return -1
    if (m > n) return -1;

    // The lower bound of pages is the maximum element in the array
    int low = *max_element(arr.begin(), arr.end());
    // The upper bound of pages is the sum of all elements in the array
    int high = accumulate(arr.begin(), arr.end(), 0);

    // Binary search to find the minimum maximum pages
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (bookAllocated(arr, mid) <= m) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}
