/*
Insertion Sort for Singly Linked List
MediumAccuracy: 69.66%Submissions: 25K+Points: 4
You've won Geekbits by solving daily. Now win 90% of your money-back by learning daily! 

banner
Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

Example 1:

Input:
N = 10
Linked List = 30->23->28->30->11->14->
              19->16->21->25 
Output : 
11 14 16 19 21 23 25 28 30 30 
Explanation :
The resultant linked list is sorted.
Example 2:

Input : 
N = 7
Linked List=19->20->16->24->12->29->30 
Output : 
12 16 19 20 24 29 30 
Explanation : 
The resultant linked list is sorted.
Your task:
You don't need to read input or print anything. Your task is to complete the function insertionSort() which takes the head of the linked list, sorts the list using insertion sort algorithm and returns the head of the sorted linked list.
 
Expected Time Complexity : O(n2)
Expected Auxiliary Space : O(1)
*/

class Solution
{
    public:
    Node* help(Node* ans, Node *temp){
        if(!ans or ans->data >= temp->data){
            temp->next = ans;
            ans = temp;
        }
        else{
            Node* temp2 = ans;
            while(temp2->next and temp2->next->data < temp->data){
                temp2 = temp2->next;
            }
            temp->next = temp2->next;
            temp2->next = temp;
        }
        return ans;
    }
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        Node* ans = NULL;
        Node* temp = head_ref;
        while(temp){
            Node* nxt = temp->next;
            ans = help(ans, temp);
            temp = nxt;
        }
        return ans;
    }
    
};