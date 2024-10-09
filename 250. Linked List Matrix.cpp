/*
Linked List Matrix
Difficulty: EasyAccuracy: 67.33%Submissions: 27K+Points: 2
Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.

Input: mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 

Input: mat = [[23, 28], [23, 28]]
Output:

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)

Constraints:
1 <= mat.size() <=15
1 <= mat[i][j] <=104
*/

/*
Approach:
1. We are given a matrix and we need to convert it into a special linked list.
   Each node in the linked list should point to its right neighbor and its down neighbor.
   
2. The matrix is given as a 2D vector. We need to iterate through the matrix and create
   nodes accordingly.

3. **Pointers Setup**:
   - `prev`: This pointer tracks the previously created node in the same row to set the `right` pointer.
   - `upper`: This pointer tracks the node in the row above the current one to set the `down` pointer.
   - `start`: This pointer holds the first node in the current row to help in moving `upper` across the row.
   
4. The construction is done by iterating through each row and column:
   - For the `right` pointer: We connect each node in the row to its right neighbor.
   - For the `down` pointer: We connect each node to its neighbor in the row below.

5. **Time Complexity**: 
   - **O(n^2)**: Since we iterate through every element of the matrix exactly once.
   
6. **Space Complexity**:
   - **O(n^2)**: Space used for storing the linked list nodes.

*/

class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        int n = mat.size(); // Size of the matrix
        Node* prev = NULL;  // Tracks the previous node in the row
        Node* head = NULL;  // Head of the matrix-linked list
        Node* upper = NULL; // Tracks the node in the row above for the 'down' pointer
        Node* start = NULL; // The first node in the current row
        
        // Iterate over the rows
        for(int i=0; i<n; i++){
            // Iterate over the columns
            for(int j=0; j<n; j++){
                // Create a new node with the matrix element
                Node* temp = new Node(mat[i][j]);
                
                // Initialize the head of the matrix-linked list
                if(!head) 
                    head = temp;
                
                // Set up the `down` pointer if we're not in the first row
                if(!upper) 
                    upper = start;
                
                // For all rows except the first, link the current node with the node in the row above
                if(i != 0){
                    upper->down = temp;
                    upper = upper->right;
                }
                
                // Set up the first node in the row
                if(j == 0) 
                    start = temp;
                
                // For all columns except the first, link the current node with the previous node in the row
                if(j > 0) 
                    prev->right = temp;
                
                // Move `prev` to the current node
                prev = temp;
            }
        }
        
        return head;
    }
};
