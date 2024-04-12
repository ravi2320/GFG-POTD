/*
Sum of Products
MediumAccuracy: 50.93%Submissions: 31K+Points: 4
Given an array arr[] of size n. Calculate the sum of Bitwise ANDs ie: calculate sum of arr[i] & arr[j] for all the pairs in the given array arr[] where i < j.

Example 1:

Input:
n = 3
arr = {5, 10, 15}
Output:
15
Explanation:
The bitwise Ands of all pairs where i<j are (5&10) = 0, (5&15) = 5 and (10&15) = 10.
Therefore, the total sum = (0+5+10) = 15.
Example 2:

Input:
n = 4
arr = {10, 20, 30, 40}
Output:
46
Explanation:
The sum of bitwise Ands 
of all pairs = (0+10+8+20+0+8) = 46.
Your Task:
You don't need to read input or print anything.Your Task is to complete the function pairAndSum() which takes an Integer n and an array arr[]  of size n as input parameters and returns the sum of bitwise Ands of all pairs.

Expected Time Complexity:O(n)
Expected Auxillary Space:O(1)

Constraints:
1 <= n <= 105
1 <= arr[i] <= 108


*/

/*
Intuition:
- To find the sum of the bitwise AND of all pairs in the given array, we first count the number of set bits at each position in the binary representation of the array elements.
- We iterate through each element in the array and count the set bits at each position.
- After counting the set bits, we calculate the sum of pairs for each bit position.
- Finally, we sum up the contributions of all bit positions to get the total sum of bitwise AND of all pairs.

Time Complexity: O(n * log(max(arr[i])))
- The time complexity of counting the set bits for each element in the array is O(n * log(max(arr[i]))).
- The time complexity of calculating the sum of pairs for each bit position is O(32) = O(1).
- Thus, the overall time complexity is dominated by the first step, which is O(n * log(max(arr[i]))).

Space Complexity: O(1)
- We use a constant amount of extra space for the bits vector, independent of the input size.
*/

long long pairAndSum(int n, long long arr[]) {
    // Initialize a vector to store the count of set bits at each position
    vector<int> bits(32, 0);
    
    // Count the number of set bits at each position in the binary representation of the array elements
    for (int i = 0; i < n; i++) {
        int j = 0;
        int temp = arr[i];
        while (temp) {
            if (temp & 1)
                bits[j]++;
            j++;
            temp >>= 1;
        }
    }
    
    // Initialize the answer variable to store the sum of bitwise AND of all pairs
    long long ans = 0;
    
    // Calculate the sum of pairs for each bit position and add to the answer
    for (int i = 0; i < 32; i++) {
        long long temp = bits[i];
        temp--;
        long long pairs = (temp * (temp + 1)) / 2;
        ans += (pairs * (long long) pow(2, i));
    }
    
    return ans;
}
