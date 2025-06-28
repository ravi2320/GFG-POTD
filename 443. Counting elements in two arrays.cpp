/*
Counting elements in two arrays
Difficulty: MediumAccuracy: 37.12%Submissions: 84K+Points: 4Average Time: 20m
You are given two unsorted arrays a[] and b[]. Both arrays may contain duplicate elements. For each element in a[], your task is to count how many elements in b[] are less than or equal to that element.

Examples:

Input: a[] = [4, 8, 7, 5, 1], b[] = [4, 48, 3, 0, 1, 1, 5]
Output: [5, 6, 6, 6, 3]
Explanation: 
For a[0] = 4, there are 5 elements in b (4, 3, 0, 1, 1) that are ≤ 4.
For a[1] = 8 and a[2] = 7, there are 6 elements in b that are ≤ 8 and ≤ 7.
For a[3] = 5, there are 6 elements in b that are ≤ 5.
For a[4] = 1, there are 3 elements in b (0, 1, 1) that are ≤ 1.
Input: a[] = [10, 20], b[] = [30, 40, 50]
Output: [0, 0]
Explanation: 
For a[0] = 10 and a[1] = 20, there are no elements in b that are less than or equal to 10 or 20. Hence, the output is [0, 0].
Constraints:
1 ≤ a.size(), b.size() ≤ 105
0 ≤ a[i], b[j] ≤ 105
*/

/*
Approach:
Given two arrays `a` and `b`, for each element in `a`, we need to count how many elements in `b` are 
less than or equal to that element.

Brute-force Solution:
- For every element `x` in `a`, iterate through all elements `y` in `b`, and count how many satisfy `y <= x`.
- Push the count into the result vector.

Intuition:
- This is a straightforward nested loop approach.
- Although simple, it becomes inefficient when arrays are large due to O(n*m) complexity.

Time Complexity:
- O(n * m), where `n` is the size of array `a` and `m` is the size of array `b`.

Space Complexity:
- O(n) for storing the result vector.

Optimized Suggestion:
- Sort array `b` and use binary search (`upper_bound`) for each element in `a` to reduce time complexity to O(n log m).

*/

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int> res;

        // For each element in `a`, count how many elements in `b` are <= current element
        for (int &x : a) {
            int cnt = 0;

            for (int &y : b) {
                if (y <= x) cnt++;
            }

            res.push_back(cnt);
        }

        return res;
    }
};


/*
Approach:
We are given an array `nums` and an integer `k`. The task is to find the subsequence of length `k` 
which has the **maximum sum** while preserving the **original order** from the array.

This implementation uses a brute-force method:
1. For `k` iterations, select the maximum available element (not already chosen) from `nums`.
2. Track the selected indices using a set to avoid repeats.
3. After collecting `k` indices, use them to form the final result vector.

Intuition:
- The algorithm mimics greedy selection by picking the maximum element repeatedly,
  but it does not guarantee preservation of relative order (since `set` sorts indices).
  Hence, the **order may be broken**, which is incorrect for this problem.

Time Complexity:
- O(k * n): For each of the k elements, we traverse the array of size n to find the maximum.
- O(k log k): For inserting and iterating through the set of indices.

Space Complexity:
- O(k): For storing the selected indices.

⚠️ Note:
This approach **fails to preserve the order of elements** correctly in all cases because 
`set` sorts indices, not preserving their insertion sequence. A better approach is 
to store value-index pairs and sort them manually.

*/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;  // To store selected indices (sorted automatically)

        for (int sel = 0; sel < k; sel++) {
            int maxIdx = INT_MIN;

            // Find the max value not already selected
            for (int i = 0; i < n; i++) {
                if (!st.count(i) && 
                    (maxIdx == INT_MIN || nums[i] > nums[maxIdx])) {
                    maxIdx = i;
                }
            }

            if (maxIdx != INT_MIN) {
                st.insert(maxIdx);
            }
        }

        // Build result using indices (⚠️ order may not be preserved!)
        vector<int> res;
        for (int idx : st) {
            res.push_back(nums[idx]);
        }

        return res;
    }
};

/*
Approach:
Given two arrays `a` and `b`, for each element in `a`, we need to count how many elements in `b` are 
less than or equal to that element.

Brute-force Solution:
- For every element `x` in `a`, iterate through all elements `y` in `b`, and count how many satisfy `y <= x`.
- Push the count into the result vector.

Intuition:
- This is a straightforward nested loop approach.
- Although simple, it becomes inefficient when arrays are large due to O(n*m) complexity.

Time Complexity:
- O(n * m), where `n` is the size of array `a` and `m` is the size of array `b`.

Space Complexity:
- O(n) for storing the result vector.

Optimized Suggestion:
- Sort array `b` and use binary search (`upper_bound`) for each element in `a` to reduce time complexity to O(n log m).

*/

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int> res;

        // For each element in `a`, count how many elements in `b` are <= current element
        for (int &x : a) {
            int cnt = 0;

            for (int &y : b) {
                if (y <= x) cnt++;
            }

            res.push_back(cnt);
        }

        return res;
    }
};