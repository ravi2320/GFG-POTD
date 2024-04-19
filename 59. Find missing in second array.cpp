/*
Find missing in second array
MediumAccuracy: 35.22%Submissions: 86K+Points: 4
Fast-Track your resumes to top tech companies and get the job you deserve! Register for Job-A-Thon Hiring Challenge  

banner
Given two integer arrays a of size n and b of size m, the task is to find the numbers which are present in the first array a, but not present in the second array b.

Example 1:

Input: 
n = 6, m = 5
a[] = {1, 2, 3, 4, 5, 10}
b[] = {2, 3, 1, 0, 5}
Output: 
4 10
Explanation: 
4 and 10 are present in first array, but not in second array.
Example 2:

Input: 
n = 5, m = 5
a[] = {4, 3, 5, 9, 11}
b[] = {4, 9, 3, 11, 10}
Output: 
5  
Explanation: 
Second array does not contain element 5.
Your Task:
You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function findMissing() that takes an integer array a, an integer array b, an integer n, and an integer m as input parameters and returns an array that contains the missing elements and the order of the elements should be the same as they are in array a.

Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(m).

Constraints:
1 ≤ n, m ≤ 105
-109 ≤ A[i], B[i] ≤ 109
*/

// Intuition:
// This class provides a solution to find missing elements in one array when compared to another array.
// It achieves this by first creating a set of elements present in the second array.
// Then, it iterates through the first array and checks if each element exists in the set.
// If an element is not found in the set, it is added to the answer vector.

// Time Complexity: O(n + m)
// - 'n' is the size of the first array and 'm' is the size of the second array.
// - Constructing the set from the elements of the second array takes O(m) time.
// - Iterating through the first array and checking for missing elements takes O(n) time.
// - Overall time complexity is O(n + m).

// Space Complexity: O(m)
// - The space complexity is dominated by the set storing elements of the second array, which requires O(m) space.

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissing(int a[], int b[], int n, int m) { 
        // Create a set to store elements of array 'b'
        unordered_set<int> st;
        for (int i = 0; i < m; i++) {
            st.insert(b[i]);
        }
        
        // Initialize a vector to store missing elements
        vector<int> ans;
        
        // Iterate through array 'a' and check for missing elements
        for (int i = 0; i < n; i++) {
            if (st.find(a[i]) == st.end()) // Element not found in 'b'
                ans.push_back(a[i]);
        }
        
        return ans;
    } 
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    int a[] = {4, 3, 2, 7, 8, 6};
    int b[] = {4, 3, 1, 7, 8};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    vector<int> result = obj.findMissing(a, b, n, m);
    cout << "Missing elements:";
    for (int x : result) {
        cout << " " << x;
    }
    cout << endl; // Output: Missing elements: 2 6
    return 0;
}
