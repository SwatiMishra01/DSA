https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
LEETCODE-28
----------------------------
SLIDING WINDOW
---------------------------
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        for (int i = 0; i <= m - n; ++i) {
            if (haystack.substr(i, n) == needle)
                return i;
        }
        return -1;
    }
};

----------------------------------------------------------------------------------------------------------------------------------------------------------------
  -------------------------
   BETTER BRUTE FORCE
  ------------------------
  class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0 , j = 0;
        int n = needle.size();
        int m = haystack.size();
        
        if(n > m) return -1;

        for(int i=0;i<m;i++)
        {
            int j, k = i;
            for(j=0;j<n && k<m;j++,k++)
            {
                if(haystack[k] != needle[j]) break;
            }
            if(j == n) return i;
        }
        return -1;
    }
};

------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------
      KMP ALGO
  -----------------------------
