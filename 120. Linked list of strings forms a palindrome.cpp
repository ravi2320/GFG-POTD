/*
Linked list of strings forms a palindrome
Difficulty: EasyAccuracy: 58.6%Submissions: 36K+Points: 2
Given a linked list with string data, check whether the combined string formed is palindrome. If the combined string is palindrome then return true otherwise return false.

Example:

Input:

Output : true
Explanation: As string "abcddcba" is palindrome the function should return true.
Input:

Output : false
Explanation: As string "abcdba" is not palindrome the function should return false.
Expected Time Complexity:  O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= Node.data.length<= 103
1<=list.length<=103
*/

// Intuition:
// The goal is to determine whether the linked list represents a palindrome. 
// To achieve this, we can convert the linked list into a string and then check if that string is a palindrome. 
// A string is a palindrome if it reads the same forward and backward.

// Time Complexity: O(n), where n is the length of the linked list. 
// We traverse the linked list once to construct the string and then reverse the string and compare it, which takes linear time.
// Space Complexity: O(n), where n is the length of the linked list. 
// We use extra space to store the string representation of the linked list.

class Solution {
  public:
    bool compute(Node* head) {
        // Convert linked list to string
        string str = "";
        Node* temp = head;
        
        while (temp) {
            str += temp->data;
            temp = temp->next;
        }
        
        // Create a reversed copy of the string
        string rev = str;
        reverse(rev.begin(), rev.end());
        
        // Check if the original string is equal to its reversed copy
        return str == rev;
    }
};
