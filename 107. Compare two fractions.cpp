/*
Compare two fractions
Difficulty: EasyAccuracy: 57.54%Submissions: 10K+Points: 2
You are given a string str containing two fractions a/b and c/d, compare them and return the greater. If they are equal, then return "equal".

Note: The string str contains "a/b, c/d"(fractions are separated by comma(,) & space( )). 

Examples

Input: str = "5/6, 11/45"
Output: 5/6
Explanation: 5/6=0.8333 and 11/45=0.2444, So 5/6 is greater fraction.
Input: str = "8/1, 8/1"
Output: equal
Explanation: We can see that both the fractions are same, so we'll return a string "equal".
Input: str = "10/17, 9/10"
Output: 9/10
Explanation: 10/17 = 0.588 & 9/10 = 0.9, so the greater fraction is "9/10".
Expected Time Complexity: O(len|str|)
Expected Auxiliary Space: O(1)

Constraints:
0<=a,c<=103
1<=b,d<=103
*/

/*
Intuition:
- The method parses the input string to extract two fractions.
- It then calculates the decimal value of each fraction.
- Finally, it compares the two values and returns the larger fraction as a string, or "equal" if they are the same.

Time Complexity:
- O(n): We traverse the input string once to parse and calculate the fractions.

Space Complexity:
- O(n): We use additional space to store the parsed fractions as strings.
*/

class Solution {
public:
    string compareFrac(string str) {
        int a = 0, b = 0;
        double first, second;
        string temp1 = "", temp2 = "";
        bool flag = false;

        for (char x : str) {
            if (x == '/') {
                flag = true;
                temp2 += x;
                continue;
            } else if (x == ',') {
                temp1 = temp2;
                temp2 = "";
                flag = false;
                first = (double) a / b;
                a = 0;
                b = 0;
                continue;
            } else if (x == ' ')
                continue;

            temp2 += x;

            if (!flag) {
                a = a * 10 + (x - '0');
            } else {
                b = b * 10 + (x - '0');
            }
        }

        second = (double) a / b;

        if (first > second)
            return temp1;
        else if (second > first)
            return temp2;

        return "equal";
    }
};
