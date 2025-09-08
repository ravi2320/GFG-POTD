/*
Merge Sort for Linked List
Difficulty: MediumAccuracy: 74.76%Submissions: 82K+Points: 4Average Time: 30m
You are given the head of a linked list. You have to sort the given linked list using Merge Sort.

Examples:

Input:
    
Output: 10 -> 20 -> 30 -> 40 -> 50 -> 60
Explanation: After sorting the given linked list, the resultant list will be:
    
Input:
    
Output: 2 -> 5 -> 8 -> 9
Explanation: After sorting the given linked list, the resultant list will be:
    
Constraints:
1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 106


*/

/*
Approach:
1. Use the "Divide and Conquer" strategy (like array Merge Sort).
2. Divide:
   - Find the middle of the linked list using the slow & fast pointer method.
   - Split the list into two halves.
3. Conquer:
   - Recursively sort both halves using mergeSort.
4. Combine:
   - Merge the two sorted halves using a helper `merge()` function.

Intuition:
The problem is similar to merge sort for arrays, but since linked lists allow
efficient splitting and merging (O(1) insertions/removals), merge sort is well-suited.
Finding the middle helps us divide, and merging maintains sorted order.

Time Complexity: O(n log n)  
- Each level of recursion divides the list into halves → O(log n) levels.  
- Merging all nodes at each level costs O(n).  

Space Complexity: O(log n)  
- Due to recursion stack in divide-and-conquer.  
- No extra arrays, since merging reuses existing nodes.
*/

class Solution {
  public:
    // Function to sort the linked list using merge sort
    Node* mergeSort(Node* head) {
        // Base case: if list is empty or single element
        if(!head || !head->next){
            return head;
        }
        
        // Find middle node to split list
        Node* mid = findMid(head);
        Node* temp = mid->next;
        mid->next = NULL;  // break the list into two halves
        
        // Recursively sort both halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(temp);
        
        // Merge the two sorted halves
        return merge(left, right);
    }
    
    // Helper function to merge two sorted linked lists
    Node* merge(Node* left, Node* right){
        Node dummy(-1);       // dummy node to ease merging
        Node* curr = &dummy;  // pointer to build result list
    
        while(left && right){
            if(left->data <= right->data){
                curr->next = left;
                left = left->next;
            }
            else{
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
    
        // Attach the remaining part
        curr->next = left ? left : right;
    
        return dummy.next;
    }

    // Helper function to find middle of linked list
    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;  // fast starts ahead for correct split
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;  // slow will be middle
    }
};
