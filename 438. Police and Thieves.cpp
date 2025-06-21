/*
Police and Thieves
Difficulty: MediumAccuracy: 34.03%Submissions: 37K+Points: 4
Given an array arr[], where each element contains either a 'P' for policeman or a 'T' for thief. Find the maximum number of thieves that can be caught by the police. 
Keep in mind the following conditions :

Each policeman can catch only one thief.
A policeman cannot catch a thief who is more than k units away from him.
Examples:

Input: arr[] = ['P', 'T', 'T', 'P', 'T'], k = 1
Output: 2
Explanation: Maximum 2 thieves can be caught. First policeman catches first thief and second police man can catch either second or third thief.
Input: arr[] = ['T', 'T', 'P', 'P', 'T', 'P'], k = 2
Output: 3
Explanation: Maximum 3 thieves can be caught.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ k ≤ 1000
arr[i] = 'P' or 'T'
*/

/*
Approach:
We are given a list of characters representing 'P' (policemen) and 'T' (thieves) and an integer `k`.
Each policeman can catch at most one thief within a maximum distance `k`.

Steps:
1. Use two pointers: 
   - `i` to find policemen ('P')
   - `j` to find thieves ('T')
2. If a policeman and thief are within distance `k`, count a successful catch and move both pointers.
3. If the thief is too far to the left of the policeman, move the thief pointer (`j`).
4. If the policeman is too far to the left of the thief, move the policeman pointer (`i`).

Intuition:
We greedily match the closest available policeman-thief pair, moving forward only when a valid pairing is found.

Time Complexity: O(n)
- Single pass through the array using two pointers

Space Complexity: O(1)
- Constant space used
*/

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        int i = 0, j = 0;  // Pointers for policemen and thieves
        int cnt = 0;       // Counter for caught thieves

        while (i < n && j < n) {
            // Move `i` to next policeman
            while (i < n && arr[i] != 'P') {
                i++;
            }

            // Move `j` to next thief
            while (j < n && arr[j] != 'T') {
                j++;
            }

            // Check if current 'P' and 'T' are within range `k`
            if (i < n && j < n && abs(j - i) <= k) {
                cnt++;  // Successful catch
                i++;
                j++;
            }
            // Move the pointer that is lagging behind
            else if (i < n && i < j) {
                i++;
            }
            else if (j < n && j < i) {
                j++;
            }
        }

        return cnt;
    }
};