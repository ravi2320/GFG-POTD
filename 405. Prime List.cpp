/*
Prime List
Difficulty: MediumAccuracy: 53.68%Submissions: 29K+Points: 4
You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one. Return the head of the modified linked list.

Examples :

Input: head = 2 → 6 → 10
Output: 2 → 5 → 11

Explanation: The nearest prime of 2 is 2 itself. The nearest primes of 6 are 5 and 7, since 5 is smaller so, 5 will be chosen. The nearest prime of 10 is 11.
Input: head = 1 → 15 → 20
Output: 2 → 13 → 19

Explanation: The nearest prime of 1 is 2. The nearest primes of 15 are 13 and 17, since 13 is smaller so, 13 will be chosen. The nearest prime of 20 is 19.
Constraints:
1 <= no. of Nodes <= 104
1 <= node.val <= 104
*/

/*
Intuition:
- For each node in the linked list, we want to replace its value with the nearest prime number.
- If the value is already a prime, no change needed.
- To check primes efficiently, we use the Sieve of Eratosthenes up to a reasonable limit.

Approach:
1. Precompute all prime numbers up to 1e5 using the sieve method.
2. Traverse the linked list node by node.
3. For each node, if its value is not prime, find the nearest prime (either from left or right).
4. Replace the node's value with the nearest prime.
5. Return the modified linked list.

Time Complexity:
- Sieve construction: O(N log log N), where N = 1e5
- For each node in the list, worst-case prime search could take O(√N), but in practice it's small.
- Total: O(N log log N + M), where M is the number of nodes in the linked list.

Space Complexity:
- O(N) for the sieve vector.

*/

class Solution {
  public:

    // Helper function to find the nearest prime to a given value
    int nearestPrime(int val, vector<int> &seive){
        if(seive[val]){
            return val;
        }

        int prev = val - 1;
        int next = val + 1;

        while (true) {
            if(prev >= 2 && seive[prev]){
                return prev;
            }
            else if(next < seive.size() && seive[next]){
                return next;
            }

            prev--;
            next++;
        }

        return 2; // fallback (technically unreachable for val <= 1e5)
    }

    // Main function to update the linked list values
    Node *primeList(Node *head) {
        int n = 1e5 + 5;
        vector<int> seive(n, true);
        seive[0] = seive[1] = false;

        // Sieve of Eratosthenes
        for(int i = 2; i * i < n; i++){
            if(seive[i]){
                for(int j = i * i; j < n; j += i){
                    seive[j] = false;
                }
            }
        }

        // Replace each node's value with the nearest prime
        Node* temp = head;
        while(temp){
            temp->val = nearestPrime(temp->val, seive);
            temp = temp->next;
        }

        return head;
    }
};
