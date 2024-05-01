/*
Arrange Consonants and Vowels
MediumAccuracy: 49.98%Submissions: 25K+Points: 4
 Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
banner
Given a singly linked list having n nodes containing english alphabets ('a'-'z'). Rearrange the linked list in such a way that all the vowels come before the consonants while maintaining the order of their arrival. 

Example 1:

Input:
n = 9
linked list: a -> b -> c -> d -> e -> f -> g -> h -> i 
Output: 
a -> e -> i -> b -> c -> d -> f -> g -> h
Explanation: 
After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.
Example 2:

Input:
n = 8
linked list: a -> b -> a -> b -> d -> e -> e -> d 
Output: 
a -> a -> e -> e -> b -> b -> d -> d
Explanation: 
After rearranging the input linked list according to the condition the resultant linked list will be as shown in output.
Your Task:
Your task is to complete the function arrangeCV(), which takes head of linked list and arranges the list in such a way that all the vowels come before the consonants while maintaining the order of their arrival and returns the head of the updated linked list.

Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)

Constraints:
1 <= n <= 104
'a' <= elements of linked list <= 'z'
*/

// Intuition:
// This function rearranges the nodes of a linked list such that all vowels appear before all consonants.
// It traverses the original linked list, creating two separate linked lists:
// one for vowels and one for consonants.
// After traversing the original list, it connects the end of the vowels list to the beginning of the consonants list.

// Time Complexity: O(N)
// - 'N' is the number of nodes in the input linked list.
// - The algorithm traverses the list once.

// Space Complexity: O(1)
// - The algorithm uses constant extra space.

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char d) : data(d), next(nullptr) {}
};

class Solution {
public:
    Node* arrangeCV(Node* head) {
        // Create dummy nodes for vowels and consonants
        Node *vowel = new Node('a'), *con = new Node('b');
        Node *vowHead = vowel, *conHead = con;

        // Traverse the original list and move nodes to the appropriate list
        while (head) {
            if (head->data == 'a' || head->data == 'e' || head->data == 'i' || head->data == 'o' || head->data == 'u') {
                vowel->next = head;
                vowel = vowel->next;
            } else {
                con->next = head;
                con = con->next;
            }
            head = head->next;
        }

        // Terminate the consonants list and connect it to the end of the vowels list
        con->next = nullptr;
        vowel->next = conHead->next;

        // Return the head of the rearranged list
        return vowHead->next;
    }
};

// Sample Usage
int main() {
    Solution obj;

    // Create a sample linked list
    Node* head = new Node('a');
    head->next = new Node('c');
    head->next->next = new Node('e');
    head->next->next->next = new Node('b');
    head->next->next->next->next = new Node('d');
    head->next->next->next->next->next = new Node('i');
    head->next->next->next->next->next->next = new Node('o');
    head->next->next->next->next->next->next->next = new Node('u');

    // Arrange the nodes in the linked list
    Node* rearrangedHead = obj.arrangeCV(head);

    // Print the rearranged list
    while (rearrangedHead) {
        cout << rearrangedHead->data << " ";
        rearrangedHead = rearrangedHead->next;
    }
    // Output: a e i o u c b d
    return 0;
}
