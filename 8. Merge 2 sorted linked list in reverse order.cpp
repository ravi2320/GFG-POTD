/*
Merge 2 sorted linked list in reverse order
MediumAccuracy: 62.29%Submissions: 44K+Points: 4
90% Refund available on all premium courses 
Discover How  

banner
Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

Example 1:

Input:
N = 2, M = 2
list1 = 1->3
list2 = 2->4
Output:
4->3->2->1
Explanation:
After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.
Example 2:

Input:
N = 4, M = 3
list1 = 5->10->15->40 
list2 = 2->3->20
Output:
40->20->15->10->5->3->2
Explanation:
After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.
Your Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

Expected Time Complexity : O(N+M)
Expected Auxiliary Space : O(1)

Constraints:
0 <= N, M <= 104
*/
class Solution
{
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
    
        while (curr != nullptr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
    
        return prev;
    }
    struct Node *mergeResult(Node *node1, Node *node2)
    {
        Node *dummy = new Node;
        dummy->data = 0; // Create a dummy node with a default value
        Node *curr = dummy;

        while (node1 != NULL || node2 != NULL)
        {
            int val1 = (node1 != NULL) ? node1->data : INT_MAX;
            int val2 = (node2 != NULL) ? node2->data : INT_MAX;

            if (val1 <= val2)
            {
                curr->next = node1;
                node1 = node1->next;
            }
            else
            {
                curr->next = node2;
                node2 = node2->next;
            }

            curr = curr->next;
        }

        return reverse(dummy->next); // Skip the dummy node
    }
};


class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        Node *head = NULL;
        Node *curr = NULL;
        vector<int> arr;
        while(node1 != NULL || node2 != NULL)
        {
            if(node1 != NULL){
                arr.push_back(node1->data);
                node1 = node1->next;
            }
            if(node2 != NULL){
                arr.push_back(node2->data);
                node2 = node2->next;
            }
        }
        sort(arr.begin(), arr.end(), greater<int>());
        for(int i : arr)
        {
            if(head == NULL){
                head = new Node;
                head->data = i;
                head->next = NULL;
                curr = head;
            }
            else{
                curr->next = new Node;
                curr->next->data = i;
                curr->next->next = NULL;
                curr = curr->next;
            }
        }
        return head;
    }  
};


