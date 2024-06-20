/*
Missing And Repeating
Difficulty: MediumAccuracy: 24.83%Submissions: 417K+Points: 4
Given an unsorted array arr of size n of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer (The first index contains B and second index contains A)

Examples

Input: n = 2 arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: n = 3 arr[] = {1, 3, 3} 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ n


*/

/*
Intuition:
- We need to find two elements in the array: the element that repeats and the element that is missing.
- By leveraging an auxiliary array to count occurrences, we can determine which element repeats (appears twice) and which is missing (does not appear).

Approach:
1. Create a vector `vec` of size `n + 1` initialized to 0 to store the count of each element from 1 to n.
2. Traverse the input array and increment the count of each element in `vec`.
3. Traverse the `vec` to find the repeating and missing elements.
   - The repeating element is the one with a count of 2.
   - The missing element is the one with a count of 0.

Time Complexity:
- O(n): We traverse the input array once and the auxiliary array once.

Space Complexity:
- O(n): We use an auxiliary array of size `n + 1`.

*/

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> vec(n + 1, 0);  // Auxiliary array to count occurrences
        int rep = -1, mis = -1;
        
        // Count occurrences of each element
        for (int i = 0; i < n; i++) {
            vec[arr[i]]++;
        }
        
        // Find the repeating and missing elements
        for (int i = 1; i <= n; i++) {
            if (vec[i] == 0)
                mis = i;  // Missing element
            else if (vec[i] == 2)
                rep = i;  // Repeating element
                
            if(mis != -1 && rep != -1)
                break;
        }
        
        return {rep, mis};
    }
};


/*
Intuition:
- We can solve the problem using the mathematical properties of numbers.
- Let the repeating number be `x` and the missing number be `y`.
- We know the sum of the first `n` natural numbers (SN) and the sum of their squares (S2N).
- We can calculate the sum of the given array (S) and the sum of the squares of the given array (S2).

Formulas:
1. The difference between the sum of the array and the sum of the first `n` natural numbers gives us: S - SN = x - y.
2. The difference between the sum of the squares of the array and the sum of the squares of the first `n` natural numbers gives us: S2 - S2N = x^2 - y^2.

Using the above equations:
- (x - y) and (x^2 - y^2) can be used to derive x + y.
- Solve the equations to find x and y.

Time Complexity:
- O(n): We traverse the input array once to calculate the sums.

Space Complexity:
- O(1): We use a constant amount of extra space.
*/

class Solution {
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // Calculate the sum of the first n natural numbers
        long long SN = (n * (n + 1)) / 2;
        // Calculate the sum of squares of the first n natural numbers
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
        
        long long S = 0, S2 = 0;
        for(int i = 0; i < n; i++) {
            S += arr[i];
            S2 += (long long)arr[i] * (long long)arr[i];
        }
        
        // Calculate the differences
        long long val1 = S - SN;  // x - y
        long long val2 = S2 - S2N;  // x^2 - y^2
        
        // x^2 - y^2 = (x + y)(x - y)
        // val2 = (x + y) * val1
        // x + y = val2 / val1
        val2 = val2 / val1;
        
        // Calculate x and y
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
        
        return {(int)x, (int)y};
    }
};
