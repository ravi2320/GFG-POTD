/*
Product array puzzle
Difficulty: EasyAccuracy: 33.46%Submissions: 233K+Points: 2
Given an array nums[], construct a Product Array nums[] such that nums[i] is equal to the product of all the elements of nums except nums[i].

Examples:

Input: nums[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]
Explanation: For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Input: nums[] = [12,0]
Output: [0, 12]
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= nums.size() <= 1000
0 <= nums[i] <= 200
nums[i] may contain duplicates.
*/

/*
Intuition:
- The problem requires constructing a product array `P` where each element at index `i` is the product of all the elements of the input array `nums` except `nums[i]`.
- To handle cases where there are zeros in the input array, we first count the zeros. 
- If there are more than one zero, all elements in `P` will be zero because any number multiplied by zero is zero.
- If there is exactly one zero, only the position corresponding to that zero in `nums` will have a non-zero value in `P`.
- If there are no zeros, we can simply divide the total product by each element to get the required product for each index.

Time Complexity:
- The time complexity is O(n), where `n` is the number of elements in `nums`. This is because we iterate through the array twice: once to calculate the total product and the number of zeros, and another time to fill the product array.

Space Complexity:
- The space complexity is O(n), where `n` is the number of elements in `nums`, for storing the resulting product array.

*/

class Solution {
public:
    // Function to calculate product of elements except self.
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        long long int product = 1; // Holds the product of all non-zero elements.
        int cnt = 0; // Counter to track the number of zeros in the array.

        // Calculate the product of all non-zero elements and count zeros.
        for(long long int &x : nums){
            if(x == 0){
                cnt++;
                continue;
            }
            product *= x;
        }
        
        int n = nums.size();
        vector<long long int> arr(n, 0); // Initialize result array with zeros.

        // If more than one zero is present, return the result array filled with zeros.
        if(cnt > 1){
            return arr;
        }
        // If exactly one zero is present, only the index corresponding to the zero in the original array will have the product of all non-zero elements.
        else if(cnt == 1){
            for(int i = 0; i < n; i++){
                if(nums[i] == 0){
                    arr[i] = product;
                    return arr;
                }
            }
        }
        // If there are no zeros, calculate the result by dividing the total product by each element.
        else {
            for(int i = 0; i < n; i++){
                arr[i] = product / nums[i];
            }
        }
        
        return arr;
    }
};
