/*
Subtraction in Linked List
HardAccuracy: 12.94%Submissions: 66K+Points: 8
Three 90 Challenge Extended On Popular Demand! Don't Miss Out Now 

banner
You are given two linked lists that represent two large positive numbers. From the two numbers represented by the linked lists, subtract the smaller number from the larger one. Look at the examples to get a better understanding of the task.

Example 1:

Input:
L1 = 1->0->0
L2 = 1->2
Output: 88
Explanation:  
First linked list represents 100 and the
second one represents 12. 12 subtracted from 100
gives us 88 as the result. It is represented
as 8->8 in the linked list.
Example 2:

Input:
L1 = 0->0->6->3
L2 = 7->1->0
Output: 647
Explanation: 
First linked list represents 0063 => 63 and 
the second one represents 710. 63 subtracted 
from 710 gives us 647 as the result. It is
represented as 6->4->7 in the linked list.
Your Task:
You do not have to take any input or print anything. The task is to complete the function subLinkedList() that takes heads of two linked lists as input parameters and which should subtract the smaller number from the larger one represented by the given linked lists and return the head of the linked list representing the result.

n and m are the length of the two linked lists respectively.
Expected Time Complexity:  O(n+m)
Expected Auxiliary Space: O(n+m)

Constraints:
1 <= n <= 10000
0 <= values represented by the linked lists < 10n
0 <= values represented by the linked lists < 10m
*/

class Solution {
public:
       int length(Node* head){

        Node* temp=head;

        int count=1;

        while(temp){

            temp=temp->next;

            count++;
        }
        return count;
    }
    void reverse(Node** head){
        Node* cur = *head;
        Node* prev = NULL;
        Node* nextt = NULL;
       
        
        while(cur!=NULL){
           
            nextt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextt;
        }
        *head = prev;
    }
    
    Node* ans(Node* head1,Node* head2){
        reverse(&head1);
        reverse(&head2);
        Node* num = NULL; 
        
  
        int carry=0,flag=0;
        Node* cur1 = head1;Node* cur2 = head2;
        int up,lw,dt;
        while(cur1!=NULL && cur2!=NULL){
          //cout<<"are you hr";
            up = cur1->data;
            lw = cur2->data;
            if(up>=lw && carry==0){
                dt = up-lw;
            }
            else if(up>lw && carry==1){
                dt = up-lw-1;
                carry=0;
            }
            else if(up==lw && carry==0){
                dt = 0;
            }
            else if(up<=lw && carry==1){
                dt = (up+10-1)-lw;
            }
            else if(up<=lw && carry==0){
                dt = (up+10)-lw;
                carry = 1;
            }

            Node* newnum = new Node(dt);
            newnum->next = num;
            num = newnum; 
         
            cur1 = cur1->next;
            cur2 = cur2->next;
           
        }
       //if something left in first list (since it is larger in length)
        while(cur1!=NULL){
            
              if(carry==1){
                  if(cur1->data>0){
                      cur1->data = cur1->data - 1;
                      carry = 0;
                  }
                  else if(cur1->data==0){
                      cur1->data = 9;
                      carry = 1;
                  }
              }
              
              Node* newnum = new Node(cur1->data);
               newnum->next = num;
               num = newnum; 
               cur1 = cur1->next;
        }
        while(num!=NULL && num->data==0){
            num = num->next;
        }
        if(num==NULL){
            Node* ptr = new Node(0);
            return ptr;
        }
        return num;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
     
        while(head1!=NULL && head1->data==0){
            
              head1=head1->next;
        }
        
        while(head2!=NULL && head2->data==0){
           
              head2=head2->next;
        }
      
        if(head1==NULL && head2==NULL){
            Node* ptr = new Node(0);
            return ptr;
        } 
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
       
        int n1 = length(head1);
        int n2 = length(head2);
       
      
        if(n1==n2) {
            while(head1!=NULL && head2!=NULL && head1->data==head2->data){
                head1 = head1->next;
                head2 = head2->next;
            }
            if(head1==NULL || head2==NULL){
                return new Node(0);
            }
            if(head1->data>head2->data){
                return ans(head1,head2);
            }
            else
             return ans(head2,head1);
        }
       
        if(n1>n2){
            return ans(head1,head2);
        }
        else{
            return ans(head2,head1);
        }

        return NULL;
    }
};