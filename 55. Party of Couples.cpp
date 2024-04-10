/*
Party of Couples
EasyAccuracy: 50.5%Submissions: 67K+Points: 2
You are given an integer array arr[] of size n, representing n number of people in a party, each person is denoted by an integer. Couples are represented by the same number ie: two people have the same integer value, it means they are a couple. Find out the only single person in the party of couples.

NOTE: It is guarantee that there exist only one single person in the party.

Example 1:

Input: 
n = 5
arr = {1, 2, 3, 2, 1}
Output: 
3
Explaination: Only the number 3 is single.
Example 2:

Input: 
n = 11 
arr = {1, 2, 3, 5, 3, 2, 1, 4, 5, 6, 6} 
Output: 
4 
Explaination: 4 is the only single.
Your Task:
You do not need to read input or print anything. Your task is to complete the function findSingle() which takes the size of the array n and the array arr[] as input parameters and returns the only single person.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 104
1 ≤ arr[i] ≤ 106


*/


// Intuition:
// XOR operation is used to find the single number that appears only once while all other numbers occur twice.
// When two same numbers are XORed, the result is 0. So, XORing all numbers in the array will cancel out the pairs,
// leaving the single number as the result.

// Time Complexity: O(n)
// The function iterates through the array once, performing constant-time operations in each iteration.
// Therefore, the time complexity is linear with respect to the size of the array, denoted by 'n'.

// Space Complexity: O(1)
// The function uses a constant amount of extra space regardless of the size of the input array.
// Thus, the space complexity is constant.
class Solution{
public:
    int findSingle(int n, int arr[]){
        int ans = 0;
        // XOR all elements in the array
        for(int i = 0; i < n; i++){
            ans = ans ^ arr[i];
        }
        // Return the single number
        return ans;
    }
};
