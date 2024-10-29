/*
Quick Sort on Linked List
Difficulty: MediumAccuracy: 71.8%Submissions: 20K+Points: 4
You are given a Linked List. Sort the given Linked List using quicksort. 

Examples:

Input: Linked list: 1->6->2
Output: 1->2->6

Explanation:
After sorting the nodes, we have 1, 2 and 6.
Input: Linked list: 1->9->3->8
Output: 1->3->8->9

Explanation:
After sorting the nodes, we have 1, 3, 8 and 9. 
Constraints:
1<= size of linked list <= 105
*/

/*
Approach:
1. This solution sorts the linked list using the quicksort algorithm by first storing all node values in a vector, sorting the vector, and then updating the linked list nodes with the sorted values.
2. The `partition` function:
   - Picks the first element as the pivot and partitions the array such that all elements less than the pivot come before it and all elements greater than the pivot come after.
   - Returns the final position of the pivot element.
3. The `quickSortArr` function:
   - Recursively calls itself to sort the left and right halves around the partition index.
4. In `quickSort` function:
   - Traverse the linked list to store node values in a vector.
   - Use `quickSortArr` to sort this vector.
   - Traverse the linked list again to replace node values with sorted values from the vector.
5. This approach leverages quicksort for time efficiency on average cases, though it requires O(n) space.

Time Complexity: O(n log n) on average for quicksort, where n is the number of nodes in the linked list.
Space Complexity: O(n), as it uses an auxiliary vector to store the list values.

*/

class Solution {
  public:
    // Function to partition the array around a pivot
    int partition(int low, int high, vector<int> &arr) {
        int i = low;  // Left pointer
        int j = high; // Right pointer
        int pivot = arr[low]; // Choose first element as pivot

        while(i < j) {
            while(i <= high && arr[i] <= pivot) i++; // Move right if elements are <= pivot
            while(j >= low && arr[j] > pivot) j--;   // Move left if elements are > pivot

            // Swap elements if they are out of place
            if(i < j) swap(arr[i], arr[j]);
        }

        swap(arr[low], arr[j]); // Place pivot in correct position
        return j; // Return final pivot position
    }

    // Recursive function to perform quicksort on the array
    void quickSortArr(int low, int high, vector<int> &arr) {
        if(low < high) {
            int partitionIdx = partition(low, high, arr); // Partition the array
            quickSortArr(low, partitionIdx - 1, arr);     // Recursively sort left half
            quickSortArr(partitionIdx + 1, high, arr);    // Recursively sort right half
        }
    }

    // Function to perform quicksort on the linked list
    struct Node* quickSort(struct Node* head) {
        vector<int> arr; // Vector to store linked list values
        Node* curr = head;

        // Store all linked list values in the vector
        while(curr) {
            arr.push_back(curr->data);
            curr = curr->next;
        }

        // Sort the array using quicksort
        quickSortArr(0, arr.size() - 1, arr);

        // Update linked list with sorted values
        curr = head;
        int i = 0;
        while(curr) {
            curr->data = arr[i++];
            curr = curr->next;
        }

        return head; // Return sorted linked list
    }
};

/*
Approach:
1. This solution sorts a linked list using the quicksort technique, with the head of the list as the pivot.
2. A helper function `partition` divides the list into two sublists: 
   - `left` contains nodes with values less than or equal to the pivot.
   - `right` contains nodes with values greater than the pivot.
3. Base case: If the list has 0 or 1 node, it is already sorted.
4. Recursion:
   - Recursively sorts the `left` and `right` partitions.
5. Concatenation:
   - Connects the sorted left partition with the pivot and then with the sorted right partition.
6. This approach ensures that each partition is sorted in place.

Time Complexity: O(n log n) on average for partitioning, where n is the number of nodes in the linked list.
Space Complexity: O(log n) for recursion stack in the worst case (unbalanced partitions).

*/

class Solution {
public:
    // Partition function to split the list into left and right sublists around a pivot
    static void partition(Node* pivot, Node* &left, Node* &right) {
        Node* temp = pivot->next;
        
        // Traverse through the list and partition nodes based on the pivot's value
        while (temp) {
            Node* next = temp->next;
            if (temp->data <= pivot->data) {
                temp->next = left;
                left = temp; // Add node to left partition
            } else {
                temp->next = right;
                right = temp; // Add node to right partition
            }
            temp = next;
        }
    }

    // Main quickSort function for the linked list
    struct Node* quickSort(struct Node* head) {
        // Base case: If list is empty or has a single node, return it
        if (!head || !head->next)
            return head;

        // Initialize left and right partitions
        Node *left = NULL, *right = NULL;

        // Partition the list around the pivot (head node)
        partition(head, left, right);

        // Recursively sort the left and right partitions
        left = quickSort(left);
        right = quickSort(right);

        // Connect the sorted left partition to the pivot (head node)
        Node* curr = left;
        if (curr) {
            while (curr->next) // Traverse to end of left partition
                curr = curr->next;
            curr->next = head; // Connect end of left partition to pivot
        } else {
            left = head; // If left partition is empty, pivot becomes the start
        }

        // Connect the pivot to the sorted right partition
        head->next = right;

        // Return the new head of the sorted list
        return left;
    }
};

