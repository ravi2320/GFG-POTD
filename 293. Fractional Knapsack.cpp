/*
Fractional Knapsack
Difficulty: MediumAccuracy: 32.46%Submissions: 288K+Points: 4
Given two arrays, val[] and wt[], representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

Examples :

Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value becomes 60+100+80.0=240.0 Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 
Input: val[] = [60, 100], wt[] = [10, 20], capacity = 50
Output: 160.000000
Explanation: Take both the items completely, without breaking. Total maximum value of item we can have is 160.00 from the given capacity of sack.
Input: val[] = [10, 20, 30], wt[] = [5, 10, 15], capacity = 100
Output: 60.000000
Explanation: In this case, the knapsack capacity exceeds the combined weight of all items (5 + 10 + 15 = 30). Therefore, we can take all items completely, yielding a total maximum value of 10 + 20 + 30 = 60.000000.
Constraints:
1 <= val.size=wt.size <= 105
1 <= capacity <= 109
1 <= val[i], wt[i] <= 104
*/

/*
Approach:
1. Calculate the value per unit weight for each item by dividing its value by its weight.
2. Store these values along with the original value and weight in a vector of pairs.
3. Sort the vector of items in descending order of value per unit weight.
4. Iterate through the sorted items:
   - If the current item's weight is less than or equal to the remaining capacity, add the entire item's value to `totalValue` and decrease `capacity` by the item's weight.
   - If the current item's weight exceeds the remaining capacity, take as much as possible from this item by adding `(capacity * value per unit weight)` to `totalValue` and setting `capacity` to 0.
5. Return `totalValue`, which now contains the maximum total value that can fit in the knapsack.

Time Complexity: O(n log n) due to sorting, where `n` is the number of items.
Space Complexity: O(n) for storing the value-to-weight ratios and item details.

*/

class Solution {
public:
    // Comparator function to sort items by descending value per unit weight
    static bool cmp(pair<double, pair<int, int>>& a, pair<double, pair<int, int>>& b) {
        return a.first > b.first;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<double, pair<int, int>>> items;
        int n = val.size();

        // Calculate value per unit weight for each item and store it with value and weight
        for (int i = 0; i < n; i++) {
            double valPerUnit = (1.0 * val[i]) / wt[i];
            items.push_back({valPerUnit, {val[i], wt[i]}});
        }

        // Sort items by value per unit weight in descending order
        sort(items.begin(), items.end(), cmp);
        double totalValue = 0;

        // Fill the knapsack with as much value as possible
        for (int i = 0; i < n && capacity > 0; i++) {
            if (items[i].second.second <= capacity) {
                totalValue += items[i].second.first;
                capacity -= items[i].second.second;
            } else {
                totalValue += (capacity * items[i].first);
                capacity = 0;
            }
        }

        return totalValue;
    }
};
