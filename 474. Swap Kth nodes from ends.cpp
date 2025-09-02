/*
Swap Kth nodes from ends

Difficulty: MediumAccuracy: 35.5%Submissions: 71K+Points: 4Average Time: 45m
Given the head of a singly linked list and an integer k. Swap the kth node (1-based index) from the beginning and the kth node from the end of the linked list. Return the head of the final formed list and if it's not possible to swap the nodes return the original list.

Examples:

Input: k = 1,
  
Output: 5 -> 2 -> 3 -> 4 -> 1
Explanation: Here k = 1, hence after swapping the 1st node from the beginning and end the new list will be 5 -> 2 -> 3 -> 4 -> 1.
  
Input: k = 2,
  
Output: 5 -> 9 -> 8 -> 5 -> 10 -> 3
Explanation: Here k = 2, hence after swapping the 2nd node from the beginning and end the new list will be 5 -> 9 -> 8 -> 5 -> 10 -> 3.
  
Constraints:
1 ≤ list size ≤ 104
1 ≤ node->data ≤ 106
1 ≤ k ≤ 104
*/

/*
Approach:
1. Traverse the linked list and store all node values into an array for easy access by index.
2. Calculate the size of the array (n).
3. If the size of the list is smaller than k, no swap is possible, so return the head.
4. Swap the k-th node from the beginning (arr[k-1]) with the k-th node from the end (arr[n-k]).
5. Traverse the linked list again and update node values from the modified array.
6. Return the modified head of the list.

Intuition:
- The problem requires swapping values of the k-th node from the start and end.
- Instead of directly manipulating node pointers (which is tricky in linked lists), we can simplify
  by storing values in an array, performing the swap, and rewriting values back to the nodes.

Time Complexity:  
- O(n): We traverse the linked list twice and perform O(1) swap operation.  
Space Complexity:  
- O(n): Extra space is used to store node values in an array.
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // Convert linked list into an array
        Node *curr = head;
        vector<int> arr;
        while(curr){
            arr.push_back(curr->data);
            curr = curr->next;
        }
        
        int n = arr.size();
        
        // If k is larger than size, no swap is possible
        if(n < k){
            return head;
        }
        
        // Swap the k-th element from start and end
        swap(arr[k-1], arr[n-k]);
        
        // Rewrite the modified values into the linked list
        curr = head;
        int idx = 0;
        while(curr){
            curr->data = arr[idx++];
            curr = curr->next;
        }
        
        return head;
    }
};

/*
Approach:
1. Traverse the linked list to count total nodes and identify the k-th node from the start.
2. If the total number of nodes is less than k, no swap is possible → return head as is.
3. Find the k-th node from the end by calculating (n - k + 1)-th node from the start.
4. Swap the data of the k-th node from the start and the k-th node from the end.
5. Return the head pointer.

Intuition:
- Swapping nodes directly in a singly linked list is tricky without modifying links. 
- Instead, we can swap their values (`data`) to achieve the same effect with less complexity.
- This requires finding the correct two nodes by traversing the list.

Time Complexity:  
- O(N) → where N is the number of nodes (one traversal to count nodes, two more traversals to locate and swap).
  
Space Complexity:  
- O(1) → constant space, since only a few pointers/variables are used.

*/

// Node class definition for reference
/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // Step 1: Count total nodes and store k-th node value
        int cnt = 0;
        int n1 = -1, n2 = -1;   // placeholders for k-th and (n-k+1)-th node values
        Node* curr = head;
        
        while (curr) {
            cnt++; 
            if (cnt == k) {
                n1 = curr->data; // store value of k-th node from start
            }
            curr = curr->next;
        }
        
        // If total nodes < k, swapping is not possible
        if (cnt < k) return head;
        
        // Step 2: Locate k-th node from end (which is (cnt - k + 1)-th from start)
        int target = cnt - k + 1;
        int cnt2 = 0;
        curr = head;
        
        while (curr) {
            cnt2++;
            if (cnt2 == target) {
                n2 = curr->data; // store value of (cnt-k+1)-th node
            }
            curr = curr->next;
        }
        
        // Step 3: Replace values at positions k and (cnt-k+1)
        cnt2 = 0;
        curr = head;
        while (curr) {
            cnt2++;
            if (cnt2 == k) {
                curr->data = n2; // assign value of (cnt-k+1)-th node
            }
            if (cnt2 == target) {
                curr->data = n1; // assign value of k-th node
            }
            curr = curr->next;
        }
        
        return head; // return updated list
    }
};

/*
Approach:
1. Traverse the linked list to count its length `n`.
2. Keep track of the kth node from the beginning (`startK`) and simultaneously find the kth node from the end (`endK`).
   - As we traverse, once we pass the kth node, move `endK` pointer forward as well.
3. After traversal, if `k <= n`, swap the data of `startK` and `endK`.
4. Return the modified head.

Intuition:
The kth node from the beginning and the kth node from the end are symmetric in the list.
By counting nodes and using a two-pointer strategy, we can directly identify and swap them 
without storing all node values in an array.

Time Complexity: O(n) → We traverse the list once to find the kth nodes.
Space Complexity: O(1) → We only use pointers, no extra data structures.
*/

/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // Pointer to traverse the list
        Node *curr = head;
        
        // Pointers for kth node from start and end
        Node *startK = head, *endK = head;
        
        int n = 0; // Total length of the linked list
        
        // Traverse the linked list to count nodes and track kth nodes
        while(curr){
            n++;
            
            // Store kth node from beginning
            if(n == k){
                startK = curr;
            }
            
            // After crossing kth node, move endK
            if(n > k){
                endK = endK->next;
            }
            
            curr = curr->next;
        }
        
        // Only swap if k is valid (list has at least k nodes)
        if(n >= k)
            swap(startK->data, endK->data);
        
        return head; // Return modified linked list
    }
};