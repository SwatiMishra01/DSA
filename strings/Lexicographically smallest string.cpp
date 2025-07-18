https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/
LEETCODE-3216
  class Solution {
public:
    string getSmallestString(string s) {
        int n = s.size();

        // Loop through the string from 0 to n-2 (checking pairs)
        for(int i = 0; i < n - 1; i++) {

            // Convert character digits to integers
            int a = s[i] - '0';
            int b = s[i + 1] - '0';

            // Check if both digits have same parity (both odd or even)
            // and if left digit > right digit
            if(a % 2 == b % 2 && a > b) {

                // Perform the swap
                swap(s[i], s[i + 1]);

                // Only one swap allowed, so break
                break;
            }
        }

        // Return the modified string
        return s;
    }
};
