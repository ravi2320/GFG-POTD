/*
Check if frequencies can be equal
MediumAccuracy: 16.67%Submissions: 91K+Points: 4
Internship Alert!
New month-> Fresh Chance to top the leaderboard and get SDE Internship! 

banner
Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.

Note: The driver code print 1 if the value returned is true, otherwise 0.

Example 1:

Input:
s = "xyyz"
Output: 
1 
Explanation: 
Removing one 'y' will make frequency of each character to be 1.
Example 2:

Input:
s = "xxxxyyzz"
Output: 
0
Explanation: 
Frequency can not be made same by removing at most one character.
Your Task:  
You dont need to read input or print anything. Complete the function sameFreq() which takes a string as input parameter and returns a boolean value denoting if same frequency is possible or not.

Expected Time Complexity: O(|s|) 
Expected Auxiliary Space: O(1)

Constraints:
1 <= |s| <= 105
*/

class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char, int> freqMap;
	    for(char c : s){
	        freqMap[c]++;
	    }
	    int maxFreq = INT_MIN, minFreq = INT_MAX;
	    int maxCnt = 0, minCnt = 0;
	    for(auto x : freqMap){
	        if(maxFreq < x.second){
	            maxFreq = x.second;
	            maxCnt = 0;
	        }
	        if(minFreq > x.second){
	            minFreq = x.second;
	            minCnt = 0;
	        }     
	        if(minFreq == x.second)
	            minCnt++;
	        if(maxFreq == x.second)
	            maxCnt++;
	    }
	    if(minFreq == maxFreq || (minFreq == maxFreq-1 && (maxCnt == 1 || minFreq == 1)))
	        return true;
        return false; 
	}
};