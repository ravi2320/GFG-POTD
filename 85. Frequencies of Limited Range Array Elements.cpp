/*
Frequencies of Limited Range Array Elements
EasyAccuracy: 27.64%Submissions: 249K+Points: 2
Given an array arr[] of N positive integers which can contain integers from 1 to P where elements can be repeated or can be absent from the array. Your task is to count the frequency of all numbers from 1 to N. Make in-place changes in arr[], such that arr[i] = frequency(i). Assume 1-based indexing.
Note: The elements greater than N in the array can be ignored for counting and do modify the array in-place. 

Example 1:

Input:
N = 5
arr[] = {2, 3, 2, 3, 5}
P = 5
Output:
0 2 2 0 1
Explanation: 
Counting frequencies of each array element
We have:
1 occurring 0 times.
2 occurring 2 times.
3 occurring 2 times.
4 occurring 0 times.
5 occurring 1 time.
Example 2:

Input:
N = 4
arr[] = {3,3,3,3}
P = 3
Output:
0 0 4 0
Explanation: 
Counting frequencies of each array element
We have:
1 occurring 0 times.
2 occurring 0 times.
3 occurring 4 times.
4 occurring 0 times.
Example 3:

Input:
N = 2
arr[] = {8,9}
P = 9
Output:
0 0
Explanation: 
Counting frequencies of each array element
We have:
1 occurring 0 times.
2 occurring 0 times.
Since here P=9, but there are no 9th Index present so can't count the value.
Your Task:
You don't need to read input or print anything. Complete the function frequencyCount() that takes the array arr, and integers n, and p as input parameters and modify the array in-place to denote the frequency count of each element from 1 to N.

Expected time complexity: O(N)
Expected auxiliay space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ P ≤ 4*104 
1 <= arr[i] <= P
*/

/*
Intuition:
- We need to count the frequency of each element from 1 to N in the given array and store the result back in the array.
- Since the array elements might be out of the range [1, N], we need to handle such cases properly.
- We can use an auxiliary frequency array to count the occurrences of each valid element in the range.

Approach:
1. Initialize a frequency array of size N with all elements set to 0.
2. Iterate through the given array and for each element, if it lies within the range [1, N], increment the corresponding index in the frequency array.
3. After processing all elements, update the original array with the frequency counts from the auxiliary frequency array.

Time Complexity: O(N)
- We iterate through the array twice, once to count the frequencies and once to update the original array. Thus, the time complexity is linear in terms of the size of the array, O(N).

Space Complexity: O(N)
- We use an auxiliary frequency array of size N to store the frequency counts. Thus, the space complexity is O(N).
*/

class Solution{
    public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P)
    { 
        // Auxiliary array to store frequency counts
        vector<int> freq(N, 0);

        // Counting the frequency of each element within the range [1, N]
        for (int i = 0; i < N; i++) {
            if (arr[i] - 1 < N)
                freq[arr[i] - 1]++;
        }

        // Updating the original array with the frequency counts
        for (int i = 0; i < N; i++) {
            arr[i] = freq[i];
        }
    }
};
