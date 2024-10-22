/*
Sub-arrays with equal number of occurences
Difficulty: HardAccuracy: 57.74%Submissions: 14K+Points: 8
Given an array arr[] and two integers say, x and y, find the number of sub-arrays in which the number of occurrences of x is equal to the number of occurrences of y.

Examples:

Input: arr[] = [1, 2, 1] , x= 1 , y = 2
Output: 2
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1, 2], x and y have same occurrence(1).
2) [2, 1], x and y have same occurrence(1).
Input: arr[] = [1, 2, 1] , x = 4 , y = 6
Output: 6
Explanation: The possible sub-arrays have same equal number of occurrences of x and y are:
1) [1], x and y have same occurrence(0).
2) [2], x and y have same occurrence(0).
3) [1], x and y have same occurrence(0).
4) [1, 2], x and y have same occurrence(0).
5) [2, 1], x and y have same occurrence(0).
6) [1, 2, 1], x and y have same occurrence(0).
Input: arr[] = [1, 2, 1] , x= 1 , y = 4
Output: 1
Explanation: The possible sub-array have same equal number of occurrences of x and y is: [2], x and y have same occurrence(0)
Constraints: 
1 <= arr.size() <= 106
1 <= arr[i], x, y<=106
*/

/*
Approach:
- The goal is to find the number of subarrays where the number of occurrences of `x` and `y` are the same.
- We track the difference between the frequencies of `x` and `y` as we traverse the array.
- If the difference at some point `i` is the same as at a previous point `j`, it implies that the subarray between `i` and `j` has equal numbers of `x` and `y`.
- This is achieved by using a frequency map (`mp`) where the key is the difference between the frequency of `x` and `y`, and the value is the count of how many times this difference has occurred.
  
Key Steps:
1. Initialize `freqA` to track the frequency of `x` and `freqB` to track the frequency of `y`.
2. For each element in the array, update the frequencies of `x` and `y` accordingly.
3. Compute the difference `freqA - freqB` at each step, and check if this difference has been seen before in the map. If it has, it means that there are subarrays ending at the current index with equal occurrences of `x` and `y`.
4. Add the count of such subarrays to the result (`ans`).
5. Update the map to include the current difference for future subarray calculations.

Time Complexity:
- O(n), where `n` is the size of the input array `arr`. We traverse the array once and perform constant-time operations for each element.

Space Complexity:
- O(n), for the hash map storing the frequency of differences.

*/

class Solution {
public:
    // Function to count the number of subarrays with the same occurrences of x and y
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // Hashmap to store the frequency difference (freqA - freqB)
        unordered_map<int, int> mp;

        int freqA = 0, freqB = 0, ans = 0;
        mp[0] = 1;  // Initialize the map with a zero difference
        
        // Traverse the array and calculate the frequency difference
        for(int &num : arr) {
            
            // Update frequency of x (freqA) if current number is x
            if(num == x) 
                freqA++;
                
            // Update frequency of y (freqB) if current number is y
            else if(num == y) 
                freqB++;
                
            // If the current difference (freqA - freqB) has been seen before,
            // it means there are subarrays with equal counts of x and y.
            if(mp.find(freqA - freqB) != mp.end()) {
                ans += mp[freqA - freqB];  // Add the count of such subarrays
            }
            
            // Increment the count of this difference in the map
            mp[freqA - freqB]++;
        }
        
        return ans;
    }
};