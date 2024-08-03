/*
Longest consecutive subsequence
Difficulty: MediumAccuracy: 33.0%Submissions: 298K+Points: 4
Given an array of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the size of the array as inputs and returns the length of the longest subsequence of consecutive integers. 


Expected Time Complexity: O(R), where R is the maximum integer in the array.
Expected Auxiliary Space: O(N).


Constraints:
1 <= N <= 105
0 <= a[i] <= 105
*/

/*
Intuition:
To find the length of the longest subsequence of consecutive integers, we can first sort the array and then iterate through it to count consecutive elements. We need to handle duplicates by skipping over them.

Time Complexity:
Sorting the array takes O(N log N) time, and iterating through the array takes O(N) time. Therefore, the overall time complexity is O(N log N).

Space Complexity:
The space complexity is O(1) since we are using a constant amount of extra space for variables.

*/

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N) {
        // Sort the array
        sort(arr, arr + N);
        
        int longest = 1; // At least one element is a subsequence
        int cnt = 1;     // Current length of consecutive subsequence
        
        for (int i = 1; i < N; i++) {
            // Check if the current element is consecutive to the previous one
            if (arr[i] == arr[i - 1] + 1) {
                cnt++;
            } 
            // Skip duplicates
            else if (arr[i] != arr[i - 1]) {
                cnt = 1; // Reset count for a new subsequence
            }
            // Update the longest subsequence length
            longest = max(longest, cnt);
        }
        
        return longest;
    }
};


class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
        unordered_set<int> st;
        for(int i=0; i<N; i++){
            st.insert(arr[i]);
        }
        
        int largest = INT_MIN;
        for(auto &itr : st){
            if(st.find(itr - 1) == st.end()){
                int cnt = 1;
                int n = itr;
                while(st.find(n + 1) != st.end()){
                    n += 1;
                    cnt += 1;
                }
                largest = max(largest, cnt);
            }
        }
        return largest;
    }
};