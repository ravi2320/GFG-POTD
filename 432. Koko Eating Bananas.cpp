/*
Koko Eating Bananas
Difficulty: MediumAccuracy: 50.27%Submissions: 28K+Points: 4Average Time: 20m
Koko is given an array arr[], where each element represents a pile of bananas. She has exactly k hours to eat all the bananas.

Each hour, Koko can choose one pile and eat up to s bananas from it.

If the pile has atleast s bananas, she eats exactly s bananas.

If the pile has fewer than s bananas, she eats the entire pile in that hour.

Koko can only eat from one pile per hour.


Your task is to find the minimum value of s (bananas per hour) such that Koko can finish all the piles within k hours.

Examples:

Input: arr[] = [5, 10, 3], k = 4
Output: 5
Explanation: Koko eats at least 5 bananas per hour to finish all piles within 4 hours, as she can consume each pile in 1 + 2 + 1 = 4 hours.
Input: arr[] = [5, 10, 15, 20], k = 7
Output: 10
Explanation: At 10 bananas per hour, Koko finishes in 6 hours, just within the limit 7.
Constraint:
1 ≤ arr.size() ≤ 105 
1 ≤ arr[i] ≤ 106
arr.size() ≤ k ≤ 106
*/

/*
Approach:
This is a classic binary search problem. We want to find the minimum eating speed (an integer)
such that Koko can eat all the bananas within `k` hours. At each candidate speed, we simulate
how many hours Koko would need to eat all the bananas and check if it fits within `k`.

We perform binary search on the speed range: [1, max(piles)].
For each mid-value in binary search, we check if it's a valid eating speed using the helper
function `isPossible()`.

Intuition:
If Koko eats slower, she might not finish on time; if she eats faster, she surely will.
Hence, the feasible region of valid speeds is sorted => binary search is applicable.

Time Complexity: O(n * log m)
Where `n` = number of piles and `m` = maximum number of bananas in a pile.
We perform log(m) binary search iterations and in each we scan all n piles.

Space Complexity: O(1)
Only a few integer variables are used.
*/

class Solution {
public:
    // Helper function to check if Koko can eat all bananas at a given speed within k hours
    bool isPossible(const vector<int> &piles, int speed, int k) {
        int totalHours = 0;

        for (int pile : piles) {
            // Calculate time needed to eat this pile at current speed (ceil division)
            totalHours += (pile + speed - 1) / speed;

            // If total hours exceed k, it's not possible
            if (totalHours > k) return false;
        }

        return true;  // She can eat all piles within k hours at this speed
    }

    int kokoEat(vector<int>& piles, int k) {
        int low = 1;  // Minimum possible speed
        int high = *max_element(piles.begin(), piles.end());  // Maximum pile size = max speed
        int answer = high;  // Initialize answer with highest possible speed

        // Perform binary search on speed
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If it's possible to eat at speed `mid`, try lower speeds
            if (isPossible(piles, mid, k)) {
                answer = mid;
                high = mid - 1;
            }
            // Otherwise, try higher speeds
            else {
                low = mid + 1;
            }
        }

        return answer;  // Return the minimum feasible speed
    }
};
