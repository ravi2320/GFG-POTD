/*
K-Pangrams
Difficulty: EasyAccuracy: 20.91%Submissions: 55K+Points: 2
Given a string str and an integer k, return true if the string can be changed into a pangram after at most k operations, else return false.

A single operation consists of swapping an existing alphabetic character with any other lowercase alphabetic character.

Note - A pangram is a sentence containing every letter in the english alphabet.

Examples :

Input: str = "the quick brown fox jumps over the lazy dog", k = 0
Output: true
Explanation: the sentence contains all 26 characters and is already a pangram.
Input: str = "aaaaaaaaaaaaaaaaaaaaaaaaaa", k = 25 
Output: true
Explanation: The word contains 26 instances of 'a'. Since only 25 operations are allowed. We can keep 1 instance and change all others to make str a pangram.
Input: str = "a b c d e f g h i j k l m", k = 20
Output: false
Explanation: Since there are only 13 alphabetic characters in this case, no amount of swapping can produce a panagram here.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)  

Constraints:
1<= str.size() <= 105
0<= k <= 50
str may contain duplicate characters
str contains only lowercase alphabets or spaces.
*/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    /**
     * Intuition:
     * A k-Pangram is a string that can be made into a pangram by adding at most k unique characters.
     * The idea is to first count the number of unique alphabetic characters in the string and then check
     * if the number of missing characters to reach all 26 alphabets is less than or equal to k.
     *
     * Time Complexity:
     * - O(n), where n is the length of the string. We iterate through the string once to count characters.
     *
     * Space Complexity:
     * - O(1) or O(26), which is constant space for the set of characters, as there are only 26 possible lowercase letters.
     */

    bool kPangram(string str, int k) {
        unordered_set<char> st;
        int cnt = 0;
        
        for(char &x : str){
            if(x != ' ' && x != ',' && x != '.'){
                st.insert(x);
                cnt++;
            }
        }
        
        // If there are fewer unique characters than the alphabet, it cannot be a k-Pangram
        if(cnt < 26)
            return false;
            
        // Check if the number of additional characters needed is less than or equal to k
        return k >= (26 - st.size());
    }
};
