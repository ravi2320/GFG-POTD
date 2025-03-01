/*
Decode the string
Difficulty: MediumAccuracy: 44.28%Submissions: 52K+Points: 4Average Time: 10m
Given an encoded string s, the task is to decode it. The encoding rule is :

k[encodedString], where the encodedString inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer, and encodedString contains only lowercase english alphabets.
Note: The test cases are generated so that the length of the output string will never exceed 105 .

Examples:

Input: s = "1[b]"
Output: "b"
Explanation: "b" is present only one time.
Input: s = "3[b2[ca]]"
Output: "bcacabcacabcaca"
Explanation:
1. Inner substring “2[ca]” breakdown into “caca”.
2. Now, new string becomes “3[bcaca]”
3. Similarly “3[bcaca]” becomes “bcacabcacabcaca ” which is final result.
Constraints:
1 ≤ |s| ≤ 105 
1 <= k <= 100
*/

/**
 * Approach:
 * 1️⃣ **Use a stack** to process characters one by one.
 * 2️⃣ **Push characters until `]` is found**:
 *    - If `]` is found, start **extracting** the substring inside `[ ]`.
 * 3️⃣ **Extract the number before `[`**:
 *    - Keep popping digits and form the number `k`.
 * 4️⃣ **Repeat the extracted string `k` times** and push it back into the stack.
 * 5️⃣ **Finally, reverse the stack to reconstruct the decoded string.**
 *
 * 🔹 **Time Complexity**: O(N) → Each character is processed once.
 * 🔹 **Space Complexity**: O(N) → Stack stores characters.
 */

class Solution {
public:
    string decodedString(string &s) {
        stack<char> st;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (s[i] != ']') {
                st.push(s[i]);  // Push characters other than ']'
            } else {
                // Step 1: Extract the encoded string inside `[...]`
                string word = "";
                while (!st.empty() && st.top() != '[') {
                    word.push_back(st.top());
                    st.pop();
                }
                st.pop();  // Remove '['

                reverse(word.begin(), word.end());  // Reverse to restore order
                
                // Step 2: Extract the number (k)
                string numStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numStr.push_back(st.top());
                    st.pop();
                }
                reverse(numStr.begin(), numStr.end());  // Reverse to get correct number

                int num = stoi(numStr);  // Convert string to integer
                
                // Step 3: Repeat the decoded string `k` times
                string repeated = "";
                while (num--) {
                    repeated.append(word);
                }

                // Step 4: Push repeated string back to stack
                for (char &ch : repeated) {
                    st.push(ch);
                }
            }
        }

        // Step 5: Construct final result from stack
        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());  // Reverse to get correct order
        
        return res;
    }
};