/*
Sorting Elements of an Array by Frequency
Difficulty: MediumAccuracy: 44.93%Submissions: 64K+Points: 4
Given an array of integers arr, sort the array according to the frequency of elements, i.e. elements that have higher frequency comes first. If the frequencies of two elements are the same, then the smaller number comes first.

Examples :

Input: arr[] = [5, 5, 4, 6, 4]
Output: [4, 4, 5, 5, 6]
Explanation: The highest frequency here is 2. Both 5 and 4 have that frequency. Now since the frequencies are the same the smaller element comes first. So 4 4 comes first then comes 5 5. Finally comes 6. The output is 4 4 5 5 6.
Input: arr[] = [9, 9, 9, 2, 5]
Output: [9, 9, 9, 2, 5]
Explanation: The highest frequency here is 3. Element 9 has the highest frequency So 9 9 9 comes first. Now both 2 and 5 have the same frequency. So we print smaller elements first. The output is 9 9 9 2 5.
Expected Time Complexity: O(n*logn)
Expected Space Complexity: O(n)

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i]≤ 105
*/

/*
**Intuition:**
We need to sort an array based on the frequency of its elements in descending order. If two elements have the same frequency, the smaller element should appear first. This can be achieved by counting the frequency of each element using a hash map and then sorting the array with a custom comparator.

**Approach:**
1. **Frequency Counting:**
   - Traverse the array and count the frequency of each element using `unordered_map`.
   
2. **Custom Sorting:**
   - Use `sort` with a custom comparator:
     - Sort by frequency in descending order.
     - If frequencies are equal, sort by element value in ascending order.
   
3. **Return Result:**
   - After sorting, return the modified array.

**Time Complexity:** O(N log N), where N is the size of the array, due to sorting.
**Space Complexity:** O(N) for the frequency map.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
  public:
    // Function to sort the array according to frequency of elements.
    std::vector<int> sortByFreq(std::vector<int>& arr) {
        // Map to store frequency of each element
        std::unordered_map<int, int> freqMap;
        for(const int &num : arr) {
            freqMap[num]++;
        }
        
        // Custom comparator for sorting
        auto compare = [&](int a, int b) {
            if(freqMap[a] != freqMap[b])
                return freqMap[a] > freqMap[b]; // Higher frequency comes first
            return a < b; // If frequency is same, smaller number comes first
        };
        
        // Sort the array using the custom comparator
        std::sort(arr.begin(), arr.end(), compare);
        
        return arr;
    }
};

int main() {
    Solution sol;
    std::vector<int> arr = {5, 5, 4, 6, 4};
    std::vector<int> result = sol.sortByFreq(arr);
    
    // Output the sorted array
    for(int num : result) {
        std::cout << num << " ";
    }
    // Expected Output: 4 4 5 5 6
    return 0;
}
