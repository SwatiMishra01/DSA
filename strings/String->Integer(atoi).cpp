https://leetcode.com/problems/string-to-integer-atoi/description/
LEETCODE-8

  class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // 2. Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Convert digits and handle overflow
        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (sign * result <= INT_MIN) return INT_MIN;
            if (sign * result >= INT_MAX) return INT_MAX;
            i++;
        }

        return sign * result;
    }
};
T.C=O(N)
S.C=O(1)
