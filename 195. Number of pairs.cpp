/*
Number of pairs
Difficulty: MediumAccuracy: 21.82%Submissions: 70K+Points: 4
Given two positive integer arrays arr and brr, find the number of pairs such that xy > yx (raised to power of) where x is an element from arr and y is an element from brr.

Examples :

Input: arr[] = [2, 1, 6], brr[] = [1, 5]
Output: 3
Explanation: The pairs which follow xy > yx are: 21 > 12,  25 > 52 and 61 > 16 .
Input: arr[] = [2 3 4 5], brr[] = [1 2 3]
Output: 5
Explanation: The pairs which follow xy > yx are: 21 > 12 , 31 > 13 , 32 > 23 , 41 > 14 , 51 > 15 .
Expected Time Complexity: O((N + M)log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ arr.size(), brr.size() ≤ 105
1 ≤ brr[i], arr[i] ≤ 103
*/

/*
Intuition:
The problem requires counting the number of valid pairs (x, y) such that x is from the first array and y is from the second array, and the condition x^y > y^x holds true. Given the nature of the comparison between powers, certain patterns and special cases (like when x or y equals 1, 2, 3, or 4) can be leveraged to simplify the solution.

Approach:
1. **Binary Search**:
   - Sort the second array and use binary search to efficiently count the number of elements in the second array that satisfy the condition for each element in the first array.
2. **Special Cases**:
   - Handle special cases where x or y equals 1, 2, 3, or 4 as these have specific impacts on the inequality x^y > y^x.
3. **Counting Valid Pairs**:
   - Iterate through each element in the first array and compute the number of valid pairs using the precomputed data and the binary search result.

Time Complexity:
- Sorting the second array: O(M log M), where M is the size of the second array.
- Processing each element in the first array using binary search: O(N log M), where N is the size of the first array.
- Overall time complexity: O(M log M + N log M).

Space Complexity:
- O(1) additional space, excluding the space needed for the input arrays.

*/

class Solution {
  public:
    // Function to perform binary search to find the index in brr
    int binarySearch(int x, vector<int> &brr){
        int low = 0, high = brr.size() - 1;
        
        // Perform binary search to find the largest element less than or equal to x
        while(low <= high){
            int mid = (low + high) / 2;
            if(brr[mid] <= x){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return high; // Return the index of the largest element less than or equal to x
    } 
    
    // Function to count valid pairs where x^y > y^x
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        long long ans = 0, one = 0, two = 0, threeFour = 0;
        
        // Sort the second array
        sort(brr.begin(), brr.end());
        
        // Count occurrences of 1, 2, and (3 or 4) in brr
        for(auto x : brr){
            if(x == 1) one++;
            else if(x == 2) two++;
            else if(x == 3 || x == 4) threeFour++;
        }
        
        int m = brr.size();
        // Iterate through each element in arr to find valid pairs
        for(auto x : arr){
            if(x != 1){
                ans += one; // Any pair (x, 1) where x != 1 is valid
                if(x == 2) ans -= threeFour; // Special case: x == 2 and y == 3 or 4 leads to invalid pairs
                if(x == 3) ans += two; // Special case: x == 3 and y == 2 leads to a valid pair
                int idx = binarySearch(x, brr); // Find the number of valid pairs using binary search
                ans += (m - idx - 1); // Add the count of valid pairs
            }
        }
        
        return ans; // Return the total count of valid pairs
    }
};
