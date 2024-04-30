/*
Add two numbers represented by linked lists
MediumAccuracy: 34.52%Submissions: 247K+Points: 4
 Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
banner
Given two numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Example 1:

Input:
n = 2
num1 = 45 (4->5->null)
m = 3
num2 = 345 (3->4->5->null)
Output: 
3->9->0->null  
Explanation: 
For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
Example 2:

Input:
n = 4
num1 = 0063 (0->0->6->3->null)
m = 2
num2 = 07 (0->7->null)
Output: 
7->0->null
Explanation: 
For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
Your Task:
The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(max(n,m)) for the resultant list.

Constraints:
1 <= n, m <= 104
*/

// Intuition:
// This class provides a solution to add two numbers represented by linked lists.
// It first reverses both input linked lists to simplify the addition process.
// Then, it iterates through both linked lists, adding corresponding digits and propagating the carry.
// The result is stored in a new linked list, which is then reversed back to the original order.

// Time Complexity: O(max(N, M))
// - 'N' and 'M' are the lengths of the input linked lists 'num1' and 'num2', respectively.
// - The algorithm iterates through both linked lists once.

// Space Complexity: O(max(N, M))
// - The algorithm uses extra space to store the result linked list, which can be at most 'max(N, M) + 1' nodes.

// Define the structure for a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    // Function to reverse a linked list
    Node* reverse(Node* root) {
        Node* curr = root;
        Node* prev = NULL;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to add two numbers represented by linked lists
    Node* addTwoLists(Node* num1, Node* num2) {
        // Remove leading zeros from both numbers
        while (num1 && num1->data == 0)
            num1 = num1->next;
        while (num2 && num2->data == 0)
            num2 = num2->next;

        // If both numbers are zero, return a new node with value 0
        if (!num1 && !num2)
            return new Node(0);

        // Reverse both input linked lists
        Node* head1 = reverse(num1);
        Node* head2 = reverse(num2);

        // Initialize variables for the result linked list
        Node* root = nullptr;
        Node* lastNode = nullptr;
        int carry = 0;

        // Iterate through both linked lists and perform addition
        while (head1 || head2 || carry) {
            int add = carry;

            if (head1) {
                add += head1->data;
                head1 = head1->next;
            }

            if (head2) {
                add += head2->data;
                head2 = head2->next;
            }

            carry = add / 10;
            add %= 10;

            // Create a new node for the result
            Node* newNode = new Node(add);

            // Add the new node to the result linked list
            if (!root) {
                root = newNode;
                lastNode = newNode;
            } else {
                lastNode->next = newNode;
                lastNode = lastNode->next;
            }
        }

        // Reverse the result linked list to restore the original order
        return reverse(root);
    }
};

// Sample Usage
#include <iostream>
using namespace std;

// Helper function to print a linked list
void printList(Node* head) {
    while (head) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution obj;
    // Create two sample linked lists: 1234 and 5678
    Node* num1 = new Node(1);
    num1->next = new Node(2);
    num1->next->next = new Node(3);
    num1->next->next->next = new Node(4);

    Node* num2 = new Node(5);
    num2->next = new Node(6);
    num2->next->next = new Node(7);
    num2->next->next->next = new Node(8);

    // Perform addition of the two numbers represented by linked lists
    Node* result = obj.addTwoLists(num1, num2);

    // Print the result linked list
    cout << "Result of addition: ";
    printList(result); // Output: Result of addition: 9876

    return 0;
}
