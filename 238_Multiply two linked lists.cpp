/*
Multiply two linked lists
Difficulty: EasyAccuracy: 46.33%Submissions: 71K+Points: 2
Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.

Note: The output could be large take modulo 109+7.

Examples :

Input: LinkedList L1 : 3->2 , LinkedList L2 : 2
Output: 64
Explanation: 

Multiplication of 32 and 2 gives 64.
Input: LinkedList L1: 1->0->0 , LinkedList L2 : 1->0
Output: 1000
Explanation: 

Multiplication of 100 and 10 gives 1000.
Expected Time Complexity: O(max(n,m))
Expected Auxilliary Space: O(1)
where n is the size of L1 and m is the size of L2

Constraints:
1 <= number of nodes <= 9
0 <= node->data <= 9
*/

/*
 * Approach:
 * - Traverse both linked lists `first` and `second`, interpreting their digits as forming numbers.
 * - Multiply the two numbers modulo `1e9 + 7` to avoid overflow.
 * 
 * Time Complexity:
 * - O(n + m): We traverse both linked lists once, where `n` is the length of the first list and `m` is the length of the second list.
 *
 * Space Complexity:
 * - O(1): Constant space usage apart from the input lists and variables.
 */

class Solution {
public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // Initialize two numbers to hold values of the linked lists
        long long n1 = 0;
        long long n2 = 0;
        long long mod = 1e9 + 7;

        // Traverse the first linked list to form the first number
        while (first) {
            n1 = (n1 * 10 + first->data) % mod;  // Constructing the number from the linked list
            first = first->next;
        }

        // Traverse the second linked list to form the second number
        while (second) {
            n2 = (n2 * 10 + second->data) % mod;  // Constructing the number from the linked list
            second = second->next;
        }

        // Return the product of the two numbers modulo 1e9+7
        return (n1 * n2) % mod;
    }
};
