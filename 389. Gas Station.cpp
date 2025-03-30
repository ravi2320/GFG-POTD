/*
Gas Station
Difficulty: MediumAccuracy: 34.79%Submissions: 186K+Points: 4Average Time: 20m
There are some gas stations along a circular route. You are given two integer arrays gas[] denoted as the amount of gas present at each station and cost[] denoted as the cost of travelling to the next station. You have a car with an unlimited gas tank. You begin the journey with an empty tank from one of the gas stations. Return the index of the starting gas station if it's possible to travel around the circuit without running out of gas at any station in a clockwise direction. If there is no such starting station exists, return -1.
Note: If a solution exists, it is guaranteed to be unique.

Examples:

Input: gas[] = [4, 5, 7, 4], cost[]= [6, 6, 3, 5]
Output: 2
Explanation: It is possible to travel around the circuit from station at index 2. Amount of gas at station 2 is (0 + 7) = 7.
Travel to station 3. Available gas = (7 – 3 + 4) = 8.
Travel to station 0. Available gas = (8 – 5 + 4) = 7.
Travel to station 1. Available gas = (7 – 6 + 5) = 6.
Return to station 2. Available gas = (6 – 6) = 0.
Input: gas[] = [1, 2, 3, 4, 5], cost[] = [3, 4, 5, 1, 2]
Output: 3
Explanation: It is possible to travel around the circuit from station at index 3. Amount of gas at station 3 is (0 + 4) = 4.
Travel to station 4. Available gas = 4 – 1 + 5 = 8.
Travel to station 0. Available gas = 8 – 2 + 1 = 7.
Travel to station 1. Available gas= 7 – 3 + 2 = 6.
Travel to station 2. Available gas = 6 – 4 + 3 = 5.
Travel to station 3. The cost is 5. The gas is just enough to travel back to station 3.
Input: gas[] = [3, 9], cost[] = [7, 6]
Output: -1
Explanation: There is no gas station to start with such that you can complete the circuit.
Constraints:
1 ≤ gas.size(), cost.size() ≤ 106
1 ≤ gas[i], cost[i] ≤ 103
*/

/*
Approach:
1. We need to determine if there exists a starting gas station from which we can complete the circular journey.
2. If the total gas available is less than the total cost required, it's impossible to complete the journey, so we return -1.
3. We keep track of the current gas balance while traversing stations.
4. If at any point the gas balance becomes negative, it means we cannot start from any of the previous stations, so we reset the start index to the next station.
5. The final result is the start index if the total gas is sufficient; otherwise, return -1.

Intuition:
- If we ever run out of gas at some station `i`, we know that no station from `0` to `i` can be a valid starting point.
- This is because starting from any of them will eventually lead to a negative balance before reaching `i`.
- Hence, we greedily reset our starting point to `i+1` and continue checking.

Time Complexity: O(n) - We traverse the array only once.
Space Complexity: O(1) - We use a few extra variables.
*/

class Solution {
public:
    int startStation(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0; // Track total gas and total cost
        int startIndex = 0, currGas = 0; // Track the starting station and current gas balance

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];

            currGas += gas[i] - cost[i];

            // If the gas balance drops below zero, we must restart from the next station
            if (currGas < 0) {
                startIndex = i + 1;
                currGas = 0;  // Reset current gas balance
            }
        }

        // If total gas is at least total cost, return the start index; otherwise, return -1
        return (totalGas >= totalCost) ? startIndex : -1;
    }
};
