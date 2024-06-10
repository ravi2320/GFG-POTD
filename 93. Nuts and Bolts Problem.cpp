/*
Nuts and Bolts Problem
MediumAccuracy: 59.03%Submissions: 63K+Points: 4
Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
Daily rewards up for grabs!

banner
Given a set of n nuts & bolts. There is a one-on-one mapping between nuts and bolts. You have to Match nuts and bolts efficiently. Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means the nut can only be compared with the bolt and the bolt can only be compared with the nut to see which one is bigger/smaller.
The elements should follow the following order: { !,#,$,%,&,*,?,@,^ }

Note: Make all the required changes directly in the given arrays, output will be handled by the driver code.

Examples

Input: n = 5, nuts[] = {@, %, $, #, ^}, bolts[] = {%, @, #, $ ^}
Output: 
# $ % @ ^
# $ % @ ^
Explanation: As per the order # should come first after that $ then % then @ and ^. 
Input: n = 9, nuts[] = {^, &, %, @, #, *, $, ?, !}, bolts[] = {?, #, @, %, &, *, $ ,^, !}
Output: 
! # $ % & * ? @ ^
! # $ % & * ? @ ^
Explanation: We'll have to match first ! then  # , $,  %,  &,  *,  @,  ^,  ? as per the required ordering.
Expected Time Complexity: O(n(logn))
Expected Auxiliary Space: O(log(n))

Constraints:
1 <= n <= 9
The arrays 'nuts' and 'bolts' can only consist of the following elements: {'@', '#', '$', '%', '^', '&', '?', '*', '!'}.
All the elements of arrays 'nuts' and 'bolts' should be unique.

Seen this question in a real interview before ?
1/4
Yes
No
Company Tags
AmazonHikeMakeMyTripMAQ SoftwareAdobe
*/

/*
Intuition:
- The problem involves matching pairs of nuts and bolts such that they can only be compared using an order relation, i.e., you cannot compare nuts directly with other nuts or bolts with other bolts.
- The approach is to use a predefined order of characters and map each character to an index, then sort the nuts and bolts arrays based on this order.

Approach:
1. Create an unordered map to define the order of characters.
2. Create two arrays to hold sorted nuts and bolts based on the predefined order.
3. Traverse through the nuts and bolts arrays, placing each character at its corresponding index in the arrays.
4. Traverse through the sorted arrays and update the original nuts and bolts arrays with the sorted values.

Time Complexity: O(n)
- We traverse the nuts and bolts arrays twice, which takes O(n) time.

Space Complexity: O(1)
- We use extra space for the map and temporary arrays, but the space is constant (9 characters).

*/

class Solution {
public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        // Define the order of characters
        unordered_map<char, int> mp;
        mp['!'] = 1;
        mp['#'] = 2;
        mp['$'] = 3;
        mp['%'] = 4;
        mp['&'] = 5;
        mp['*'] = 6;
        mp['^'] = 7;
        mp['@'] = 8;
        mp['?'] = 9;
        
        // Temporary arrays to hold sorted nuts and bolts
        vector<char> sortedNuts(9, '0'), sortedBolts(9, '0');
        
        // Place nuts and bolts in the temporary arrays based on the order
        for(int i = 0; i < n; i++) {
            int idx = mp[nuts[i]] - 1;
            sortedNuts[idx] = nuts[i];
            
            idx = mp[bolts[i]] - 1;
            sortedBolts[idx] = bolts[i];
        }
        
        // Update the original nuts and bolts arrays with the sorted values
        int nutIndex = 0, boltIndex = 0;
        for(int i = 0; i < 9; i++) {
            if(sortedNuts[i] != '0') {
                nuts[nutIndex++] = sortedNuts[i];
            }
            
            if(sortedBolts[i] != '0') {
                bolts[boltIndex++] = sortedBolts[i];
            }
        }
    }
};
