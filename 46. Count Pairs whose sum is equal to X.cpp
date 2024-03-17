/*
Count Pairs whose sum is equal to X
EasyAccuracy: 39.61%Submissions: 84K+Points: 2
Share your experience with the world! Submit your admission, interview, campus or any other experience and reach an audience of millions today!

banner
Given two linked list head1 and head2 with distinct elements, determine the count of all distinct pairs from both lists whose sum is equal to the given value x.

Note: A valid pair would be in the form (x, y) where x is from first linked list and y is from second linked list.

Example 1:

Input:
head1 = 1->2->3->4->5->6
head2 = 11->12->13
x = 15
Output: 3
Explanation: There are total 3 pairs whose sum is 15 : (4,11) , (3,12) and (2,13)
Example 2:

Input:
head1 = 7->5->1->3
head2 = 3->5->2->8
x = 10
Output: 2
Explanation: There are total 2 pairs whose sum is 10 : (7,3) and (5,5)
Your Task:
You only need to implement the given function countPairs() that take two linked list head1 and head2 and return the count of distinct pairs whose sum is equal to x.

Expected Time Complexity: O(length(head1)+lenght(head2)).
Expected Auxiliary Space: O(length(head1)) or O(length(head2)).

Constraints:
1<=length(head1), lenght(head2)<=105
1 <= Value of elements of  linked lists <= 109
1<= x <= 109
Note : All elements in each linked list are unique.

Company Tags
Amazon
Topic Tags
Linked ListData Structures
*/

/*
Algorithm:
1. Create an unordered_set to store the elements of the first linked list.
2. Traverse the first linked list and insert each element into the unordered_set.
3. Traverse the second linked list.
4. For each element in the second linked list, calculate the complement (x - current element).
5. Check if the complement exists in the unordered_set.
6. If the complement exists, increment the count of pairs.
7. Return the count of pairs.
*/

class Solution {
public:
    // Function to count pairs whose sum equals x
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Initialize count variable to store the count of pairs
        int cnt = 0;
        // Create an unordered_set to store elements of the first linked list
        unordered_set<int> st;
        // Traverse the first linked list and insert elements into the unordered_set
        while (head1) {
            st.insert(head1->data);
            head1 = head1->next;
        }
        // Traverse the second linked list
        while (head2) {
            // Calculate the complement (x - current element)
            int searchEle = x - head2->data;
            // Check if the complement exists in the unordered_set
            if (st.find(searchEle) != st.end()) {
                // If the complement exists, increment the count of pairs
                cnt++;
            }
            head2 = head2->next;
        }
        // Return the count of pairs
        return cnt;
    }
};
