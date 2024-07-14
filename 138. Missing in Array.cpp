/*
Missing in Array
Difficulty: EasyAccuracy: 29.59%Submissions: 1.1MPoints: 2
Given an array of size n-1 such that it only contains distinct integers in the range of 1 to n. Return the missing element.

Examples:

Input: n = 5, arr[] = [1,2,3,5]
Output: 4
Explanation : All the numbers from 1 to 5 are present except 4.
Input: n = 2, arr[] = [1]
Output: 2
Explanation : All the numbers from 1 to 2 are present except 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 106
1 ≤ arr[i] ≤ 106
*/

// Intuition:
// - The missing number in the array is found by subtracting the sum of the elements in the array from the expected sum of numbers from 1 to n.
// - Calculate the expected sum using the formula (n * (n + 1)) / 2, where n is the size of the array plus one (since one number is missing).
// - Time Complexity: O(n), where n is the size of the array. We iterate through the array once to compute the sum.
// - Space Complexity: O(1). We use constant extra space for variables.

class Solution {
public:
    // Function to find the missing number in an array of size n-1 containing numbers from 1 to n
    int missingNumber(int n, vector<int>& arr) {
        // Calculate the sum of numbers from 1 to n
        int sum = (n * (n + 1)) / 2;
        
        // Subtract each number in arr from the total sum
        for (int &num : arr) {
            sum -= num;
        }
        
        // The remaining sum is the missing number
        return sum;
    }
};


// Intuition:
// - Use the property of XOR to find the missing number efficiently.
// - XOR of all numbers from 1 to n gives us a baseline value.
// - XOR all numbers in the given array to cancel out the numbers that are present, leaving the missing number.
// - Time Complexity: O(n), where n is the size of the array. We iterate through the array twice, once for calculating XOR and once for applying it.
// - Space Complexity: O(1). We use constant extra space for variables.

class Solution {
public:
    // Function to find the missing number in an array of size n-1 containing numbers from 1 to n
    int missingNumber(int n, vector<int>& arr) {
        // Initialize XOR variable to store XOR of numbers from 1 to n
        int Xor = 0;
        
        // XOR all numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            Xor ^= i;
        }
        
        // XOR all numbers in the array
        for (int &num : arr) {
            Xor ^= num;
        }
        
        // The remaining Xor will be the missing number
        return Xor;
    }
};


