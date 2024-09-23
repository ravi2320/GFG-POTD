/*
Find pairs with given sum in doubly linked list
Difficulty: EasyAccuracy: 66.01%Submissions: 52K+Points: 2
Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

 

Example 1:

Input:  
1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
target = 7
Output: (1, 6), (2,5)
Explanation: We can see that there are two pairs 
(1, 6) and (2,5) with sum 7.
 

Example 2:

Input: 
1 <-> 5 <-> 6
target = 6
Output: (1,5)
Explanation: We can see that there is one pairs  (1, 5) with sum 6.
*/

/*
 * Approach:
 * 1. This function finds all pairs of nodes in a doubly linked list whose data sum up to the given target.
 * 2. The function uses two nested loops:
 *    - The outer loop iterates over each node in the list (`temp`).
 *    - The inner loop (`temp2`) checks subsequent nodes for a pair whose sum equals the target.
 * 3. When such a pair is found, it is added to the result vector `ans`.
 * 4. The function ensures that pairs are only formed in the correct order (from left to right in the list).
 *
 * Time Complexity: O(n^2), where `n` is the number of nodes in the list (due to the nested loops).
 * Space Complexity: O(1) for extra space, excluding the result vector `ans`.
 */

class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;  // Stores the pairs with the given sum
        Node* temp = head;  // Pointer to traverse the list
        
        // Outer loop to fix one element
        while(temp) {
            Node* temp2 = temp->next;  // Pointer to find the second element of the pair
            
            // Inner loop to find the pair with the current element
            while(temp2 && temp->data + temp2->data <= target) {
                // Check if the sum of temp and temp2 equals the target
                if(temp->data + temp2->data == target) {
                    ans.push_back({temp->data, temp2->data});  // Add the pair to the result
                }
                temp2 = temp2->next;  // Move to the next node
            }
            
            temp = temp->next;  // Move the outer loop pointer to the next node
        }
        
        return ans;  // Return the vector of pairs
    }
};


/*
 * Approach:
 * 1. This function finds all pairs of nodes in a doubly linked list whose data sum up to the given target.
 * 2. The algorithm uses the two-pointer technique:
 *    - `left` starts from the head (smallest value) and `right` starts from the tail (largest value).
 *    - If the sum of `left` and `right` equals the target, add the pair to the result vector `ans`.
 *    - If the sum is less than the target, move the `left` pointer forward to increase the sum.
 *    - If the sum is greater than the target, move the `right` pointer backward to decrease the sum.
 * 3. This ensures that pairs are found efficiently, without nested loops.
 *
 * Time Complexity: O(n), where `n` is the number of nodes in the list (one pass from both ends).
 * Space Complexity: O(1) for extra space, excluding the result vector `ans`.
 */

class Solution {
public:
    // Helper function to find the tail (last node) of the list
    Node* findTail(Node* head) {
        while(head->next) {
            head = head->next;
        }
        return head;
    }

    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        vector<pair<int, int>> ans;  // Stores the pairs with the given sum
        Node* left = head;  // Pointer starting from the head (smallest value)
        Node* right = findTail(head);  // Pointer starting from the tail (largest value)
        
        // Loop until left and right pointers cross each other
        while(left && right && left != right && left->data < right->data) {
            int sum = left->data + right->data;  // Calculate the current sum
            
            if(sum == target) {
                ans.push_back({left->data, right->data});  // Add the pair to the result
                left = left->next;  // Move left pointer forward
                right = right->prev;  // Move right pointer backward
            }
            else if(sum < target) {
                left = left->next;  // If sum is less than target, move left forward to increase sum
            }
            else {
                right = right->prev;  // If sum is greater than target, move right backward to decrease sum
            }
        }
        
        return ans;  // Return the vector of pairs
    }
};
