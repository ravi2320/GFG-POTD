/*
Design MinMax Queue
Difficulty: MediumAccuracy: 76.5%Submissions: 6K+Points: 4
Design a SpecialQueue data structure that functions like a normal queue but with additional support for retrieving the minimum and maximum element efficiently.
The SpecialQueue must support the following operations:

enqueue(x): Insert an element x at the rear of the queue.
dequeue(): Remove the element from the front of the queue.
getFront(): Return the front element without removing.
getMin(): Return the minimum element in the queue in O(1) time.
getMax(): Return the maximum element in the queue in O(1) time.
There will be a sequence of queries queries[][]. The queries are represented in numeric form:

1 x : Call enqueue(x)
2:  Call dequeue()
3: Call getFront()
4: Call getMin()
5: Call getMax()
The driver code will process the queries, call the corresponding functions, and print the outputs of getFront(), getMin(), getMax() operations.
You only need to implement the above five functions.

Note: It is guaranteed that all the queries are valid.

Examples:

Input: q = 6, queries[][] = [[1, 4], [1, 2], [3], [4], [2], [5]]
Output: [4, 2, 2]
Explanation: Queries on queue are as follows:
enqueue(4): Insert 4 at the rear of the queue.
enqueue(2): Insert 2 at the rear of the queue.
return the front element i.e 4
return minimum element from the queue i.e 2
dequeue(): Remove the front element 4 from the queue
return maximum element from the queue i.e 2
Input: q = 4, queries[][] = [[1, 3], [4], [1, 5], [5]]
Output: [3, 5]
Explanation: Queries on queue are as follows:
enqueue(3): Insert 3 at the rear of the queue.
return minimum element from the queue i.e 3
enqueue(5): Insert 5 at the rear of the queue.
return maximum element from the queue i.e 5
Constraints:
1 ≤ queries.size() ≤ 105
0 ≤ values in the queue ≤ 109
*/

/*
Approach:
1. Maintain:
   - A normal queue<int> q to preserve FIFO order.
   - A multiset<int> st to keep all elements in sorted order.

2. enqueue(x):
   - Push element into queue q.
   - Insert into multiset st.

3. dequeue():
   - Take front element from q.
   - Remove it from multiset st.
   - Pop it from q.

4. getFront():
   - Return front element from q.

5. getMin():
   - The minimum element is at *st.begin() since multiset stores in sorted order.

6. getMax():
   - The maximum element is at *st.rbegin() (reverse begin).

Intuition:
- Queue ensures FIFO order.
- Multiset ensures we can get min/max in O(1).
- Deletion from multiset is O(log n), which keeps operations efficient.

Time Complexity:
- enqueue(x): O(log n) due to multiset insertion.
- dequeue(): O(log n) due to multiset deletion.
- getFront(): O(1).
- getMin(): O(1).
- getMax(): O(1).
Overall: O(log n) per update, O(1) per query.

Space Complexity:
- O(n) for storing elements in both queue and multiset.

*/

class SpecialQueue {
    multiset<int> st;   // Stores elements in sorted order for min/max retrieval
    queue<int> q;       // Stores elements in FIFO order
public:

    // Insert element into the queue
    void enqueue(int x) {
        q.push(x);
        st.insert(x);
    }

    // Remove front element from the queue
    void dequeue() {
        int front = q.front();
        auto it = st.find(front); // Find element in multiset
        st.erase(it);             // Remove one occurrence
        q.pop();
    }

    // Get the front element of the queue
    int getFront() {
        return q.front();
    }

    // Get the minimum element in the queue
    int getMin() {
        return *st.begin();
    }

    // Get the maximum element in the queue
    int getMax() {
        return *st.rbegin();
    }
};
