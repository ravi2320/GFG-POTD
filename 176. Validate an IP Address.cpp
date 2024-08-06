/*
Validate an IP Address
Difficulty: MediumAccuracy: 11.22%Submissions: 249K+Points: 4
You are given a string str in the form of an IPv4 Address. Your task is to validate an IPv4 Address, if it is valid return true otherwise return false.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1

A valid IPv4 Address is of the form x1.x2.x3.x4 where 0 <= (x1, x2, x3, x4) <= 255. Thus, we can write the generalized form of an IPv4 address as (0-255).(0-255).(0-255).(0-255)

Note: Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.

Examples :

Input: str = 222.111.111.111
Output: true
Explanation: Here, the IPv4 address is as per the criteria mentioned and also all four decimal numbers lies in the mentioned range.
Input: str = 5555..555
Output: false
Explanation: 5555..555 is not a valid. IPv4 address, as the middle two portions are missing.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1<=str.length() <=15
*/

// Intuition: This function checks if a given string is a valid IPv4 address. 
// It splits the string by dots and ensures that each segment is a number between 0 and 255,
// with no leading zeros (except for "0" itself).

// Time Complexity: O(n), where n is the length of the string. Each character is processed once.
// Space Complexity: O(1), as we use a constant amount of extra space.

class Solution {
public:
    int isValid(string str) {
        int temp = -1, idx = -1, n = str.length();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (str[i] == '.') {
                cnt++;
                if (temp < 0 || temp > 255)
                    return false;

                if (temp != 0 && str[idx + 1] == '0')
                    return false;

                idx = i;
                temp = -1;
            } else {
                if (temp == -1)
                    temp = 0;

                temp = temp * 10 + (str[i] - '0');
            }
        }

        if (temp < 0 || temp > 255 || (temp != 0 && str[idx + 1] == '0') || cnt != 3)
            return false;

        return true;
    }
};
