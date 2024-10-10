/*
Max distance between same elements
Difficulty: EasyAccuracy: 46.67%Submissions: 59K+Points: 2
Given an array arr[] with repeated elements, the task is to find the maximum distance between two occurrences of an element.

Note: You may assume that every input array has repetitions.

Examples:

Input: arr = [1, 1, 2, 2, 2, 1]
Output: 5
Explanation: distance for 1 is: 5-0 = 5, distance for 2 is : 4-2 = 2, So max distance is 5.
Input: arr = [3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2]
Output: 10
Explanation: maximum distance for 2 is 11-1 = 10, maximum distance for 1 is 4-2 = 2 ,maximum distance for 4 is 10-5 = 5, So max distance is 10.
Expected Time Complexity :  O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 <= arr.size() <= 106
1 <= arr[i] <= 109
*/

/*
Approach:
1. We need to find the maximum distance between two occurrences of the same element in the array.
2. We will use two hash maps:
   - `mp1` stores the **first occurrence** index of each element.
   - `mp2` stores the **last occurrence** index of each element.
3. For each element in the array:
   - If it's the first time encountering it, store its index in `mp1`.
   - Otherwise, update its last occurrence index in `mp2`.
4. Finally, we will calculate the maximum distance using `mp2[arr[i]] - mp1[arr[i]]` for each element.

5. **Time Complexity**: 
   - **O(n)** for traversing the array twice.
6. **Space Complexity**: 
   - **O(n)** for storing indices in two unordered maps.

*/

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> mp1, mp2;  // Maps to store first and last occurrences
        int n = arr.size();  // Size of the array
        
        // Step 1: Traverse the array to fill `mp1` and `mp2`
        for(int i = 0; i < n; i++) {
            // If it's the first time seeing the element, store its index in `mp1`
            if(mp1.find(arr[i]) == mp1.end()) {
                mp1[arr[i]] = i;
            }
            // Always update the last occurrence in `mp2`
            mp2[arr[i]] = i;
        }
        
        // Step 2: Find the maximum distance
        int dist = 0;  // Initialize distance to 0
        
        for(int i = 0; i < n; i++) {
            // Compute the distance between the first and last occurrence of arr[i]
            dist = max(dist, mp2[arr[i]] - mp1[arr[i]]);
        }
        
        return dist;  // Return the maximum distance
    }
};


/*
Approach:
1. We will use an unordered map to track the **first occurrence** of each element in the array.
2. As we iterate through the array:
   - If the element has been seen before (exists in the map), we compute the distance between the current index and the first occurrence index stored in the map.
   - If the element has not been seen before, we store its index in the map.
3. Keep track of the maximum distance found during the traversal.

4. **Time Complexity**: 
   - **O(n)**, where n is the size of the array since we are traversing the array once.
5. **Space Complexity**: 
   - **O(n)** for storing indices in the unordered map in the worst case.

*/

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> mp;  // Map to store the first occurrence of each element
        int n = arr.size();  // Size of the array
        int dist = 0;  // Initialize maximum distance to 0
        
        // Step 1: Traverse the array to calculate the maximum distance
        for(int i = 0; i < n; i++) {
            if(mp.find(arr[i]) != mp.end()) {
                // If element is already in the map, calculate distance
                dist = max(dist, i - mp[arr[i]]);
            } else {
                // If element is encountered for the first time, store its index
                mp[arr[i]] = i;
            }
        }
        
        return dist;  // Return the maximum distance
    }
};
