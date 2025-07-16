---------------------------
  NEXT PERMUTATION
----------------------------
  class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size() - 2;

        // 1. Find first decreasing element
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }

        if (i < 0) return -1;

        // 2. Find element just greater than s[i]
        int j = s.size() - 1;
        while (j >= 0 && s[j] <= s[i]) {
            j--;
        }

        swap(s[i], s[j]);

        // 3. Reverse suffix
        reverse(s.begin() + i + 1, s.end());

        long long res = stoll(s);
        return (res > INT_MAX) ? -1 : res;
    }
};
T.C=O(1)
T.C=O(1)
