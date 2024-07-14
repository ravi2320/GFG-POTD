/*
Check Equal Arrays
Difficulty: BasicAccuracy: 42.18%Submissions: 340K+Points: 1
Given two arrays arr1 and arr2 of equal size, the task is to find whether the given arrays are equal. Two arrays are said to be equal if both contain the same set of elements, arrangements (or permutations) of elements may be different though.
Note: If there are repetitions, then counts of repeated elements must also be the same for two arrays to be equal.

Examples:

Input: arr1[] = [1, 2, 5, 4, 0], arr2[] = [2, 4, 5, 0, 1]
Output: true
Explanation: Both the array can be rearranged to [0,1,2,4,5]
Input: arr1[] = [1, 2, 5], arr2[] = [2, 4, 15]
Output: false
Explanation: arr1[] and arr2[] have only one common value.
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1<= arr1.size, arr2.size<=107
1<=arr1[], arr2[]<=109
*/

// Intuition: 
// - We use an unordered_map to count occurrences of each number in arr1.
// - For each element in arr2, we decrement its count in the map.
// - If all counts in the map become zero after processing arr2, arr1 and arr2 are equal.
// - Time Complexity: O(n) where n is the size of arr1 (assuming arr1 and arr2 are of equal size).
// - Space Complexity: O(n) for the unordered_map where n is the number of distinct elements in arr1.

class Solution {
public:
    // Function to check if two arrays are equal in terms of elements and frequencies.
    bool check(vector<int>& arr1, vector<int>& arr2) {
        // Check if sizes are different, arrays cannot be equal
        if (arr1.size() != arr2.size())
            return false;
        
        // Map to count occurrences of each number in arr1
        unordered_map<int, int> mp;
        
        // Count occurrences of numbers in arr1
        for (int &num : arr1) {
            mp[num]++;
        }
        
        // Compare with arr2
        for (int &num : arr2) {
            // Decrease count of num in map
            mp[num]--;
            
            // If count becomes zero, remove it from map
            if (mp[num] == 0) {
                mp.erase(num);
            }
        }
        
        // If map is empty, arrays are equal; otherwise, they are not
        return mp.empty();
    }
};
