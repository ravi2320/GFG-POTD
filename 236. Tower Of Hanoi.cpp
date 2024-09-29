/*
Tower Of Hanoi
Difficulty: MediumAccuracy: 35.23%Submissions: 151K+Points: 4
The tower of Hanoi is a famous puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of discs n. Initially, these discs are in the rod 1. You need to print all the steps of discs movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.

You only need to complete the function toh() that takes following parameters: n (number of discs), from (The rod number from which we move the disc), to (The rod number to which we move the disc), aux (The rod that is used as an auxiliary rod) and prints the required moves inside function body (See the example for the format of the output) as well as return the count of total moves made.

Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered n. Also, all the discs have different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about the puzzle.

Examples:

Input: n = 2
Output:
move disk 1 from rod 1 to rod 2
move disk 2 from rod 1 to rod 3
move disk 1 from rod 2 to rod 3
3
Explanation: For N=2 , steps will be as follows in the example and total 3 steps will be taken.
Input: n = 3
Output:
move disk 1 from rod 1 to rod 3
move disk 2 from rod 1 to rod 2
move disk 1 from rod 3 to rod 2
move disk 3 from rod 1 to rod 3
move disk 1 from rod 2 to rod 1
move disk 2 from rod 2 to rod 3
move disk 1 from rod 1 to rod 3
7
Explanation: For N=3 , steps will be as follows in the example and total 7 steps will be taken.
Expected Time Complexity: O(2n).
Expected Auxiliary Space: O(n).

Constraints:
0 <= n <= 16
*/

/*
 * Approach:
 * - The problem is solved recursively using the divide-and-conquer approach.
 * - The idea is to move `n-1` disks from the source rod to the auxiliary rod using the destination rod, 
 *   then move the nth disk directly to the destination, and finally move the `n-1` disks from the auxiliary
 *   rod to the destination rod using the source rod.
 * - The recursive nature of this problem makes it an optimal solution for the Tower of Hanoi.
 *
 * Time Complexity:
 * - O(2^n), where `n` is the number of disks. This is because for each disk, we perform two recursive calls 
 *   and a constant amount of work (moving one disk).
 *
 * Space Complexity:
 * - O(n), which accounts for the recursion depth (the function call stack).
 *   In the worst case, the recursion will reach a depth of `n`.
 */

class Solution {
public:
    // Function to solve Tower of Hanoi
    // n    : Number of disks
    // from : The source rod (numbered 1, 2, or 3)
    // to   : The destination rod (numbered 1, 2, or 3)
    // aux  : The auxiliary rod (numbered 1, 2, or 3)
    long long toh(int n, int from, int to, int aux) {
        // Base case: When there is only one disk, move it directly from 'from' to 'to'
        if (n == 1) {
            // Output the move
            cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
            return 1;  // One move made
        }

        // Recursive case:
        // 1. Move the top (n-1) disks from 'from' rod to 'aux' rod using 'to' as auxiliary
        int count = toh(n - 1, from, aux, to);

        // 2. Move the nth disk directly from 'from' rod to 'to' rod
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        count++;  // One more move

        // 3. Move the (n-1) disks from 'aux' rod to 'to' rod using 'from' as auxiliary
        count += toh(n - 1, aux, to, from);

        // Return the total number of moves
        return count;
    }
};
