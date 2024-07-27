/*
 Intersection Of Two Sorted Arrays
Easy
40/40
Average time to solve is 10m
Contributed by
557 upvotes
Asked in companies
Problem statement
You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively. Both these arrays are sorted in non-decreasing order. You have to find the intersection of these two arrays.

Intersection of two arrays is an array that consists of all the common elements occurring in both arrays.

Note :
1. The length of each array is greater than zero.
2. Both the arrays are sorted in non-decreasing order.
3. The output should be in the order of elements that occur in the original arrays.
4. If there is no intersection present then return an empty array.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 100
1 <= N, M <= 10^4
0 <= A[i] <= 10^5
0 <= B[i] <= 10^5

Time Limit: 1 sec
Sample Input 1 :
2
6 4
1 2 2 2 3 4
2 2 3 3
3 2
1 2 3
3 4  
Sample Output 1 :
2 2 3
3   
Explanation for Sample Input 1 :
For the first test case, the common elements are 2 2 3 in both the arrays, so we print it.

For the second test case, only 3 is common so we print 3.
Sample Input 2 :
2
3 3 
1 4 5
3 4 5
1 1
3
6
Sample Output 2 :
4 5
-1
*/

/*
Intuition:
The problem is to find the intersection of two sorted arrays, which means finding elements that are present in both arrays. Since the arrays are sorted, we can efficiently find the intersection using a two-pointer technique. This approach involves traversing both arrays simultaneously and comparing their elements. If an element is present in both arrays, it is added to the result list.

Time Complexity:
The time complexity of this approach is O(n + m), where n and m are the lengths of the two input arrays. This is because, in the worst case, we traverse both arrays completely.

Space Complexity:
The space complexity is O(1) for the pointers and auxiliary variables, and O(min(n, m)) for the result list, where n and m are the sizes of the input arrays. This space is required to store the intersection elements.
*/

#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    int i = 0; // Pointer for the first array
    int j = 0; // Pointer for the second array
    vector<int> res; // Result vector to store intersection elements
    
    // Traverse both arrays simultaneously
    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            // If elements match, add to result and move both pointers
            res.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {
            // If arr1[i] is smaller, move the pointer i
            i++;
        }
        else {
            // If arr2[j] is smaller, move the pointer j
            j++;
        }
    }

    return res; // Return the result vector
}
