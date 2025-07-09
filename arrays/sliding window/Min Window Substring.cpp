https://leetcode.com/problems/minimum-window-substring/description/
LEETCODE-76

  -------------------------------------------
              SLIDING WINDOW
  --------------------------------------------
class Solution {
public:
    string minWindow(string s, string t) {
        // Edge case: if t is longer than s, no possible window
        if (t.size() > s.size()) return "";

        // Step 1: Build frequency map for characters in t
        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        // 'have' counts matched characters in the window
        int have = 0;
        int needCount = t.size(); // total characters (including duplicates) needed

        int l = 0;         // left pointer
        int r = 0;         // right pointer
        int minLen = INT_MAX; // track minimum window length
        int start = 0;     // starting index of min window

        unordered_map<char, int> window; // current window frequencies

        // Step 2: Expand the window with right pointer
        while (r < s.size()) {
            char c = s[r];
            window[c]++;

            // If current character is needed and its count in window <= needed
            if (need.count(c) && window[c] <= need[c]) {
                have++;
            }

            // Step 3: Try to shrink the window from the left
            while (have == needCount) {
                // Update minimum window if current window is smaller
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Pop the leftmost character
                window[s[l]]--;

                // If it's a needed char and we now have less than needed, reduce 'have'
                if (need.count(s[l]) && window[s[l]] < need[s[l]]) {
                    have--;
                }

                l++; // Move left pointer to shrink window
            }

            r++; // Expand window
        }

        // Step 4: Return result
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
TC = O(s.length + t.length)
S.C=O(1)
